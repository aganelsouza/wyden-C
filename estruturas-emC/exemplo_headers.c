#include <stdio.h>       // Biblioteca padrão: E/S
#include <stdlib.h>      // Biblioteca padrão: Utilidades
#include <string.h>      // Biblioteca padrão: Strings
#include <math.h>        // Biblioteca padrão: Matemática
#include <time.h>        // Biblioteca padrão: Tempo
#include <ctype.h>       // Biblioteca padrão: Classificação chars
#include <limits.h>      // Biblioteca padrão: Limites
#include "calculadora.h" // Biblioteca pessoal
#include "utilidade.h"   // Biblioteca pessoal

// ============================================
// EXEMPLO 1: USANDO BIBLIOTECAS PADRÃO
// ============================================
void exemplo1_bibliotecas_padrao()
{
  printf("\n");
  linha_separadora('=', 60);
  printf("EXEMPLO 1: BIBLIOTECAS PADRÃO\n");
  linha_separadora('=', 60);

  printf("\n--- stdio.h (Entrada/Saída) ---\n");
  printf("Usando printf() para exibir: Olá do stdio.h!\n");

  printf("\n--- string.h (Strings) ---\n");
  char str1[50] = "Olá";
  char str2[50] = "Mundo";
  printf("Comprimento de \"%s\": %lu\n", str1, strlen(str1));
  printf("Concatenando: ");
  strcat(str1, " ");
  strcat(str1, str2);
  printf("%s\n", str1);

  printf("\n--- math.h (Matemática) ---\n");
  printf("Raiz quadrada de 25: %.2f\n", sqrt(25));
  printf("2 elevado a 3: %.2f\n", pow(2, 3));
  printf("Seno de 0: %.2f\n", sin(0));

  printf("\n--- ctype.h (Classificação de caracteres) ---\n");
  printf("'5' é dígito? %s\n", isdigit('5') ? "Sim" : "Não");
  printf("'a' é letra? %s\n", isalpha('a') ? "Sim" : "Não");
  printf("'A' em minúscula: '%c'\n", tolower('A'));

  printf("\n--- time.h (Data/Hora) ---\n");
  time_t agora = time(NULL);
  printf("Tempo atual em segundos: %ld\n", agora);
  struct tm *tempo = localtime(&agora);
  printf("Data/Hora: %02d:%02d:%02d\n", tempo->tm_hour, tempo->tm_min, tempo->tm_sec);
}

// ============================================
// EXEMPLO 2: USANDO BIBLIOTECA PESSOAL (CALCULADORA)
// ============================================
void exemplo2_biblioteca_pessoal_calculadora()
{
  printf("\n");
  linha_separadora('=', 60);
  printf("EXEMPLO 2: BIBLIOTECA PESSOAL - CALCULADORA\n");
  linha_separadora('=', 60);

  exibir_calculadora();

  int a = 15;
  int b = 3;

  printf("\nOperações com a = %d e b = %d:\n", a, b);
  printf("  Adição:      %d + %d = %d\n", a, b, adicionar(a, b));
  printf("  Subtração:   %d - %d = %d\n", a, b, subtrair(a, b));
  printf("  Multiplicação: %d × %d = %d\n", a, b, multiplicar(a, b));
  printf("  Divisão:     %d ÷ %d = %.2f\n", a, b, dividir(a, b));
  printf("  Potência:    %d^%d = %d\n", a, b, potencia(a, b));
  printf("  Módulo:      %d mod %d = %d\n", a, b, modulo(a, b));
  printf("  Raiz Quadrada de %d: %.2f\n", a, raiz_quadrada(a));
}

