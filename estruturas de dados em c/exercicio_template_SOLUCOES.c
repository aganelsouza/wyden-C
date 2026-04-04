#include <stdio.h>
#include <stdlib.h>

/* ============================================================
   SOLUÇÕES DOS EXERCÍCIOS DO TEMPLATE
   ============================================================

   Só olhe DEPOIS de tentar resolver sozinho! 😉

============================================================ */

typedef struct no
{
  int valor;
  struct no *proximo;
} no;

// ========== FUNÇÕES BÁSICAS (IGUAIS AO TEMPLATE) ==========

no *criar_no(int valor)
{
  no *novo = (no *)malloc(sizeof(no));
  if (novo == NULL)
  {
    printf("Erro: Memória insuficiente!\n");
    return NULL;
  }
  novo->valor = valor;
  novo->proximo = NULL;
  return novo;
}

no *inserir_inicio(no *cabeca, int valor)
{
  no *novo = criar_no(valor);
  if (novo == NULL)
    return cabeca;

  novo->proximo = cabeca;
  return novo;
}

void exibir(no *cabeca)
{
  if (cabeca == NULL)
  {
    printf("Lista vazia!\n");
    return;
  }

  printf("Lista: ");
  no *atual = cabeca;
  while (atual != NULL)
  {
    printf("%d -> ", atual->valor);
    atual = atual->proximo;
  }
  printf("NULL\n");
}

void liberar(no *cabeca)
{
  no *atual = cabeca;
  while (atual != NULL)
  {
    no *temp = atual;
    atual = atual->proximo;
    free(temp);
  }
}

// ========== SOLUÇÃO 1: CONTAR ELEMENTOS ==========

int contar_elementos(no *cabeca)
{
  int contador = 0;
  no *atual = cabeca;

  while (atual != NULL)
  {
    contador++;
    atual = atual->proximo;
  }

  return contador;
}

// ========== SOLUÇÃO 2 (ALT): CONTAR COM RECURSÃO ==========

int contar_elementos_recursivo(no *cabeca)
{
  if (cabeca == NULL)
  {
    return 0;
  }
  return 1 + contar_elementos_recursivo(cabeca->proximo);
}

// ========== SOLUÇÃO 3: BUSCAR ELEMENTO ==========

int buscar_elemento(no *cabeca, int valor)
{
  no *atual = cabeca;

  while (atual != NULL)
  {
    if (atual->valor == valor)
    {
      return 1; // Encontrou
    }
    atual = atual->proximo;
  }

  return 0; // Não encontrou
}

// ========== SOLUÇÃO 4 (ALT): BUSCAR COM RECURSÃO ==========

int buscar_elemento_recursivo(no *cabeca, int valor)
{
  if (cabeca == NULL)
  {
    return 0; // Fim da lista, não encontrou
  }

  if (cabeca->valor == valor)
  {
    return 1; // Encontrou!
  }

  return buscar_elemento_recursivo(cabeca->proximo, valor);
}

// ========== SOLUÇÃO 5: ENCONTRAR O MAIOR ==========

int encontrar_maior(no *cabeca)
{
  if (cabeca == NULL)
  {
    printf("Erro: Lista vazia!\n");
    return -1; // Valor inválido
  }

  int maior = cabeca->valor;
  no *atual = cabeca->proximo;

  while (atual != NULL)
  {
    if (atual->valor > maior)
    {
      maior = atual->valor;
    }
    atual = atual->proximo;
  }

  return maior;
}

// ========== SOLUÇÃO 6 (ALT): MAIOR COM RECURSÃO ==========

int encontrar_maior_recursivo(no *cabeca)
{
  if (cabeca == NULL)
  {
    return -1; // Erro
  }

  if (cabeca->proximo == NULL)
  {
    return cabeca->valor; // Último nó
  }

  int maior_resto = encontrar_maior_recursivo(cabeca->proximo);

  if (cabeca->valor > maior_resto)
  {
    return cabeca->valor;
  }
  else
  {
    return maior_resto;
  }
}

// ========== SOLUÇÃO 7: INVERTER LISTA (DESAFIO!) ==========

