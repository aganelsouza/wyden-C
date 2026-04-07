#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ============================================
// ESCOPO GLOBAL, TEMPO DE VIDA ESTÁTICO
// ============================================
int contador_global = 0;         // Acessível em qualquer lugar
static int contador_privado = 0; // Privado a este arquivo
extern int valor_externo;        // Declaração (será definida em outro arquivo se existisse)

// ============================================
// EXEMPLO 1: VARIÁVEIS AUTOMÁTICAS (AUTO)
// ============================================
void exemplo1_auto()
{
  printf("\n=== EXEMPLO 1: VARIÁVEIS AUTOMÁTICAS ===\n");

  int x = 100; // Implicitamente 'auto'
  printf("x = %d\n", x);
  printf("Endereço de x: %p\n", (void *)&x);

  {
    int x = 200; // Nova variável, mesmo nome, escopo local
    printf("x (dentro do bloco) = %d\n", x);
    printf("Endereço de x (dentro do bloco): %p\n", (void *)&x);
  }

  printf("x (após o bloco) = %d\n", x);
  printf("Endereço de x (após o bloco): %p\n", (void *)&x);
}

// ============================================
// EXEMPLO 2: VARIÁVEIS ESTÁTICAS (STATIC)
// ============================================
void contador_chamadas()
{
  static int chamadas = 0; // Inicializada uma única vez
  chamadas++;
  printf("Função chamada %d vez(es)\n", chamadas);
}

void exemplo2_static()
{
  printf("\n=== EXEMPLO 2: VARIÁVEIS ESTÁTICAS ===\n");
  printf("Demonstrando retenção de valor:\n");

  for (int i = 0; i < 5; i++)
  {
    contador_chamadas();
  }
}

// ============================================
// EXEMPLO 3: VARIÁVEIS GLOBAIS
// ============================================
void funcao_a()
{
  contador_global++;
  printf("Em funcao_a: contador_global = %d\n", contador_global);
}

void funcao_b()
{
  contador_global += 10;
  printf("Em funcao_b: contador_global = %d\n", contador_global);
}

void exemplo3_global()
{
  printf("\n=== EXEMPLO 3: VARIÁVEIS GLOBAIS ===\n");
  printf("Compartilhadas entre funções\n");
  printf("Valor inicial de contador_global: %d\n", contador_global);

  funcao_a();
  funcao_b();
  funcao_a();

  printf("Valor final de contador_global: %d\n", contador_global);
}

// ============================================
// EXEMPLO 4: VARIÁVEL ESTÁTICA PRIVADA (PRIVACIDADE)
// ============================================
void incrementar_privado()
{
  contador_privado++;
  printf("contador_privado (função incrementar): %d\n", contador_privado);
}

void exemplo4_privado()
{
  printf("\n=== EXEMPLO 4: VARIÁVEL ESTÁTICA PRIVADA ===\n");
  printf("'static' no escopo global torna a variável privada ao arquivo\n");

  incrementar_privado();
  incrementar_privado();
  incrementar_privado();
}

// ============================================
// EXEMPLO 5: SHADOWING (SOMBREAMENTO)
// ============================================
int valor_importante = 100; // Global

void funcao_com_shadowing()
{
  int valor_importante = 50; // Local (esconde a global)
  printf("Dentro da função: valor_importante = %d\n", valor_importante);
}

void exemplo5_shadowing()
{
  printf("\n=== EXEMPLO 5: SHADOWING (SOMBREAMENTO) ===\n");
  printf("Variável local com mesmo nome esconde a global\n");

  printf("Global: valor_importante = %d\n", valor_importante);
  funcao_com_shadowing();
  printf("Global (após função): valor_importante = %d\n", valor_importante);
}

// ============================================
// EXEMPLO 6: ESCOPO DE BLOCO
// ============================================
void exemplo6_bloco()
{
  printf("\n=== EXEMPLO 6: ESCOPO DE BLOCO ===\n");

  int nivel = 0;
  printf("[Nível 0] nivel = %d\n", nivel);

  {
    int nivel = 1;
    printf("[Nível 1] nivel = %d\n", nivel);

    {
      int nivel = 2;
      printf("[Nível 2] nivel = %d\n", nivel);

      {
        int nivel = 3;
        printf("[Nível 3] nivel = %d\n", nivel);
      }

      printf("[Voltando ao Nível 2] nivel = %d\n", nivel);
    }

    printf("[Voltando ao Nível 1] nivel = %d\n", nivel);
  }

  printf("[Voltando ao Nível 0] nivel = %d\n", nivel);
}

// ============================================
// EXEMPLO 7: TEMPO DE VIDA vs ESCOPO
// ============================================
void exibir_endereco()
{
  int x = 999;
  printf("Endereço de x em exibir_endereco: %p\n", (void *)&x);
}

void exemplo7_tempo_vida()
{
  printf("\n=== EXEMPLO 7: TEMPO DE VIDA vs ESCOPO ===\n");
  printf("Observe os endereços: mesma variável, mesmos endereços ou diferentes\n\n");

  printf("Chamada 1:\n");
  exibir_endereco();

  printf("Chamada 2:\n");
  exibir_endereco();

  printf("\nChamada 3:\n");
  exibir_endereco();
}

// ============================================
// EXEMPLO 8: VARIÁVEL ESTÁTICA LOCAL
// ============================================
void fibonacci_static()
{
  static int anterior = 0, atual = 1;
  int proximo = anterior + atual;

  printf("Fibonacci: %d\n", proximo);

  anterior = atual;
  atual = proximo;
}