// ============================================
// EXEMPLO 3: USANDO BIBLIOTECA PESSOAL (UTILIDADE)
// ============================================
void exemplo3_biblioteca_pessoal_utilidade()
{
  printf("\n");
  linha_separadora('=', 60);
  printf("EXEMPLO 3: BIBLIOTECA PESSOAL - UTILIDADE\n");
  linha_separadora('=', 60);

  printf("\n--- Saudações ---\n");
  saudacao();
  saudacao_personalizada("João Silva");

  printf("\n--- Operações com Arrays ---\n");
  int valores[] = {10, 25, 15, 30, 20};
  int tamanho = 5;

  printf("Array: ");
  exibir_array(valores, tamanho);
  printf("Soma dos elementos: %d\n", somar_array(valores, tamanho));
  printf("Valor máximo: %d\n", encontrar_maximo(valores, tamanho));
  printf("Valor mínimo: %d\n", encontrar_minimo(valores, tamanho));
  printf("Média: %.2f\n", (float)somar_array(valores, tamanho) / tamanho);

  printf("\n--- Operações com Strings ---\n");
  char mensagem[] = "Olá Mundo";
  printf("Mensagem original: \"%s\"\n", mensagem);
  printf("Tamanho da string: %d caracteres\n", contar_caracteres(mensagem));

  char copia[50];
  strcpy(copia, mensagem);
  inverter_string(copia);
  printf("String invertida: \"%s\"\n", copia);

  printf("Comparando \"ABC\" com \"abc\" (ignorando caso): %s\n",
         comparar_strings_ignora_caso("ABC", "abc") ? "Iguais" : "Diferentes");
}

// ============================================
// EXEMPLO 4: COMBINANDO MÚLTIPLAS BIBLIOTECAS
// ============================================
void exemplo4_combinando_bibliotecas()
{
  printf("\n");
  linha_separadora('=', 60);
  printf("EXEMPLO 4: COMBINANDO MÚLTIPLAS BIBLIOTECAS\n");
  linha_separadora('=', 60);

  printf("\nCálculo de IMC usando múltiplas bibliotecas:\n");
  printf("%-40s\n", "-------------------------------------------");

  float peso = 75.5f;
  float altura = 1.80f;

  // math.h
  float imc = peso / (altura * altura);

  // string.h + stdio.h
  char resultado[100];
  sprintf(resultado, "IMC: %.2f", imc);

  // ctype.h
  printf("Resultado em maiúsculas: ");
  for (int i = 0; resultado[i]; i++)
  {
    printf("%c", toupper(resultado[i]));
  }
  printf("\n");

  // calculadora.h
  printf("Peso: %.1f kg\n", peso);
  printf("Altura: %.2f m\n", altura);
  printf("IMC: %.2f\n", imc);

  if (imc < 18.5)
    printf("Classificação: Abaixo do peso\n");
  else if (imc < 25)
    printf("Classificação: Peso normal\n");
  else if (imc < 30)
    printf("Classificação: Sobrepeso\n");
  else
    printf("Classificação: Obesidade\n");
}

// ============================================
// EXEMPLO 5: MANIPULAÇÃO DE MEMÓRIA
// ============================================
void exemplo5_alocacao_dinamica()
{
  printf("\n");
  linha_separadora('=', 60);
  printf("EXEMPLO 5: ALOCAÇÃO DINÂMICA (stdlib.h)\n");
  linha_separadora('=', 60);

  printf("\n--- Alocação de Memory ---\n");

  // malloc
  int *numeros = (int *)malloc(5 * sizeof(int));
  if (numeros == NULL)
  {
    printf("Erro ao alocar memória!\n");
    return;
  }

  numeros[0] = 10;
  numeros[1] = 20;
  numeros[2] = 30;
  numeros[3] = 40;
  numeros[4] = 50;

  printf("Números alocados: ");
  exibir_array(numeros, 5);
  printf("Soma: %d\n", somar_array(numeros, 5));

  // realloc
  printf("\n--- Realocação de Memória ---\n");
  int *novo = (int *)realloc(numeros, 10 * sizeof(int));
  if (novo == NULL)
  {
    printf("Erro ao realocar!\n");
    free(numeros);
    return;
  }

  numeros = novo;
  numeros[5] = 60;
  numeros[6] = 70;
  numeros[7] = 80;
  numeros[8] = 90;
  numeros[9] = 100;

  printf("Números após realocação: ");
  exibir_array(numeros, 10);
  printf("Soma: %d\n", somar_array(numeros, 10));

  // calloc
  printf("\n--- Alocação com calloc (inicializado com 0) ---\n");
  int *zeros = (int *)calloc(5, sizeof(int));
  printf("Array calloc: ");
  exibir_array(zeros, 5);

  // free
  printf("\n--- Liberação de Memória ---\n");
  free(numeros);
  free(zeros);
  printf("Memória liberada com sucesso!\n");
}

