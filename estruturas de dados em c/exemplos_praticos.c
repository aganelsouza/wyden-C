#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========== EXEMPLO 1: SIMULADOR DE ESTACIONAMENTO ==========

typedef struct
{
  int id;
  char placa[20];
  int hora_entrada;
  int hora_saida;
} veiculo;

typedef struct no_veiculo
{
  veiculo *dados;
  struct no_veiculo *proximo;
} no_veiculo;

// Historico como lista encadeada
typedef struct
{
  no_veiculo *cabeca;
} historico_estacionamento;

// Fila de entrada
typedef struct no_fila_veiculo
{
  veiculo *dados;
  struct no_fila_veiculo *proximo;
} no_fila_veiculo;

typedef struct
{
  no_fila_veiculo *inicio;
  no_fila_veiculo *fim;
} fila_entrada;

// Pilha de saída
typedef struct no_pilha_saida
{
  veiculo *dados;
  struct no_pilha_saida *proximo;
} no_pilha_saida;

typedef struct
{
  no_pilha_saida *topo;
} pilha_saida;

// Estacionamento
typedef struct
{
  veiculo **vagas; // Array
  int capacidade;
  int ocupadas;
  historico_estacionamento *historico;
  int proximo_id;
} estacionamento;

// Funções auxiliares
estacionamento *criar_estacionamento(int capacidade)
{
  estacionamento *e = (estacionamento *)malloc(sizeof(estacionamento));
  e->vagas = (veiculo **)malloc(sizeof(veiculo *) * capacidade);
  for (int i = 0; i < capacidade; i++)
  {
    e->vagas[i] = NULL;
  }
  e->capacidade = capacidade;
  e->ocupadas = 0;
  e->historico = (historico_estacionamento *)malloc(sizeof(historico_estacionamento));
  e->historico->cabeca = NULL;
  e->proximo_id = 1;
  return e;
}

int vagas_disponiveis(estacionamento *e)
{
  return e->capacidade - e->ocupadas;
}

int estacionar(estacionamento *e, const char *placa, int hora)
{
  if (vagas_disponiveis(e) == 0)
  {
    printf("Estacionamento cheio!\n");
    return -1;
  }

  // Encontrar vaga livre
  int vaga = -1;
  for (int i = 0; i < e->capacidade; i++)
  {
    if (e->vagas[i] == NULL)
    {
      vaga = i;
      break;
    }
  }

  // Criar veículo
  veiculo *v = (veiculo *)malloc(sizeof(veiculo));
  v->id = e->proximo_id++;
  strcpy(v->placa, placa);
  v->hora_entrada = hora;
  v->hora_saida = 0;

  e->vagas[vaga] = v;
  e->ocupadas++;

  printf("Carro %s estacionado na vaga %d (ID: %d, Hora: %d)\n", placa, vaga, v->id, hora);
  return vaga;
}

veiculo *sair_estacionamento(estacionamento *e, int vaga, int hora)
{
  if (vaga < 0 || vaga >= e->capacidade || e->vagas[vaga] == NULL)
  {
    printf("Vaga inválida!\n");
    return NULL;
  }

  veiculo *v = e->vagas[vaga];
  v->hora_saida = hora;
  e->vagas[vaga] = NULL;
  e->ocupadas--;

  printf("Carro %s saiu da vaga %d (Hora: %d, Tempo: %d horas)\n",
         v->placa, vaga, hora, hora - v->hora_entrada);

  // Adicionar ao histórico
  no_veiculo *novo = (no_veiculo *)malloc(sizeof(no_veiculo));
  novo->dados = v;
  novo->proximo = e->historico->cabeca;
  e->historico->cabeca = novo;

  return v;
}

void exibir_vagas(estacionamento *e)
{
  printf("\n=== STATUS DO ESTACIONAMENTO ===\n");
  printf("Vagas ocupadas: %d/%d\n", e->ocupadas, e->capacidade);
  printf("Carros estacionados:\n");
  for (int i = 0; i < e->capacidade; i++)
  {
    if (e->vagas[i] != NULL)
    {
      printf("  Vaga %d: %s (ID: %d, Entrada: %d)\n",
             i, e->vagas[i]->placa, e->vagas[i]->id, e->vagas[i]->hora_entrada);
    }
    else
    {
      printf("  Vaga %d: [LIVRE]\n", i);
    }
  }
}

