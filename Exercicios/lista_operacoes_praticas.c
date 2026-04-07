#include <stdio.h>
#include <stdlib.h>

// ============================================================================
// ESTRUTURA PARA REPRESENTAR A LISTA
// ============================================================================

typedef struct
{
  int *vetor;
  int tamanho;
  int quantidade; // Quantidade atual de elementos
} Lista;

// ============================================================================
// 1. CRIAR LISTA
// ============================================================================

Lista *criar_lista(int capacidade)
{
  Lista *l = (Lista *)malloc(sizeof(Lista));
  l->vetor = (int *)malloc(capacidade * sizeof(int));
  l->tamanho = capacidade; // Capacidade máxima
  l->quantidade = 0;       // Nenhum elemento no início
  return l;
}

// ============================================================================
// 2. LISTAR/IMPRIMIR ELEMENTOS
// ============================================================================

void listar_elementos(Lista *l)
{
  if (l->quantidade == 0)
  {
    printf("\n⚠️  Lista vazia!\n");
    return;
  }

  printf("\n📋 Elementos da lista (%d elementos):\n", l->quantidade);
  for (int i = 0; i < l->quantidade; i++)
  {
    printf("Posição [%d] = %d\n", i, l->vetor[i]);
  }
  printf("\n");
}

// ============================================================================
// 3. CONTAR ELEMENTOS
// ============================================================================

int contar_elementos(Lista *l)
{
  return l->quantidade;
}

// ============================================================================
// 4. INSERIR ELEMENTOS
// ============================================================================

// 4.1 - Inserir no FINAL da lista
void inserir_final(Lista *l, int valor)
{
  if (l->quantidade >= l->tamanho)
  {
    printf("❌ Lista cheia! Não é possível inserir.\n");
    return;
  }
  l->vetor[l->quantidade] = valor;
  l->quantidade++;
  printf("✅ Valor %d inserido no final!\n", valor);
}

// 4.2 - Inserir no INÍCIO da lista
void inserir_inicio(Lista *l, int valor)
{
  if (l->quantidade >= l->tamanho)
  {
    printf("❌ Lista cheia! Não é possível inserir.\n");
    return;
  }

  // Deslocar todos os elementos uma posição para a direita
  for (int i = l->quantidade; i > 0; i--)
  {
    l->vetor[i] = l->vetor[i - 1];
  }
  l->vetor[0] = valor;
  l->quantidade++;
  printf("✅ Valor %d inserido no início!\n", valor);
}

// 4.3 - Inserir em POSIÇÃO ESPECÍFICA
void inserir_posicao(Lista *l, int valor, int posicao)
{
  if (l->quantidade >= l->tamanho)
  {
    printf("❌ Lista cheia! Não é possível inserir.\n");
    return;
  }

  if (posicao < 0 || posicao > l->quantidade)
  {
    printf("❌ Posição inválida! (0 a %d)\n", l->quantidade);
    return;
  }

  // Deslocar elementos a partir da posição
  for (int i = l->quantidade; i > posicao; i--)
  {
    l->vetor[i] = l->vetor[i - 1];
  }
  l->vetor[posicao] = valor;
  l->quantidade++;
  printf("✅ Valor %d inserido na posição %d!\n", valor, posicao);
}

// ============================================================================
// 5. REMOVER ELEMENTOS
// ============================================================================

// 5.1 - Remover do FINAL
void remover_final(Lista *l)
{
  if (l->quantidade == 0)
  {
    printf("❌ Lista vazia! Nada para remover.\n");
    return;
  }

  int valor_removido = l->vetor[l->quantidade - 1];
  l->quantidade--;
  printf("✅ Valor %d removido do final!\n", valor_removido);
}

// 5.2 - Remover do INÍCIO
void remover_inicio(Lista *l)
{
  if (l->quantidade == 0)
  {
    printf("❌ Lista vazia! Nada para remover.\n");
    return;
  }

  int valor_removido = l->vetor[0];

  // Deslocar todos os elementos uma posição para a esquerda
  for (int i = 0; i < l->quantidade - 1; i++)
  {
    l->vetor[i] = l->vetor[i + 1];
  }
  l->quantidade--;
  printf("✅ Valor %d removido do início!\n", valor_removido);
}

// 5.3 - Remover de POSIÇÃO ESPECÍFICA
void remover_posicao(Lista *l, int posicao)
{
  if (l->quantidade == 0)
  {
    printf("❌ Lista vazia! Nada para remover.\n");
    return;
  }

  if (posicao < 0 || posicao >= l->quantidade)
  {
    printf("❌ Posição inválida! (0 a %d)\n", l->quantidade - 1);
    return;
  }

  int valor_removido = l->vetor[posicao];

  // Deslocar elementos para preencher o espaço
  for (int i = posicao; i < l->quantidade - 1; i++)
  {
    l->vetor[i] = l->vetor[i + 1];
  }
  l->quantidade--;
  printf("✅ Valor %d removido da posição %d!\n", valor_removido, posicao);
}

