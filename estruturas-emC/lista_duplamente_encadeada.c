#include <stdio.h>
#include <stdlib.h>

// ========== LISTA DUPLAMENTE ENCADEADA ==========
// Cada nó tem ponteiro para ANTERIOR e PRÓXIMO
typedef struct no_duplo
{
  int valor;
  struct no_duplo *proximo;
  struct no_duplo *anterior;
} no_duplo;

// Função para criar um novo nó
no_duplo *criar_no_duplo(int valor)
{
  no_duplo *novo = (no_duplo *)malloc(sizeof(no_duplo));
  if (novo == NULL)
  {
    printf("Erro: Memória insuficiente!\n");
    return NULL;
  }
  novo->valor = valor;
  novo->proximo = NULL;
  novo->anterior = NULL;
  return novo;
}

// Inserir no INÍCIO
no_duplo *inserir_duplo_inicio(no_duplo *cabeca, int valor)
{
  no_duplo *novo = criar_no_duplo(valor);
  if (novo == NULL)
    return cabeca;

  if (cabeca != NULL)
  {
    novo->proximo = cabeca;
    cabeca->anterior = novo;
  }
  return novo;
}

// Inserir no FINAL
no_duplo *inserir_duplo_fim(no_duplo *cabeca, int valor)
{
  no_duplo *novo = criar_no_duplo(valor);
  if (novo == NULL)
    return cabeca;

  if (cabeca == NULL)
  {
    return novo;
  }

  // Procura o último nó
  no_duplo *atual = cabeca;
  while (atual->proximo != NULL)
  {
    atual = atual->proximo;
  }

  atual->proximo = novo;
  novo->anterior = atual;
  return cabeca;
}

// Exibir para FRENTE (início -> fim)
void exibir_duplo_frente(no_duplo *cabeca)
{
  if (cabeca == NULL)
  {
    printf("Lista vazia!\n");
    return;
  }

  printf("Frente (início->fim): ");
  no_duplo *atual = cabeca;
  while (atual != NULL)
  {
    printf("%d <-> ", atual->valor);
    atual = atual->proximo;
  }
  printf("NULL\n");
}

// Exibir para TRÁS (fim -> início)
void exibir_duplo_tras(no_duplo *cauda)
{
  if (cauda == NULL)
  {
    printf("Lista vazia!\n");
    return;
  }

  printf("Trás (fim->início): ");
  no_duplo *atual = cauda;
  while (atual != NULL)
  {
    printf("%d <-> ", atual->valor);
    atual = atual->anterior;
  }
  printf("NULL\n");
}

// Encontrar o último nó (cauda)
no_duplo *encontrar_cauda(no_duplo *cabeca)
{
  if (cabeca == NULL)
    return NULL;

  no_duplo *atual = cabeca;
  while (atual->proximo != NULL)
  {
    atual = atual->proximo;
  }
  return atual;
}

// Remover um elemento
no_duplo *remover_duplo(no_duplo *cabeca, int valor)
{
  if (cabeca == NULL)
    return NULL;

  // Se está no início
  if (cabeca->valor == valor)
  {
    no_duplo *temp = cabeca;
    cabeca = cabeca->proximo;
    if (cabeca != NULL)
    {
      cabeca->anterior = NULL;
    }
    free(temp);
    printf("Elemento %d removido do início!\n", valor);
    return cabeca;
  }

  // Procura na lista
  no_duplo *atual = cabeca;
  while (atual != NULL)
  {
    if (atual->valor == valor)
    {
      if (atual->anterior != NULL)
      {
        atual->anterior->proximo = atual->proximo;
      }
      if (atual->proximo != NULL)
      {
        atual->proximo->anterior = atual->anterior;
      }
      free(atual);
      printf("Elemento %d removido!\n", valor);
      return cabeca;
    }
    atual = atual->proximo;
  }

  printf("Elemento %d não encontrado!\n", valor);
  return cabeca;
}

// Liberar memória
void liberar_duplo(no_duplo *cabeca)
{
  no_duplo *atual = cabeca;
  while (atual != NULL)
  {
    no_duplo *temp = atual;
    atual = atual->proximo;
    free(temp);
  }
}

// ========== PROGRAMA PRINCIPAL ==========
int main(int argc, char const *argv[])
{
  printf("===== LISTA DUPLAMENTE ENCADEADA =====\n\n");

  no_duplo *lista = NULL;

  // Inserindo elementos
  lista = inserir_duplo_fim(lista, 10);
  lista = inserir_duplo_fim(lista, 20);
  lista = inserir_duplo_fim(lista, 30);
  lista = inserir_duplo_inicio(lista, 5);

  exibir_duplo_frente(lista);
  no_duplo *cauda = encontrar_cauda(lista);
  exibir_duplo_tras(cauda);

  printf("\nRemovendo 20...\n");
  lista = remover_duplo(lista, 20);

  exibir_duplo_frente(lista);
  cauda = encontrar_cauda(lista);
  exibir_duplo_tras(cauda);

  liberar_duplo(lista);

  printf("\nPrograma finalizado!\n");
  return 0;
}
