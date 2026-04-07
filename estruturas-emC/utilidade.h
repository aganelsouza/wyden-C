#ifndef UTILIDADE_H
#define UTILIDADE_H

// Funções de manipulação de saudações
void saudacao();
void saudacao_personalizada(char *nome);

// Funções de array
void exibir_array(int *arr, int tamanho);
int somar_array(int *arr, int tamanho);
int encontrar_maximo(int *arr, int tamanho);
int encontrar_minimo(int *arr, int tamanho);

// Funções de manipulação de strings
int contar_caracteres(char *str);
void inverter_string(char *str);
int comparar_strings_ignora_caso(char *str1, char *str2);

// Função separadora
void linha_separadora(char c, int tamanho);

#endif