// ============================================
// EXEMPLO 6: CONVERSÃO DE TIPOS (stdlib.h)
// ============================================
void exemplo6_conversao_tipos()
{
  printf("\n");
  linha_separadora('=', 60);
  printf("EXEMPLO 6: CONVERSÃO DE TIPOS (stdlib.h)\n");
  linha_separadora('=', 60);

  printf("\n--- Convertendo Strings para Números ---\n");

  const char *str_int = "42";
  const char *str_float = "3.14159";

  int numero_int = atoi(str_int);
  double numero_double = atof(str_float);

  printf("String \"%s\" → int: %d\n", str_int, numero_int);
  printf("String \"%s\" → double: %.5f\n", str_float, numero_double);

  printf("\n--- Usando em Cálculos ---\n");
  printf("Resultado: %d × 2 = %d\n", numero_int, numero_int * 2);
  printf("Resultado: %.5f × 2 = %.5f\n", numero_double, numero_double * 2);
}

// ============================================
// EXEMPLO 7: NÚMEROS ALEATÓRIOS (stdlib.h)
// ============================================
void exemplo7_numeros_aleatorios()
{
  printf("\n");
  linha_separadora('=', 60);
  printf("EXEMPLO 7: NÚMEROS ALEATÓRIOS (stdlib.h)\n");
  linha_separadora('=', 60);

  printf("\n--- Inicializando gerador com seed ---\n");
  srand((unsigned)time(NULL));

  printf("Números aleatórios entre 1 e 100:\n");
  for (int i = 0; i < 10; i++)
  {
    int aleatorio = (rand() % 100) + 1;
    printf("  %d ", aleatorio);
  }
  printf("\n");
}

// ============================================
// EXEMPLO 8: USO DE LIMITES (limits.h)
// ============================================
void exemplo8_limites_tipos()
{
  printf("\n");
  linha_separadora('=', 60);
  printf("EXEMPLO 8: LIMITES DE TIPOS (limits.h)\n");
  linha_separadora('=', 60);

  printf("\n--- Tamanhos e Limites ---\n");
  printf("Tamanho de int: %lu bytes\n", sizeof(int));
  printf("Tamanho de float: %lu bytes\n", sizeof(float));
  printf("Tamanho de double: %lu bytes\n", sizeof(double));
  printf("Tamanho de char: %lu bytes\n", sizeof(char));

  printf("\n--- Valores Extremos ---\n");
  printf("INT_MAX: %d\n", INT_MAX);
  printf("INT_MIN: %d\n", INT_MIN);
}

// ============================================
// FUNÇÃO PRINCIPAL
// ============================================
int main()
{
  printf("╔═════════════════════════════════════════════════════════╗\n");
  printf("║   BIBLIOTECAS E ARQUIVOS DE CABEÇALHO EM C              ║\n");
  printf("║         (Headers Padrão e Personalizados)              ║\n");
  printf("╚═════════════════════════════════════════════════════════╝\n");

  exemplo1_bibliotecas_padrao();
  exemplo2_biblioteca_pessoal_calculadora();
  exemplo3_biblioteca_pessoal_utilidade();
  exemplo4_combinando_bibliotecas();
  exemplo5_alocacao_dinamica();
  exemplo6_conversao_tipos();
  exemplo7_numeros_aleatorios();
  exemplo8_limites_tipos();

  printf("\n");
  linha_separadora('=', 60);
  printf("FIM DOS EXEMPLOS\n");
  linha_separadora('=', 60);
  printf("\nResumo:\n");
  printf("  ✓ Bibliotecas padrão (stdio, stdlib, string, math, etc)\n");
  printf("  ✓ Bibliotecas personalizadas (calculadora, utilidade)\n");
  printf("  ✓ Headers (.h) e implementações (.c)\n");
  printf("  ✓ Alocação dinâmica de memória\n");
  printf("  ✓ Conversão de tipos\n");
  printf("  ✓ Números aleatórios\n");
  printf("  ✓ Limites de tipos\n\n");

  return 0;
}