// 5.4 - Remover o PRIMEIRO elemento com VALOR específico
void remover_valor(Lista *l, int valor)
{
  int posicao = -1;

  // Procurar a posição do valor
  for (int i = 0; i < l->quantidade; i++)
  {
    if (l->vetor[i] == valor)
    {
      posicao = i;
      break;
    }
  }

  if (posicao == -1)
  {
    printf("❌ Valor %d não encontrado na lista!\n", valor);
    return;
  }

  // Remover usando a função de remover por posição
  for (int i = posicao; i < l->quantidade - 1; i++)
  {
    l->vetor[i] = l->vetor[i + 1];
  }
  l->quantidade--;
  printf("✅ Valor %d removido com sucesso!\n", valor);
}

// ============================================================================
// 6. BUSCAR ELEMENTO
// ============================================================================

int buscar_elemento(Lista *l, int valor)
{
  for (int i = 0; i < l->quantidade; i++)
  {
    if (l->vetor[i] == valor)
    {
      return i; // Retorna a posição
    }
  }
  return -1; // Não encontrado
}

// ============================================================================
// 7. LIBERTAR MEMÓRIA
// ============================================================================

void liberar_lista(Lista *l)
{
  free(l->vetor);
  free(l);
}

// ============================================================================
// 8. MENU INTERATIVO
// ============================================================================

void exibir_menu()
{
  printf("\n");
  printf("╔════════════════════════════════════════════╗\n");
  printf("║    OPERAÇÕES COM LISTAS - MENU PRÁTICO    ║\n");
  printf("╠════════════════════════════════════════════╣\n");
  printf("║ 1. Listar elementos                       ║\n");
  printf("║ 2. Contar elementos                       ║\n");
  printf("║ 3. Inserir no final                       ║\n");
  printf("║ 4. Inserir no início                      ║\n");
  printf("║ 5. Inserir em posição específica          ║\n");
  printf("║ 6. Remover do final                       ║\n");
  printf("║ 7. Remover do início                      ║\n");
  printf("║ 8. Remover de posição específica          ║\n");
  printf("║ 9. Remover por valor                      ║\n");
  printf("║ 10. Buscar elemento                       ║\n");
  printf("║ 0. Sair                                   ║\n");
  printf("╚════════════════════════════════════════════╝\n");
  printf("Escolha uma opção: ");
}

// ============================================================================
// 9. MAIN - PROGRAMA PRINCIPAL
// ============================================================================

int main()
{
  printf("\n🚀 BEM-VINDO AO PROGRAMA DE OPERAÇÕES COM LISTAS!\n");

  int capacidade;
  printf("\nDigite a capacidade máxima da lista: ");
  scanf("%d", &capacidade);

  Lista *lista = criar_lista(capacidade);
  int opcao;

  while (1)
  {
    exibir_menu();
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      listar_elementos(lista);
      break;

    case 2:
    {
      int total = contar_elementos(lista);
      printf("\n📊 Total de elementos: %d/%d\n", total, capacidade);
      break;
    }

    case 3:
    {
      int valor;
      printf("\nDigite o valor a inserir: ");
      scanf("%d", &valor);
      inserir_final(lista, valor);
      break;
    }

    case 4:
    {
      int valor;
      printf("\nDigite o valor a inserir: ");
      scanf("%d", &valor);
      inserir_inicio(lista, valor);
      break;
    }

    case 5:
    {
      int valor, posicao;
      printf("\nDigite o valor a inserir: ");
      scanf("%d", &valor);
      printf("Digite a posição (0 a %d): ", contar_elementos(lista));
      scanf("%d", &posicao);
      inserir_posicao(lista, valor, posicao);
      break;
    }

    case 6:
      remover_final(lista);
      break;

    case 7:
      remover_inicio(lista);
      break;

    case 8:
    {
      int posicao;
      printf("\nDigite a posição a remover (0 a %d): ", contar_elementos(lista) - 1);
      scanf("%d", &posicao);
      remover_posicao(lista, posicao);
      break;
    }

    case 9:
    {
      int valor;
      printf("\nDigite o valor a remover: ");
      scanf("%d", &valor);
      remover_valor(lista, valor);
      break;
    }

    case 10:
    {
      int valor;
      printf("\nDigite o valor a buscar: ");
      scanf("%d", &valor);
      int pos = buscar_elemento(lista, valor);
      if (pos != -1)
      {
        printf("✅ Valor %d encontrado na posição %d!\n", valor, pos);
      }
      else
      {
        printf("❌ Valor %d não encontrado!\n", valor);
      }
      break;
    }

    case 0:
      printf("\n👋 Encerrando programa...\n");
      liberar_lista(lista);
      return 0;

    default:
      printf("❌ Opção inválida! Tente novamente.\n");
    }
  }

  return 0;
}
