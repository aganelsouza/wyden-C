#include <stdio.h>
#include <stdlib.h>

// ========== LISTA DUPLAMENTE ENCADEADA CIRCULAR ==========
// Cada nó aponta para anterior e próximo, e o último aponta para o primeiro
typedef struct no_duplo_circ
{
  int valor;
  struct no_duplo_circ *proximo;
  struct no_duplo_circ *anterior;
} no_duplo_circ;

// Criar nó
no_duplo_circ *criar_no_duplo_circ(int valor)
{
  no_duplo_circ *novo = (no_duplo_circ *)malloc(sizeof(no_duplo_circ));
  if (novo == NULL)
  {
    printf("Erro: Memória insuficiente!\n");
    return NULL;
  }
  novo->valor = valor;
  novo->proximo = novo;  // Aponta para si mesmo
  novo->anterior = novo; // Aponta para si mesmo
  return novo;
}

// Inserir no INÍCIO (retorna nova cabeça)
no_duplo_circ *inserir_duplo_circ_inicio(no_duplo_circ *cabeca, int valor)
{
  no_duplo_circ *novo = criar_no_duplo_circ(valor);
  if (novo == NULL)
    return cabeca;

  if (cabeca == NULL)
  {
    return novo;
  }

  // Atualiza ligações circulares
  novo->proximo = cabeca;
  novo->anterior = cabeca->anterior;
  cabeca->anterior->proximo = novo;
  cabeca->anterior = novo;

  return novo; // Nova cabeça
}

// Inserir no FINAL (passa cauda por último)
no_duplo_circ *inserir_duplo_circ_fim(no_duplo_circ *cabeca, int valor)
{
  no_duplo_circ *novo = criar_no_duplo_circ(valor);
  if (novo == NULL)
    return cabeca;

  if (cabeca == NULL)
  {
    return novo;
  }

  // A cauda é a anterior da cabeça
  no_duplo_circ *cauda = cabeca->anterior;

  novo->proximo = cabeca;
  novo->anterior = cauda;
  cauda->proximo = novo;
  cabeca->anterior = novo;

  return cabeca; // Cabeça não muda
}

// Exibir para FRENTE (com limite para evitar loop infinito)
void exibir_duplo_circ_frente(no_duplo_circ *cabeca)
{
  if (cabeca == NULL)
  {
    printf("Lista vazia!\n");
    return;
  }

  printf("Frente (início->fim->início): ");
  no_duplo_circ *atual = cabeca;
  int contador = 0;
  int limite = 100;

  do
  {
    printf("%d <-> ", atual->valor);
    atual = atual->proximo;
    contador++;
  } while (atual != cabeca && contador < limite);

  printf("(volta ao início)\n");
}

// Exibir para TRÁS
void exibir_duplo_circ_tras(no_duplo_circ *cabeca)
{
  if (cabeca == NULL)
  {
    printf("Lista vazia!\n");
    return;
  }

  printf("Trás (fim->início->fim): ");
  no_duplo_circ *atual = cabeca->anterior; // Começa da cauda
  int contador = 0;
  int limite = 100;

  do
  {
    printf("%d <-> ", atual->valor);
    atual = atual->anterior;
    contador++;
  } while (atual != cabeca->anterior && contador < limite);

  printf("(volta ao fim)\n");
}

// Encontrar um elemento
no_duplo_circ *buscar_duplo_circ(no_duplo_circ *cabeca, int valor)
{
  if (cabeca == NULL)
    return NULL;

  no_duplo_circ *atual = cabeca;
  do
  {
    if (atual->valor == valor)
    {
      return atual;
    }
    atual = atual->proximo;
  } while (atual != cabeca);

  return NULL;
}

// Remover um elemento
no_duplo_circ *remover_duplo_circ(no_duplo_circ *cabeca, int valor)
{
  if (cabeca == NULL)
    return NULL;

  no_duplo_circ *removivel = buscar_duplo_circ(cabeca, valor);

  if (removivel == NULL)
  {
    printf("Elemento %d não encontrado!\n", valor);
    return cabeca;
  }

  // Se é o único elemento
  if (removivel->proximo == removivel)
  {
    free(removivel);
    printf("Elemento %d removido (lista ficou vazia)!\n", valor);
    return NULL;
  }

  // Se é a cabeça
  if (removivel == cabeca)
  {
    no_duplo_circ *nova_cabeca = cabeca->proximo;
    cabeca->anterior->proximo = nova_cabeca;
    nova_cabeca->anterior = cabeca->anterior;
    free(cabeca);
    printf("Elemento %d removido do início!\n", valor);
    return nova_cabeca;
  }

  // Elemento no meio
  removivel->anterior->proximo = removivel->proximo;
  removivel->proximo->anterior = removivel->anterior;
  free(removivel);
  printf("Elemento %d removido!\n", valor);
  return cabeca;
}

// Obter quantidade de elementos
int contar_duplo_circ(no_duplo_circ *cabeca)
{
  if (cabeca == NULL)
    return 0;

  int contador = 1;
  no_duplo_circ *atual = cabeca->proximo;

  while (atual != cabeca)
  {
    contador++;
    atual = atual->proximo;
  }

  return contador;
}

// Liberar memória
void liberar_duplo_circ(no_duplo_circ *cabeca)
{
  if (cabeca == NULL)
    return;

  no_duplo_circ *atual = cabeca->proximo;

  while (atual != cabeca)
  {
    no_duplo_circ *temp = atual;
    atual = atual->proximo;
    free(temp);
  }

  free(cabeca);
}

// ========== PROGRAMA PRINCIPAL ==========
int main(int argc, char const *argv[])
{
  printf("===== LISTA DUPLAMENTE ENCADEADA CIRCULAR =====\n\n");

  no_duplo_circ *lista = NULL;

  // Inserindo elementos
  lista = inserir_duplo_circ_fim(lista, 10);
  lista = inserir_duplo_circ_fim(lista, 20);
  lista = inserir_duplo_circ_fim(lista, 30);
  lista = inserir_duplo_circ_inicio(lista, 5);

  printf("Quantidade de elementos: %d\n\n", contar_duplo_circ(lista));

  exibir_duplo_circ_frente(lista);
  exibir_duplo_circ_tras(lista);

  printf("\nBuscando elemento 20...\n");
  no_duplo_circ *encontrado = buscar_duplo_circ(lista, 20);
  if (encontrado != NULL)
  {
    printf("Elemento %d encontrado! (Anterior: %d, Próximo: %d)\n\n",
           encontrado->valor, encontrado->anterior->valor, encontrado->proximo->valor);
  }

  printf("Removendo 20...\n");
  lista = remover_duplo_circ(lista, 20);

  printf("Quantidade de elementos: %d\n\n", contar_duplo_circ(lista));

  exibir_duplo_circ_frente(lista);
  exibir_duplo_circ_tras(lista);

  printf("\nRemovendo 10...\n");
  lista = remover_duplo_circ(lista, 10);

  exibir_duplo_circ_frente(lista);

  liberar_duplo_circ(lista);

  printf("Programa finalizado!\n");
  return 0;
}