void exibir_historico(estacionamento *e)
{
  printf("\n=== HISTÓRICO DE SAÍDAS ===\n");
  no_veiculo *atual = e->historico->cabeca;
  int contador = 1;
  while (atual != NULL)
  {
    int tempo = atual->dados->hora_saida - atual->dados->hora_entrada;
    printf("%d. %s - Entrada: %d, Saída: %d, Tempo: %d horas\n",
           contador, atual->dados->placa, atual->dados->hora_entrada,
           atual->dados->hora_saida, tempo);
    atual = atual->proximo;
    contador++;
  }
}

void liberar_estacionamento(estacionamento *e)
{
  // Liberar vagas
  for (int i = 0; i < e->capacidade; i++)
  {
    if (e->vagas[i] != NULL)
    {
      free(e->vagas[i]);
    }
  }
  free(e->vagas);

  // Liberar histórico
  no_veiculo *atual = e->historico->cabeca;
  while (atual != NULL)
  {
    no_veiculo *temp = atual;
    atual = atual->proximo;
    free(temp->dados);
    free(temp);
  }
  free(e->historico);

  free(e);
}

// ========== EXEMPLO 2: VALIDADOR COM PILHA ==========

typedef struct
{
  char dados[1000];
  int topo;
} pilha_char;

pilha_char *criar_pilha_char()
{
  pilha_char *p = (pilha_char *)malloc(sizeof(pilha_char));
  p->topo = -1;
  return p;
}

void push_char(pilha_char *p, char c)
{
  if (p->topo < 999)
  {
    p->dados[++p->topo] = c;
  }
}

char pop_char(pilha_char *p)
{
  if (p->topo >= 0)
  {
    return p->dados[p->topo--];
  }
  return '\0';
}

int validar_balanceamento(const char *expressao)
{
  pilha_char *p = criar_pilha_char();

  for (int i = 0; expressao[i] != '\0'; i++)
  {
    char c = expressao[i];

    if (c == '(' || c == '[' || c == '{')
    {
      push_char(p, c);
    }
    else if (c == ')' || c == ']' || c == '}')
    {
      if (p->topo < 0)
      {
        free(p);
        return 0;
      }

      char abertura = pop_char(p);

      if ((c == ')' && abertura != '(') ||
          (c == ']' && abertura != '[') ||
          (c == '}' && abertura != '{'))
      {
        free(p);
        return 0;
      }
    }
  }

  int resultado = (p->topo < 0) ? 1 : 0;
  free(p);
  return resultado;
}

// ========== PROGRAMA PRINCIPAL ==========

int main(int argc, char const *argv[])
{
  printf("========== SIMULADOR DE ESTACIONAMENTO ==========\n\n");

  estacionamento *e = criar_estacionamento(5);

  // Simular entradas e saídas
  estacionar(e, "ABC-1234", 8);
  estacionar(e, "XYZ-9876", 9);
  estacionar(e, "DEF-5555", 10);

  exibir_vagas(e);

  printf("\n--- Alguns carros saem ---\n");
  sair_estacionamento(e, 0, 12);
  sair_estacionamento(e, 1, 13);

  exibir_vagas(e);

  printf("\n--- Novos carros chegam ---\n");
  estacionar(e, "GHI-1111", 14);
  estacionar(e, "JKL-2222", 14);

  exibir_vagas(e);
  exibir_historico(e);

  liberar_estacionamento(e);

  printf("\n\n========== VALIDADOR DE EXPRESSÕES ==========\n\n");

  const char *expressoes[] = {
      "((a + b) * (c - d))",
      "((a + b) * c - d))",
      "[(a + b) * {c}]",
      "[(a + b) * c}]",
      "{[(1 + 2) * 3] / 4}"};

  int n_expressoes = sizeof(expressoes) / sizeof(expressoes[0]);

  for (int i = 0; i < n_expressoes; i++)
  {
    int valida = validar_balanceamento(expressoes[i]);
    printf("%-30s -> %s\n", expressoes[i],
           valida ? "✓ VÁLIDA" : "✗ INVÁLIDA");
  }

  printf("\nPrograma finalizado!\n");
  return 0;
}
