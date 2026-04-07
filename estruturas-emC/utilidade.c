#include "utilidade.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ============================================
// IMPLEMENTAÇÃO DAS FUNÇÕES DE UTILIDADE
// ============================================

void saudacao()
{
  printf("Olá! Bem-vindo ao programa!\n");
}

void saudacao_personalizada(char *nome)
{
  if (nome == NULL)
  {
    printf("Erro: Nome inválido!\n");
    return;
  }
  printf("Olá, %s! Bem-vindo!\n", nome);
}

void exibir_array(int *arr, int tamanho)
{
  if (arr == NULL || tamanho <= 0)
  {
    printf("Array inválido!\n");
    return;
  }

  printf("[ ");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

int somar_array(int *arr, int tamanho)
{
  if (arr == NULL || tamanho <= 0)
  {
    return 0;
  }

  int soma = 0;
  for (int i = 0; i < tamanho; i++)
  {
    soma += arr[i];
  }
  return soma;
}

int encontrar_maximo(int *arr, int tamanho)
{
  if (arr == NULL || tamanho <= 0)
  {
    return 0;
  }

  int maximo = arr[0];
  for (int i = 1; i < tamanho; i++)
  {
    if (arr[i] > maximo)
    {
      maximo = arr[i];
    }
  }
  return maximo;
}

int encontrar_minimo(int *arr, int tamanho)
{
  if (arr == NULL || tamanho <= 0)
  {
    return 0;
  }

  int minimo = arr[0];
  for (int i = 1; i < tamanho; i++)
  {
    if (arr[i] < minimo)
    {
      minimo = arr[i];
    }
  }
  return minimo;
}

int contar_caracteres(char *str)
{
  if (str == NULL)
  {
    return 0;
  }
  return strlen(str);
}

void inverter_string(char *str)
{
  if (str == NULL)
  {
    return;
  }

  int inicio = 0;
  int fim = strlen(str) - 1;

  while (inicio < fim)
  {
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;

    inicio++;
    fim--;
  }
}

int comparar_strings_ignora_caso(char *str1, char *str2)
{
  if (str1 == NULL || str2 == NULL)
  {
    return -1;
  }

  for (int i = 0;; i++)
  {
    char c1 = tolower(str1[i]);
    char c2 = tolower(str2[i]);

    if (c1 != c2)
    {
      return 0; // Diferentes
    }

    if (c1 == '\0')
    {
      return 1; // Iguais
    }
  }
}

void linha_separadora(char c, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("%c", c);
  }
  printf("\n");
}
