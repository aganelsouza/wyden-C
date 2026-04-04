#include <stdio.h>
#include <stdlib.h>

/* ============================================================
   TEMPLATE PARA CRIAR EXERCÍCIOS
   ============================================================

   Copie este arquivo para começar seu exercício.
   Customize conforme necessário.

============================================================ */

// ========== DEFINIÇÕES ==========

typedef struct no
{
  int valor;
  struct no *proximo;
} no;

// ========== FUNÇÕES BÁSICAS ==========

// Criar nó
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

// Inserir no início
no *inserir_inicio(no *cabeca, int valor)
{
  no *novo = criar_no(valor);
  if (novo == NULL)
    return cabeca;

  novo->proximo = cabeca;
  return novo;
}

// Exibir lista
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

// Liberar memória
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

// ========== EXERCÍCIO 1: CONTAR ELEMENTOS ==========

int contar_elementos(no *cabeca)
{
  // TODO: Implementar esta função
  // Objetivo: Retornar a quantidade de elementos na lista
  // Exemplo: 1 -> 2 -> 3 => retorna 3

  // Sua implementação aqui:

  return 0; // Remova isso após implementar
}

// ========== EXERCÍCIO 2: BUSCAR ELEMENTO ==========

int buscar_elemento(no *cabeca, int valor)
{
  // TODO: Implementar esta função
  // Objetivo: Retornar 1 se encontra, 0 se não encontra
  // Exemplo: buscar 2 em (1 -> 2 -> 3) => retorna 1

  // Sua implementação aqui:

  return 0; // Remova isso após implementar
}

// ========== EXERCÍCIO 3: ENCONTRAR O MAIOR ==========

int encontrar_maior(no *cabeca)
{
  // TODO: Implementar esta função
  // Objetivo: Retornar o maior valor da lista
  // Exemplo: 5 -> 2 -> 8 -> 1 => retorna 8
  // Atenção: Testar com lista vazia!

  // Sua implementação aqui:

  return -1; // Remova isso após implementar
}

// ========== EXERCÍCIO 4: INVERTER LISTA (DESAFIO!) ==========

no *inverter_lista(no *cabeca)
{
  // TODO: Implementar esta função
  // Objetivo: Inverter a ordem dos elementos
  // Exemplo: 1 -> 2 -> 3 => 3 -> 2 -> 1
  // Dica: Use 3 apontadores (anterior, atual, proximo)

  // Sua implementação aqui:

  return cabeca; // Remova isso após implementar
}

// ========== PROGRAMA PRINCIPAL DE TESTE ==========

int main(int argc, char const *argv[])
{
  printf("========== EXERCÍCIOS COM LISTA ENCADEADA ==========\n\n");

  // Criar lista: 1 -> 2 -> 3 -> 4 -> 5
  no *lista = NULL;
  lista = inserir_inicio(lista, 5);
  lista = inserir_inicio(lista, 4);
  lista = inserir_inicio(lista, 3);
  lista = inserir_inicio(lista, 2);
  lista = inserir_inicio(lista, 1);

  exibir(lista);

  // ========== TESTE 1: CONTAR ==========
  printf("\n--- Teste 1: Contar Elementos ---\n");
  int quantidade = contar_elementos(lista);
  printf("Quantidade de elementos: %d (esperado: 5)\n", quantidade);

  // ========== TESTE 2: BUSCAR ==========
  printf("\n--- Teste 2: Buscar Elemento ---\n");
  printf("Buscar 3: %s (esperado: encontrado)\n",
         buscar_elemento(lista, 3) ? "encontrado" : "não encontrado");
  printf("Buscar 10: %s (esperado: não encontrado)\n",
         buscar_elemento(lista, 10) ? "encontrado" : "não encontrado");

  // ========== TESTE 3: MAIOR ==========
  printf("\n--- Teste 3: Encontrar Maior ---\n");
  int maior = encontrar_maior(lista);
  printf("Maior elemento: %d (esperado: 5)\n", maior);

  // ========== TESTE 4: INVERTER ==========
  printf("\n--- Teste 4: Inverter Lista ---\n");
  printf("Antes: ");
  exibir(lista);

  lista = inverter_lista(lista);

  printf("Depois: ");
  exibir(lista);
  printf("(esperado: 5 -> 4 -> 3 -> 2 -> 1 -> NULL)\n");

  // Liberar memória
  liberar(lista);

  printf("\nPrograma finalizado!\n");
  return 0;
}

/* ============================================================
   INSTRUÇÕES PARA EXERCITAR:

   1. Abra este arquivo: exercicio_template.c
   2. Implemente cada função onde está "TODO"
   3. Compile: gcc -o meu_exercicio exercicio_template.c
   4. Execute: ./meu_exercicio
   5. Veja se as saídas estão corretas

   DICAS:
   - Comece com contar_elementos() (mais fácil)
   - Use printf() para fazer debug
   - Revise os exemplos nos arquivos principais se ficar preso
   - Tente fazer cada função recursiva depois (DESAFIO!)

   BOA SORTE! 🚀
============================================================ */
