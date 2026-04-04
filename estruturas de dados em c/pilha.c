#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100

// ========== PILHA - VERSÃO COM ARRAY ==========
typedef struct
{
  int dados[TAM_MAX];
  int topo; // Índice do topo da pilha
} pilha_array;

// Criar pilha
pilha_array *criar_pilha_array()
{
  pilha_array *p = (pilha_array *)malloc(sizeof(pilha_array));
  p->topo = -1; // -1 significa pilha vazia
  return p;
}

// Verificar se está vazia
int pilha_array_vazia(pilha_array *p)
{
  return p->topo == -1;
}

// Verificar se está cheia
int pilha_array_cheia(pilha_array *p)
{
  return p->topo == TAM_MAX - 1;
}

// PUSH (adicionar elemento no topo)
void push_array(pilha_array *p, int valor)
{
  if (pilha_array_cheia(p))
  {
    printf("Erro: Pilha cheia!\n");
    return;
  }
  p->topo++;
  p->dados[p->topo] = valor;
  printf("Push: %d adicionado (topo em posição %d)\n", valor, p->topo);
}

// POP (remover elemento do topo)
int pop_array(pilha_array *p)
{
  if (pilha_array_vazia(p))
  {
    printf("Erro: Pilha vazia!\n");
    return -1;
  }
  int valor = p->dados[p->topo];
  printf("Pop: %d removido (topo em posição %d)\n", valor, p->topo);
  p->topo--;
  return valor;
}

// PEEK (ver elemento do topo sem remover)
int peek_array(pilha_array *p)
{
  if (pilha_array_vazia(p))
  {
    printf("Pilha vazia!\n");
    return -1;
  }
  return p->dados[p->topo];
}

// Exibir pilha
void exibir_pilha_array(pilha_array *p)
{
  if (pilha_array_vazia(p))
  {
    printf("Pilha vazia!\n");
    return;
  }

  printf("Pilha (topo para baixo): ");
  for (int i = p->topo; i >= 0; i--)
  {
    printf("%d ", p->dados[i]);
  }
  printf("(base)\n");
}

// ========== PILHA - VERSÃO COM LISTA ENCADEADA ==========
typedef struct no_pilha
{
  int valor;
  struct no_pilha *proximo;
} no_pilha;

no_pilha *criar_pilha_encadeada()
{
  return NULL; // Pilha vazia
}

int pilha_encad_vazia(no_pilha *topo)
{
  return topo == NULL;
}

void push_encad(no_pilha **topo, int valor)
{
  no_pilha *novo = (no_pilha *)malloc(sizeof(no_pilha));
  novo->valor = valor;
  novo->proximo = *topo;
  *topo = novo;
  printf("Push: %d adicionado\n", valor);
}

int pop_encad(no_pilha **topo)
{
  if (pilha_encad_vazia(*topo))
  {
    printf("Erro: Pilha vazia!\n");
    return -1;
  }
  no_pilha *temp = *topo;
  int valor = temp->valor;
  *topo = (*topo)->proximo;
  free(temp);
  printf("Pop: %d removido\n", valor);
  return valor;
}

int peek_encad(no_pilha *topo)
{
  if (pilha_encad_vazia(topo))
  {
    printf("Pilha vazia!\n");
    return -1;
  }
  return topo->valor;
}

void exibir_pilha_encad(no_pilha *topo)
{
  if (pilha_encad_vazia(topo))
  {
    printf("Pilha vazia!\n");
    return;
  }

  printf("Pilha (encadeada): ");
  no_pilha *atual = topo;
  while (atual != NULL)
  {
    printf("%d -> ", atual->valor);
    atual = atual->proximo;
  }
  printf("NULL\n");
}

void liberar_pilha_encad(no_pilha *topo)
{
  no_pilha *atual = topo;
  while (atual != NULL)
  {
    no_pilha *temp = atual;
    atual = atual->proximo;
    free(temp);
  }
}

// ========== EXEMPLO: VERIFICAR PARÊNTESES BALANCEADOS ==========
int parenteses_balanceados(const char *expressao)
{
  pilha_array *p = criar_pilha_array();

  for (int i = 0; expressao[i] != '\0'; i++)
  {
    if (expressao[i] == '(')
    {
      push_array(p, i);
    }
    else if (expressao[i] == ')')
    {
      if (pilha_array_vazia(p))
      {
        free(p);
        return 0; // Parêntese fechando sem abrir
      }
      pop_array(p);
    }
  }

  int resultado = pilha_array_vazia(p);
  free(p);
  return resultado;
}

// ========== PROGRAMA PRINCIPAL ==========
int main(int argc, char const *argv[])
{
  printf("========== PILHA COM ARRAY ==========\n\n");

  pilha_array *p_array = criar_pilha_array();

  push_array(p_array, 10);
  push_array(p_array, 20);
  push_array(p_array, 30);
  push_array(p_array, 40);

  exibir_pilha_array(p_array);
  printf("Topo: %d\n\n", peek_array(p_array));

  pop_array(p_array);
  pop_array(p_array);
  exibir_pilha_array(p_array);

  free(p_array);

  printf("\n========== PILHA COM LISTA ENCADEADA ==========\n\n");

  no_pilha *p_encad = criar_pilha_encadeada();

  push_encad(&p_encad, 100);
  push_encad(&p_encad, 200);
  push_encad(&p_encad, 300);

  exibir_pilha_encad(p_encad);
  printf("Topo: %d\n\n", peek_encad(p_encad));

  pop_encad(&p_encad);
  exibir_pilha_encad(p_encad);

  liberar_pilha_encad(p_encad);

  printf("\n========== EXEMPLO: PARÊNTESES BALANCEADOS ==========\n\n");

  const char *expr1 = "((a + b) * (c - d))";
  const char *expr2 = "((a + b) * (c - d)";
  const char *expr3 = "((a + b) * c - d))";

  printf("Expressão: %s -> %s\n", expr1,
         parenteses_balanceados(expr1) ? "Balanceada ✓" : "Desbalanceada ✗");
  printf("Expressão: %s -> %s\n", expr2,
         parenteses_balanceados(expr2) ? "Balanceada ✓" : "Desbalanceada ✗");
  printf("Expressão: %s -> %s\n", expr3,
         parenteses_balanceados(expr3) ? "Balanceada ✓" : "Desbalanceada ✗");

  printf("\nPrograma finalizado!\n");
  return 0;
}