// Versão 1: Iterativa com 3 apontadores
no *inverter_lista(no *cabeca)
{
  no *anterior = NULL;
  no *atual = cabeca;
  no *proximo = NULL;

  while (atual != NULL)
  {
    // Guardar o próximo
    proximo = atual->proximo;

    // Inverter o apontador
    atual->proximo = anterior;

    // Mover para o próximo
    anterior = atual;
    atual = proximo;
  }

  return anterior; // Nova cabeça
}

// ========== SOLUÇÃO 8 (ALT): INVERTER COM RECURSÃO ==========

no *inverter_lista_recursivo(no *cabeca)
{
  // Caso base: lista vazia ou com 1 elemento
  if (cabeca == NULL || cabeca->proximo == NULL)
  {
    return cabeca;
  }

  // Inverter o resto
  no *nova_cabeca = inverter_lista_recursivo(cabeca->proximo);

  // Fazer o próximo apontar para este
  cabeca->proximo->proximo = cabeca;

  // Este aponta para nada
  cabeca->proximo = NULL;

  return nova_cabeca;
}

// ========== PROGRAMA PRINCIPAL DE TESTE ==========

int main(int argc, char const *argv[])
{
  printf("========== SOLUÇÕES DOS EXERCÍCIOS ==========\n\n");

  // Criar lista: 1 -> 2 -> 3 -> 4 -> 5
  no *lista = NULL;
  lista = inserir_inicio(lista, 5);
  lista = inserir_inicio(lista, 4);
  lista = inserir_inicio(lista, 3);
  lista = inserir_inicio(lista, 2);
  lista = inserir_inicio(lista, 1);

  exibir(lista);

  // ========== SOLUÇÃO 1: CONTAR ==========
  printf("\n--- Solução 1: Contar Elementos ---\n");
  int quantidade = contar_elementos(lista);
  printf("Iterativa: %d elementos\n", quantidade);

  quantidade = contar_elementos_recursivo(lista);
  printf("Recursiva: %d elementos\n", quantidade);

  // ========== SOLUÇÃO 2: BUSCAR ==========
  printf("\n--- Solução 2: Buscar Elemento ---\n");
  printf("Buscar 3 (iterativa): %s\n",
         buscar_elemento(lista, 3) ? "encontrado" : "não encontrado");
  printf("Buscar 3 (recursiva): %s\n",
         buscar_elemento_recursivo(lista, 3) ? "encontrado" : "não encontrado");
  printf("Buscar 10 (iterativa): %s\n",
         buscar_elemento(lista, 10) ? "encontrado" : "não encontrado");

  // ========== SOLUÇÃO 3: MAIOR ==========
  printf("\n--- Solução 3: Encontrar Maior ---\n");
  int maior = encontrar_maior(lista);
  printf("Iterativa: %d\n", maior);

  maior = encontrar_maior_recursivo(lista);
  printf("Recursiva: %d\n", maior);

  // ========== SOLUÇÃO 4: INVERTER ==========
  printf("\n--- Solução 4: Inverter Lista ---\n");
  printf("Antes: ");
  exibir(lista);

  lista = inverter_lista(lista);

  printf("Depois (iterativa): ");
  exibir(lista);

  // Inverter novamente para testar recursivo com lista normal
  lista = inverter_lista(lista);
  printf("Voltando ao normal: ");
  exibir(lista);

  lista = inverter_lista_recursivo(lista);
  printf("Inverter (recursiva): ");
  exibir(lista);

  // Liberar memória
  liberar(lista);

  printf("\nPrograma finalizado!\n");
  return 0;
}

/* ============================================================
   RESUMO DAS SOLUÇÕES:

   1. CONTAR: while + contador
   2. BUSCAR: while + if para comparar
   3. MAIOR: while + guardar maior valor
   4. INVERTER: 3 apontadores (anterior, atual, próximo)
      - Cada passo: guardar próximo, inverter, avançar

   VERSÕES RECURSIVAS:
   - Cada uma segue o padrão:
     - Caso base (lista vazia ou fim)
     - Caso recursivo (processa um elemento + recursa)

============================================================ */