void exemplo8_static_local()
{
  printf("\n=== EXEMPLO 8: VARIÁVEL ESTÁTICA LOCAL ===\n");
  printf("Mantém estado entre chamadas\n");

  for (int i = 0; i < 8; i++)
  {
    fibonacci_static();
  }
}

// ============================================
// EXEMPLO 9: CICLO DE VIDA VISUAL
// ============================================
void diagrama_ciclo_vida()
{
  printf("\n=== EXEMPLO 9: CICLO DE VIDA ===\n");

  {
    int a = 1;
    printf("1. a = 1 criada (escopo: bloco 1)\n");
    printf("   Tempo de vida: iniciado\n");

    {
      int b = 2;
      printf("2. b = 2 criada (escopo: bloco 2)\n");
      printf("   Tempo de vida: iniciado\n");
      printf("   Acessíveis: a, b\n");
    }

    printf("3. b destruída (fim de escopo, fim de tempo de vida)\n");
    printf("   Acessíveis: a\n");
    printf("   b NÃO existe mais\n");
  }

  printf("4. a destruída (fim de escopo, fim de tempo de vida)\n");
  printf("   Acessíveis: nenhuma local\n");
}

// ============================================
// EXEMPLO 10: REGRAS DE VISIBILIDADE
// ============================================
char regra_vazia[] = ""; // Global

void exemplo10_regras_visibilidade()
{
  printf("\n=== EXEMPLO 10: REGRAS DE VISIBILIDADE ===\n");

  int a = 1;
  printf("Nível 1: posso ver 'a' = %d\n", a);
  printf("Nível 1: variáveis globais também são acessíveis\n");

  {
    int b = 2;
    printf("Nível 2: posso ver 'a' e 'b'\n");
    printf("Nível 2: a = %d, b = %d\n", a, b);

    {
      int c = 3;
      printf("Nível 3: posso ver 'a', 'b' e 'c'\n");
      printf("Nível 3: a = %d, b = %d, c = %d\n", a, b, c);
    }

    // printf("Nível 2: c = %d\n", c);  // ERRO! c fora de escopo
    printf("Nível 2: 'c' não é acessível aqui (saiu do escopo)\n");
  }
}

// ============================================
// EXEMPLO 11: ARMAZENAMENTO COMPARATIVO
// ============================================
void exemplo11_comparacao_armazenamento()
{
  printf("\n=== EXEMPLO 11: COMPARAÇÃO DE ARMAZENAMENTO ===\n");
  printf("Classes de armazenamento: AUTO vs STATIC vs GLOBAL\n\n");

  printf("Auto (local):\n");
  {
    int auto_var = 100;
    printf("  Valor: %d\n", auto_var);
    printf("  Endereço: %p\n", (void *)&auto_var);
    printf("  Tempo de vida: bloco { }\n");
    printf("  Escopo: local\n");
  }

  printf("\nStatic local:\n");
  {
    static int static_var = 200;
    printf("  Valor: %d\n", static_var);
    printf("  Endereço: %p\n", (void *)&static_var);
    printf("  Tempo de vida: programa inteiro\n");
    printf("  Escopo: bloco { }\n");
  }

  printf("\nGlobal:\n");
  printf("  Valor: %d\n", contador_global);
  printf("  Endereço: %p\n", (void *)&contador_global);
  printf("  Tempo de vida: programa inteiro\n");
  printf("  Escopo: qualquer lugar\n");
}

// ============================================
// EXEMPLO 12: IDENTIFICADOR COM MESMO NOME
// ============================================
int resultado = 1000; // Global chamado 'resultado'

void funcao_resultado()
{
  int resultado = 2000; // Local chamado 'resultado'
  printf("Resultado local na função: %d\n", resultado);
}

void exemplo12_multiplos_nomes()
{
  printf("\n=== EXEMPLO 12: VARIÁVEIS COM MESMO NOME ===\n");

  int resultado = 3000; // Resultado local em main

  printf("Resultado local em main: %d\n", resultado);
  printf("Valor global (antes): %d\n", valor_importante);
  printf("(Em C, não há forma de acessar global se sombreado por local)\n");

  funcao_resultado();
}

// ============================================
// FUNÇÃO PRINCIPAL
// ============================================
int main()
{
  printf("╔═══════════════════════════════════════════════════════╗\n");
  printf("║   TEMPO DE VIDA E ESCOPO DE VARIÁVEIS EM C            ║\n");
  printf("╚═══════════════════════════════════════════════════════╝\n");

  // Executar todos os exemplos
  exemplo1_auto();
  exemplo2_static();
  exemplo3_global();
  exemplo4_privado();
  exemplo5_shadowing();
  exemplo6_bloco();
  exemplo7_tempo_vida();
  exemplo8_static_local();
  diagrama_ciclo_vida();
  exemplo10_regras_visibilidade();
  exemplo11_comparacao_armazenamento();
  exemplo12_multiplos_nomes();

  printf("\n╔═══════════════════════════════════════════════════════╗\n");
  printf("║   RESUMO: TEMPO DE VIDA E ESCOPO                      ║\n");
  printf("╠═══════════════════════════════════════════════════════╣\n");
  printf("║ ESCOPO = Onde?     (Onde variável é acessível)       ║\n");
  printf("║ TEMPO DE VIDA = Quanto tempo? (Quando existe)        ║\n");
  printf("║                                                       ║\n");
  printf("║ AUTO:    Escopo local, tempo automático               ║\n");
  printf("║ STATIC:  Escopo local, tempo permanente               ║\n");
  printf("║ GLOBAL:  Escopo global, tempo permanente              ║\n");
  printf("║ EXTERN:  Referência global de outro arquivo           ║\n");
  printf("╚═══════════════════════════════════════════════════════╝\n");

  return 0;
}
