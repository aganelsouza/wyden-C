#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ============================================
// GUIA PRÁTICO: VARIÁVEIS EM C
// ============================================

// VARIÁVEIS GLOBAIS
int contador_global = 0;
const float PI = 3.14159f; // Constante

// Função para demonstrar escopo estático
void demonstrar_static()
{
  static int chamadas = 0;
  chamadas++;
  printf("\nFunção chamada %d vez(es)\n", chamadas);
}

// ============================================
// EXEMPLO 1: TIPOS DE DADOS BÁSICOS
// ============================================
void exemplo_tipos_dados()
{
  printf("\n=== EXEMPLO 1: TIPOS DE DADOS ===\n");

  // Tipo inteiro
  int idade = 25;
  short numero_curto = 100;
  long numero_longo = 1234567890L;

  // Tipo ponto flutuante
  float preco = 19.99f;
  double temperatura = 36.5;

  // Tipo caractere
  char inicial = 'A';

  // Tipo booleano
  bool ativo = true;

  printf("Int: %d (tamanho: %lu bytes)\n", idade, sizeof(idade));
  printf("Short: %hd (tamanho: %lu bytes)\n", numero_curto, sizeof(numero_curto));
  printf("Long: %ld (tamanho: %lu bytes)\n", numero_longo, sizeof(numero_longo));
  printf("Float: %.2f (tamanho: %lu bytes)\n", preco, sizeof(preco));
  printf("Double: %.1f (tamanho: %lu bytes)\n", temperatura, sizeof(temperatura));
  printf("Char: %c (tamanho: %lu bytes)\n", inicial, sizeof(inicial));
  printf("Bool: %s (tamanho: %lu bytes)\n", ativo ? "true" : "false", sizeof(ativo));
}

// ============================================
// EXEMPLO 2: INICIALIZAÇÃO DE VARIÁVEIS
// ============================================
void exemplo_inicializacao()
{
  printf("\n=== EXEMPLO 2: INICIALIZAÇÃO ===\n");

  // Inicialização simples
  int x = 10;
  float y = 3.14f;

  // Múltiplas inicializações
  int a = 1, b = 2, c = 3;

  // Inicialização com const
  const int MAXIMO = 100;

  printf("x = %d, y = %.2f\n", x, y);
  printf("a = %d, b = %d, c = %d\n", a, b, c);
  printf("MAXIMO = %d (constante)\n", MAXIMO);
}

// ============================================
// EXEMPLO 3: MODIFICADORES DE TIPO
// ============================================
void exemplo_modificadores()
{
  printf("\n=== EXEMPLO 3: MODIFICADORES (signed/unsigned) ===\n");

  signed int numero_negativo = -50;
  unsigned int numero_positivo = 100;

  printf("Signed (com sinal): %d\n", numero_negativo);
  printf("Unsigned (sem sinal): %u\n", numero_positivo);
}

// ============================================
// EXEMPLO 4: OPERADORES COM VARIÁVEIS
// ============================================
void exemplo_operadores()
{
  printf("\n=== EXEMPLO 4: OPERADORES ===\n");

  int x = 10;
  int y = 3;

  printf("Aritméticos:\n");
  printf("  %d + %d = %d\n", x, y, x + y);
  printf("  %d - %d = %d\n", x, y, x - y);
  printf("  %d * %d = %d\n", x, y, x * y);
  printf("  %d / %d = %d\n", x, y, x / y);
  printf("  %d %% %d = %d\n", x, y, x % y);

  printf("\nAtribuição composta:\n");
  int z = 20;
  printf("  z = %d\n", z);
  z += 5;
  printf("  z += 5 → z = %d\n", z);
  z -= 3;
  printf("  z -= 3 → z = %d\n", z);
  z *= 2;
  printf("  z *= 2 → z = %d\n", z);
  z /= 4;
  printf("  z /= 4 → z = %d\n", z);

  printf("\nIncremento/Decremento:\n");
  int contador = 5;
  printf("  contador = %d\n", contador);
  printf("  contador++ = %d, depois contador = %d\n", contador++, contador);
  printf("  ++contador = %d\n", ++contador);
  printf("  contador-- = %d, depois contador = %d\n", contador--, contador);
  printf("  --contador = %d\n", --contador);
}

// ============================================
// EXEMPLO 5: ENDEREÇO DE MEMÓRIA
// ============================================
void exemplo_endereco()
{
  printf("\n=== EXEMPLO 5: ENDEREÇO DE MEMÓRIA (Operador &) ===\n");

  int numero = 42;
  float decimal = 3.14f;
  char letra = 'X';

  printf("Variável 'numero':\n");
  printf("  Valor: %d\n", numero);
  printf("  Endereço: %p\n", (void *)&numero);
  printf("  Tamanho: %lu bytes\n", sizeof(numero));

  printf("\nVariável 'decimal':\n");
  printf("  Valor: %.2f\n", decimal);
  printf("  Endereço: %p\n", (void *)&decimal);
  printf("  Tamanho: %lu bytes\n", sizeof(decimal));

  printf("\nVariável 'letra':\n");
  printf("  Valor: %c\n", letra);
  printf("  Endereço: %p\n", (void *)&letra);
  printf("  Tamanho: %lu bytes\n", sizeof(letra));
}

