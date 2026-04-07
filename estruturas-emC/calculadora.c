#include "calculadora.h"
#include <stdio.h>
#include <math.h>

// ============================================
// IMPLEMENTAÇÃO DAS FUNÇÕES DA CALCULADORA
// ============================================

int adicionar(int a, int b)
{
  return a + b;
}

int subtrair(int a, int b)
{
  return a - b;
}

int multiplicar(int a, int b)
{
  return a * b;
}

float dividir(int a, int b)
{
  if (b == 0)
  {
    printf("Erro: Divisão por zero!\n");
    return 0;
  }
  return (float)a / b;
}

int potencia(int base, int expoente)
{
  if (expoente < 0)
  {
    printf("Erro: Expoente negativo!\n");
    return 0;
  }

  int resultado = 1;
  for (int i = 0; i < expoente; i++)
  {
    resultado *= base;
  }
  return resultado;
}

int modulo(int a, int b)
{
  if (b == 0)
  {
    printf("Erro: Módulo por zero!\n");
    return 0;
  }
  return a % b;
}

double raiz_quadrada(double valor)
{
  if (valor < 0)
  {
    printf("Erro: Raiz de número negativo!\n");
    return 0;
  }
  return sqrt(valor);
}

void exibir_calculadora()
{
  printf("\n╔═════════════════════════════════════╗\n");
  printf("║      CALCULADORA EM C               ║\n");
  printf("║   (Usando biblioteca personalizada) ║\n");
  printf("╚═════════════════════════════════════╝\n");
}
