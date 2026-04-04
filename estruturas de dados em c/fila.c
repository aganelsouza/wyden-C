#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100

// ========== FILA - VERSÃO COM ARRAY (CIRCULAR) ==========
typedef struct
{
  int dados[TAM_MAX];
  int inicio;  // Índice do início da fila
  int fim;     // Índice do fim da fila
  int tamanho; // Quantidade de elementos
} fila_array;

// Criar fila
fila_array *criar_fila_array()
{
  fila_array *f = (fila_array *)malloc(sizeof(fila_array));
  f->inicio = 0;
  f->fim = -1;
  f->tamanho = 0;
  return f;
}

// Verificar se está vazia
int fila_array_vazia(fila_array *f)
{
  return f->tamanho == 0;
}

// Verificar se está cheia
int fila_array_cheia(fila_array *f)
{
  return f->tamanho == TAM_MAX;
}

// ENQUEUE (adicionar no final)
void enqueue_array(fila_array *f, int valor)
{
  if (fila_array_cheia(f))
  {
    printf("Erro: Fila cheia!\n");
    return;
  }

  f->fim = (f->fim + 1) % TAM_MAX; // Circular
  f->dados[f->fim] = valor;
  f->tamanho++;
  printf("Enqueue: %d adicionado\n", valor);
}

// DEQUEUE (remover do início)
int dequeue_array(fila_array *f)
{
  if (fila_array_vazia(f))
  {
    printf("Erro: Fila vazia!\n");
    return -1;
  }

  int valor = f->dados[f->inicio];
  f->inicio = (f->inicio + 1) % TAM_MAX; // Circular
  f->tamanho--;
  printf("Dequeue: %d removido\n", valor);
  return valor;
}

// PEEK (ver primeiro elemento sem remover)
int peek_array(fila_array *f)
{
  if (fila_array_vazia(f))
  {
    printf("Fila vazia!\n");
    return -1;
  }
  return f->dados[f->inicio];
}

// Exibir fila
void exibir_fila_array(fila_array *f)
{
  if (fila_array_vazia(f))
  {
    printf("Fila vazia!\n");
    return;
  }

  printf("Fila (início->fim): ");
  int idx = f->inicio;
  for (int i = 0; i < f->tamanho; i++)
  {
    printf("%d ", f->dados[idx]);
    idx = (idx + 1) % TAM_MAX;
  }
  printf("(tamanho: %d)\n", f->tamanho);
}

// ========== FILA - VERSÃO COM LISTA ENCADEADA ==========
typedef struct no_fila
{
  int valor;
  struct no_fila *proximo;
} no_fila;

typedef struct
{
  no_fila *inicio;
  no_fila *fim;
  int tamanho;
} fila_encad;

// Criar fila encadeada
fila_encad *criar_fila_encad()
{
  fila_encad *f = (fila_encad *)malloc(sizeof(fila_encad));
  f->inicio = NULL;
  f->fim = NULL;
  f->tamanho = 0;
  return f;
}

int fila_encad_vazia(fila_encad *f)
{
  return f->tamanho == 0;
}

// ENQUEUE (adicionar no final)
void enqueue_encad(fila_encad *f, int valor)
{
  no_fila *novo = (no_fila *)malloc(sizeof(no_fila));
  novo->valor = valor;
  novo->proximo = NULL;

  if (fila_encad_vazia(f))
  {
    f->inicio = novo;
  }
  else
  {
    f->fim->proximo = novo;
  }
  f->fim = novo;
  f->tamanho++;
  printf("Enqueue: %d adicionado\n", valor);
}

// DEQUEUE (remover do início)
int dequeue_encad(fila_encad *f)
{
  if (fila_encad_vazia(f))
  {
    printf("Erro: Fila vazia!\n");
    return -1;
  }

  no_fila *temp = f->inicio;
  int valor = temp->valor;
  f->inicio = f->inicio->proximo;
  f->tamanho--;

  if (fila_encad_vazia(f))
  {
    f->fim = NULL;
  }

  free(temp);
  printf("Dequeue: %d removido\n", valor);
  return valor;
}

// PEEK
int peek_encad(fila_encad *f)
{
  if (fila_encad_vazia(f))
  {
    printf("Fila vazia!\n");
    return -1;
  }
  return f->inicio->valor;
}

// Exibir fila encadeada
void exibir_fila_encad(fila_encad *f)
{
  if (fila_encad_vazia(f))
  {
    printf("Fila vazia!\n");
    return;
  }

  printf("Fila (encadeada): ");
  no_fila *atual = f->inicio;
  while (atual != NULL)
  {
    printf("%d -> ", atual->valor);
    atual = atual->proximo;
  }
  printf("NULL (tamanho: %d)\n", f->tamanho);
}

// Liberar fila encadeada
void liberar_fila_encad(fila_encad *f)
{
  no_fila *atual = f->inicio;
  while (atual != NULL)
  {
    no_fila *temp = atual;
    atual = atual->proximo;
    free(temp);
  }
  free(f);
}

// ========== SIMULAÇÃO: FILA DE CAIXA DE SUPERMERCADO ==========
typedef struct
{
  int id_cliente;
  int tempo_atendimento;
} cliente_fila;

void simular_fila_caixa()
{
  printf("\n========== SIMULAÇÃO: CAIXA DE SUPERMERCADO ==========\n\n");

  fila_encad *fila = criar_fila_encad();

  // Clientes chegando
  printf("Clientes chegando...\n");
  for (int i = 1; i <= 5; i++)
  {
    cliente_fila *c = (cliente_fila *)malloc(sizeof(cliente_fila));
    c->id_cliente = i * 100;
    c->tempo_atendimento = i * 2;

    // Simplificado: armazenar apenas o ID
    enqueue_encad(fila, c->id_cliente);
    free(c);
  }

  exibir_fila_encad(fila);

  // Atendimento
  printf("\nAtendendo clientes...\n");
  while (!fila_encad_vazia(fila))
  {
    int cliente = dequeue_encad(fila);
    printf("  -> Cliente %d atendido!\n", cliente);
  }

  liberar_fila_encad(fila);
}

// ========== PROGRAMA PRINCIPAL ==========
int main(int argc, char const *argv[])
{
  printf("========== FILA COM ARRAY (CIRCULAR) ==========\n\n");

  fila_array *f_array = criar_fila_array();

  enqueue_array(f_array, 10);
  enqueue_array(f_array, 20);
  enqueue_array(f_array, 30);
  enqueue_array(f_array, 40);

  exibir_fila_array(f_array);
  printf("Primeiro: %d\n\n", peek_array(f_array));

  dequeue_array(f_array);
  dequeue_array(f_array);
  exibir_fila_array(f_array);

  enqueue_array(f_array, 50);
  enqueue_array(f_array, 60);
  exibir_fila_array(f_array);

  free(f_array);

  printf("\n========== FILA COM LISTA ENCADEADA ==========\n\n");

  fila_encad *f_encad = criar_fila_encad();

  enqueue_encad(f_encad, 100);
  enqueue_encad(f_encad, 200);
  enqueue_encad(f_encad, 300);

  exibir_fila_encad(f_encad);
  printf("Primeiro: %d\n\n", peek_encad(f_encad));

  dequeue_encad(f_encad);
  exibir_fila_encad(f_encad);

  simular_fila_caixa();

  printf("\nPrograma finalizado!\n");
  return 0;
}