// ============================================
// EXEMPLO 6: CONVERSÃO DE TIPOS (CASTING)
// ============================================
void exemplo_casting()
{
  printf("\n=== EXEMPLO 6: CONVERSÃO DE TIPOS (CASTING) ===\n");

  // Conversão implícita
  int inteiro = 5;
  double resultado = inteiro;
  printf("Conversão implícita: int %d → double %.1f\n", inteiro, resultado);

  // Conversão explícita
  double valor = 3.7;
  int truncado = (int)valor;
  printf("Conversão explícita: double %.1f → int %d\n", valor, truncado);

  // Conversão em expressão
  int a = 10;
  int b = 3;
  printf("Divisão sem cast: %d / %d = %d\n", a, b, a / b);
  printf("Divisão com cast: %d / %d = %.2f\n", a, b, (float)a / b);

  // Char para int (código ASCII)
  char letra = 'A';
  int codigo = (int)letra;
  printf("Char '%c' → código ASCII %d\n", letra, codigo);
}

// ============================================
// EXEMPLO 7: LEITURA E ESCRITA (I/O)
// ============================================
void exemplo_io()
{
  printf("\n=== EXEMPLO 7: ENTRADA E SAÍDA ===\n");

  int numero;
  float valor;
  char caractere;

  printf("Digite um número inteiro: ");
  scanf("%d", &numero);

  printf("Digite um valor decimal: ");
  scanf("%f", &valor);

  printf("Digite um caractere: ");
  scanf(" %c", &caractere); // Note o espaço antes de %c

  printf("\nValores lidos:\n");
  printf("  Número: %d\n", numero);
  printf("  Valor: %.2f\n", valor);
  printf("  Caractere: %c\n", caractere);
}

// ============================================
// EXEMPLO 8: ESCOPO LOCAL
// ============================================
void exemplo_escopo_local()
{
  printf("\n=== EXEMPLO 8: ESCOPO LOCAL ===\n");

  int x = 100; // Escopo local de exemplo_escopo_local
  printf("x fora do bloco: %d\n", x);

  {
    int x = 50; // Novo x, escopo apenas deste bloco
    printf("x dentro do bloco: %d (escopo local)\n", x);
  }

  printf("x após o bloco: %d (volta ao valor anterior)\n", x);
}

// ============================================
// EXEMPLO 9: VARIÁVEL ESTÁTICA (STATIC)
// ============================================
void exemplo_static()
{
  printf("\n=== EXEMPLO 9: VARIÁVEL ESTÁTICA ===\n");
  printf("Chamadas à função 'demonstrar_static':\n");

  demonstrar_static(); // Chamada 1
  demonstrar_static(); // Chamada 2
  demonstrar_static(); // Chamada 3
  demonstrar_static(); // Chamada 4
}

// ============================================
// EXEMPLO 10: CÁLCULOS PRÁTICOS
// ============================================
void exemplo_calculos_praticos()
{
  printf("\n=== EXEMPLO 10: CÁLCULOS PRÁTICOS ===\n");

  // Cálculo de IMC
  float peso = 75.5f;   // kg
  float altura = 1.80f; // metros
  float imc = peso / (altura * altura);

  printf("Cálculo de IMC:\n");
  printf("  Peso: %.1f kg\n", peso);
  printf("  Altura: %.2f m\n", altura);
  printf("  IMC: %.2f\n", imc);

  // Cálculo de área do círculo
  float raio = 5.0f;
  float area = PI * raio * raio;
  float perimetro = 2 * PI * raio;

  printf("\nCálculo de círculo (raio = %.1f):\n", raio);
  printf("  Área: %.2f\n", area);
  printf("  Perímetro: %.2f\n", perimetro);

  // Cálculo de juros
  float capital = 1000.0f;
  float taxa = 0.05f; // 5%
  int meses = 12;
  float total = capital * (1 + taxa * meses);

  printf("\nCálculo de juros simples:\n");
  printf("  Capital: R$ %.2f\n", capital);
  printf("  Taxa: %.1f%% ao mês\n", taxa * 100);
  printf("  Período: %d meses\n", meses);
  printf("  Total com juros: R$ %.2f\n", total);
}

// ============================================
// FUNÇÃO PRINCIPAL
// ============================================
int main()
{
  printf("╔════════════════════════════════════════════════════════╗\n");
  printf("║     GUIA PRÁTICO: VARIÁVEIS EM C                       ║\n");
  printf("╚════════════════════════════════════════════════════════╝\n");

  // Executar todos os exemplos
  exemplo_tipos_dados();
  exemplo_inicializacao();
  exemplo_modificadores();
  exemplo_operadores();
  exemplo_endereco();
  exemplo_casting();
  exemplo_escopo_local();
  exemplo_static();
  exemplo_calculos_praticos();

  // Exemplos que requerem entrada do usuário (descomente para usar)
  // exemplo_io();

  printf("\n╔════════════════════════════════════════════════════════╗\n");
  printf("║     FIM DO GUIA                                       ║\n");
  printf("╚════════════════════════════════════════════════════════╝\n");

  return 0;
}