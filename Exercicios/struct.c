/**
 * ============================================================================
 * GUIA DIDÁTICO: STRUCTS EM C
 * ============================================================================
 *
 * Uma struct (estrutura) é um tipo de dado composto que permite agrupar
 * várias variáveis de diferentes tipos sob um único nome.
 *
 * VANTAGENS:
 * - Organiza dados relacionados em um único tipo
 * - Melhora a legibilidade e organização do código
 * - Facilita a passagem de dados entre funções
 * - Permite criar tipos de dados customizados
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================================
// 1. DEFININDO UMA STRUCT SIMPLES
// ============================================================================
/**
 * Uma struct é definida usando a palavra-chave 'struct', seguida de um nome
 * e uma lista de membros entre chaves.
 *
 * Sintaxe básica:
 *   struct nome_struct {
 *       tipo1 membro1;
 *       tipo2 membro2;
 *       ...
 *   };
 */
struct Ponto
{
  int x;
  int y;
};

// ============================================================================
// 2. TYPEDEF PARA CRIAR ALIAS
// ============================================================================
/**
 * Usar 'typedef' permite criar um alias (apelido) para a struct, tornando
 * mais práctico declarar variáveis sem repetir a palavra 'struct'.
 *
 * Sintaxe:
 *   typedef struct {
 *       tipo1 membro1;
 *       tipo2 membro2;
 *   } NomeAlias;
 */
typedef struct
{
  int id;
  int matricula;
  char nome[50];
  float salario;
  int data_nascimento;
  int contratado;
  char cargo[50];
  int data_contratacao;
  int data_demissao;
  char motivo_demissao[100];
  _Bool ativo;
} Funcionario;

// ============================================================================
// 3. FUNÇÃO AUXILIAR PARA EXIBIR FUNCIONÁRIO
// ============================================================================
/**
 * Boas práticas: criar funções reutilizáveis para operações comuns.
 * Isso evita repetição de código.
 */
void exibir_funcionario(Funcionario f)
{
  printf("\n--- Dados do Funcionário ---\n");
  printf("ID:              %d\n", f.id);
  printf("Matrícula:       %d\n", f.matricula);
  printf("Nome:            %s\n", f.nome);
  printf("Salário:         R$ %.2f\n", f.salario);
  printf("Nascimento:      %d\n", f.data_nascimento);
  printf("Contratado:      %s\n", f.contratado ? "Sim" : "Não");
  printf("Cargo:           %s\n", f.cargo);
  printf("Data Contratação:%d\n", f.data_contratacao);

  if (f.data_demissao != 0)
  {
    printf("Data Demissão:   %d\n", f.data_demissao);
    printf("Motivo:          %s\n", f.motivo_demissao);
  }

  printf("Status:          %s\n", f.ativo ? "Ativo" : "Inativo");
}

// ============================================================================
// 4. FUNÇÃO PARA INICIALIZAR UM FUNCIONÁRIO
// ============================================================================
/**
 * Criar funções de inicialização garante que todos os campos sejam
 * preenchidos corretamente, evitando erros e comportamentos indefinidos.
 */
Funcionario criar_funcionario(int id, int matricula, const char *nome,
                              float salario, int data_nasc,
                              const char *cargo)
{
  Funcionario f;
  f.id = id;
  f.matricula = matricula;
  strcpy(f.nome, nome);
  f.salario = salario;
  f.data_nascimento = data_nasc;
  f.contratado = 1;
  strcpy(f.cargo, cargo);
  f.data_contratacao = 20200101;
  f.data_demissao = 0;
  strcpy(f.motivo_demissao, "");
  f.ativo = 1;

  return f;
}

// ============================================================================
// MAIN: EXEMPLOS PRÁTICOS
// ============================================================================

int main()
{
  printf("\n");
  printf("╔════════════════════════════════════════════════════════════╗\n");
  printf("║         GUIA DIDÁTICO: STRUCTS EM C                       ║\n");
  printf("╚════════════════════════════════════════════════════════════╝\n");

  // ========================================================================
  // EXEMPLO 1: Criação e Acesso Manualmente
  // ========================================================================
  printf("\n\n[EXEMPLO 1] Criação Manual de Estrutura\n");
  printf("═══════════════════════════════════════════════════════════\n");

  Funcionario f1;
  f1.id = 1;
  f1.matricula = 12345;
  strcpy(f1.nome, "João Silva");
  f1.salario = 3500.00;
  f1.data_nascimento = 19900101;
  f1.contratado = 1;
  strcpy(f1.cargo, "Analista de Sistemas");
  f1.data_contratacao = 20200101;
  f1.data_demissao = 0;
  strcpy(f1.motivo_demissao, "");
  f1.ativo = 1;

  exibir_funcionario(f1);

  // ========================================================================
  // EXEMPLO 2: Usando Função para Criar Funcionário
  // ========================================================================
  printf("\n\n[EXEMPLO 2] Criação Usando Função\n");
  printf("═══════════════════════════════════════════════════════════\n");

  Funcionario f2 = criar_funcionario(2, 54321, "Maria Santos", 4000.00,
                                     19850515, "Gerente de Projetos");

  exibir_funcionario(f2);

  // ========================================================================
  // EXEMPLO 3: Array de Structs
  // ========================================================================
  printf("\n\n[EXEMPLO 3] Array de Estruturas\n");
  printf("═══════════════════════════════════════════════════════════\n");
  printf("Demonstra como armazenar múltiplas estruturas em um array.\n");

  Funcionario equipe[3];
  equipe[0] = criar_funcionario(1, 10001, "Carlos Oliveira", 3200.00,
                                19920315, "Desenvolvedor");
  equipe[1] = criar_funcionario(2, 10002, "Ana Costa", 3800.00,
                                19881220, "Tester QA");
  equipe[2] = criar_funcionario(3, 10003, "Pedro Martins", 4500.00,
                                19800705, "Líder Técnico");

  printf("\nExibindo todos os funcionários da equipe:\n");
  for (int i = 0; i < 3; i++)
  {
    exibir_funcionario(equipe[i]);
  }

  // ========================================================================
  // EXEMPLO 4: Struct Simples (Ponto)
  // ========================================================================
  printf("\n\n[EXEMPLO 4] Struct Simples - Ponto\n");
  printf("═══════════════════════════════════════════════════════════\n");
  printf("Um exemplo básico com apenas inteiros.\n");

  struct Ponto p1 = {10, 20};
  struct Ponto p2 = {30, 40};

  printf("Ponto 1: (%d, %d)\n", p1.x, p1.y);
  printf("Ponto 2: (%d, %d)\n", p2.x, p2.y);

  // ========================================================================
  // RESUMO DE CONCEITOS
  // ========================================================================
  printf("\n\n");
  printf("╔════════════════════════════════════════════════════════════╗\n");
  printf("║ RESUMO DE CONCEITOS IMPORTANTES                           ║\n");
  printf("╠════════════════════════════════════════════════════════════╣\n");
  printf("║ 1. Struct agrupa dados relacionados                       ║\n");
  printf("║ 2. Typedef simplifica a declaração de variáveis           ║\n");
  printf("║ 3. Acesso aos membros: variavel.membro                    ║\n");
  printf("║ 4. Strings em struct necessitam de strcpy()               ║\n");
  printf("║ 5. Funções podem receber/retornar structs                 ║\n");
  printf("║ 6. Arrays podem armazenar structs                         ║\n");
  printf("║ 7. Ponteiros para structs usam: ponteiro->membro          ║\n");
  printf("╚════════════════════════════════════════════════════════════╝\n\n");

  return 0;
}