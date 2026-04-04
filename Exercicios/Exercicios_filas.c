#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========== SIMULADOR DE ESTACIONAMENTO  2.0==========  


typedef struct{
  int id;
  char placa[20];
  int hora_entrada;
  int hora_saida;
} no_veiculo;

typedef struct{
  no_veiculo *cabeca;
} historico_estacionamento;

typedef struct{
  no_veiculo *inicio;
  no_veiculo *fim;
} fila_entrada;

typedef struct{
  no_veiculo **vagas;
  int capacidade;
  int ocupadas;
  historico_estacionamento *historico;
  int proximo_id;
} estacionamento;

// Funções auxiliares
estacionamento *criar_estacionamento(int capacidade);
int vagas_disponiveis(estacionamento *e);
int estacionar(estacionamento *e, const char *placa, int hora);
void listar_estacionados(estacionamento *e);
void sair_estacionamento(estacionamento *e, int vaga, int hora_saida);
void listar_historico(estacionamento *e);
void liberar_estacionamento(estacionamento *e);



int main()
{
  printf("========== SIMULADOR DE ESTACIONAMENTO ==========\n\n");

  // Criar estacionamento com capacidade para 10 vagas
  estacionamento *e = criar_estacionamento(10);

  // Estacionar alguns carros
  estacionar(e, "ABC-1234", 8);
  estacionar(e, "DEF-5678", 9);
  estacionar(e, "GHI-9012", 10);

  // Listar carros estacionados
  printf("\nCarros atualmente estacionados:\n");
  listar_estacionados(e);

  // Sair do estacionamento
  sair_estacionamento(e, 0, 12); // Carro na vaga 0 sai às 12h

  // tempo de permanência: 12 - 8 = 4 horas
  printf("\nTempo de permanência do carro na vaga 0: 4 horas\n");

  // Listar carros após saída
  printf("\nCarros atualmente estacionados após saída:\n");
  listar_estacionados(e);

  // Listar histórico de saídas
  printf("\nHistórico de saídas:\n");
  listar_historico(e);

  // Liberar memória
  liberar_estacionamento(e);

  printf("\nPrograma finalizado!\n");
  return 0;
}