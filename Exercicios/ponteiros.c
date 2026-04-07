#include <stdio.h>
#include <stdlib.h>

// ============================================================================
// 1. INTRODUÇÃO A PONTEIROS
// ============================================================================
/**
 * Ponteiros são variáveis que armazenam o endereço de memória de outra variável.
 * Eles permitem manipular dados de forma indireta, facilitando a criação de
 * estruturas de dados dinâmicas, passagem eficiente de grandes estruturas para
 * funções e muito mais.
 * Vantagens dos ponteiros:
 * - Passagem de parâmetros por referência (eficiência)
 * - Criação de estruturas de dados dinâmicas (listas, árvores, grafos)
 * - Manipulação eficiente de grandes volumes de dados
 * - Implementação de funções que podem modificar múltiplas variáveis
 */
int soma(int x, int y)
{
  return x + y;
}

int main()
{
  printf("\n");
  printf("╔════════════════════════════════════════════════════════════╗\n");
  printf("║         GUIA DIDÁTICO: PONTEIROS EM C                      ║\n");
  printf("╚════════════════════════════════════════════════════════════╝\n");

  // ========================================================================
  // EXEMPLO 1: Declaração e Uso Básico de Ponteiros
  // ========================================================================
  printf("\n\n[EXEMPLO 1] Declaração e Uso Básico de Ponteiros\n");
  printf("═══════════════════════════════════════════════════════════\n");

  int a = 10;
  int *ptr_a = &a; // ptr_a armazena o endereço de a

  printf("Valor de a: %d\n", a);
  printf("Endereço de a: %p\n", (void *)&a);
  printf("Valor do ponteiro ptr_a: %p\n", (void *)ptr_a);
  printf("Valor apontado por ptr_a: %d\n", *ptr_a);

  // ========================================================================
  // EXEMPLO 2: Modificando Variáveis Usando Ponteiros
  // ========================================================================
  printf("\n\n[EXEMPLO 2] Modificando Variáveis Usando Ponteiros\n");
  printf("═══════════════════════════════════════════════════════════\n");

  *ptr_a = 20; // Modifica o valor de a através do ponteiro

  printf("Novo valor de a após modificação via ponteiro: %d\n", a);

  // ========================================================================
  // EXEMPLO 3: Ponteiros para Structs
  // ========================================================================
  printf("\n\n[EXEMPLO 3] Ponteiros para Structs\n");
  printf("═══════════════════════════════════════════════════════════\n");
  typedef struct
  {
    int id;
    char nome[50];
  } Pessoa;
  Pessoa p1 = {1, "João"};
  Pessoa *ptr_p1 = &p1;

  printf("ID de p1: %d\n", p1.id);
  printf("Nome de p1: %s\n", p1.nome);

  // Acessando membros da struct através do ponteiro
  printf("ID via ponteiro: %d\n", ptr_p1->id);
  printf("Nome via ponteiro: %s\n", ptr_p1->nome);

  // ========================================================================
  // EXEMPLO 4: Alocação Dinâmica de Memória com Ponteiros
  // ========================================================================
  printf("\n\n[EXEMPLO 4] Alocação Dinâmica de Memória com Ponteiros\n");
  printf("═══════════════════════════════════════════════════════════\n");
  int *array = (int *)malloc(5 * sizeof(int)); // Aloca um array de 5 inteiros
  if (array == NULL)
  {
    fprintf(stderr, "Erro ao alocar memória\n");
    return 1;
  }
  for (int i = 0; i < 5; i++)
  {
    array[i] = i + 1; // Preenche o array com valores de 1 a 5
  }
  printf("Array alocado dinamicamente: ");
  for (int i = 0; i < 5; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  free(array); // Libera a memória alocada

  //
  // ========================================================================
  // EXEMPLO 5: Ponteiros para Funções
  // ========================================================================
  printf("\n\n[EXEMPLO 5] Ponteiros para Funções\n");
  printf("═══════════════════════════════════════════════════════════\n");
  int (*ptr_soma)(int, int) = soma; // Ponteiro para a função soma
  int resultado = ptr_soma(5, 10); // Chama a função através do ponteiro
  printf("Resultado da soma via ponteiro: %d\n", resultado);
  // ========================================================================
  // RESUMO DE CONCEITOS
  // ========================================================================
  printf("\n\n");
  printf("╔════════════════════════════════════════════════════════════╗\n");
  printf("║ RESUMO DE CONCEITOS IMPORTANTES                            ║\n");
  printf("╠════════════════════════════════════════════════════════════╣\n");
  printf("║ - Um ponteiro é uma variável que armazena o endereço de    ║\n");
  printf("║   memória de outra variável.                               ║\n");
  printf("║ - Acessamos o valor apontado por um ponteiro usando o      ║\n");
  printf("║   operador de desreferenciação (*).                        ║\n");
  printf("║ - Ponteiros para structs permitem acessar membros usando   ║\n");
  printf("║   o operador '->'.                                         ║\n");
  printf("║ - Alocação dinâmica de memória é feita usando malloc() e   ║\n");
  printf("║   liberada com free().                                     ║\n");
  printf("║ - Ponteiros para funções permitem armazenar endereços de   ║\n");
  printf("║   funções e chamá-las indiretamente.                       ║\n");
  printf("╚════════════════════════════════════════════════════════════╝\n\n");

  return 0;
}
