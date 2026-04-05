#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========== SIMULADOR DE ESTACIONAMENTO 2.0 ==========  

typedef struct{
  int id;
  char placa[20];
  int hora_entrada;
  int hora_saida;
} no_veiculo;

typedef struct historico{
  no_veiculo *veiculo;
  struct historico *prox;
} historico_node;

typedef struct{
  historico_node *cabeca;
} historico_estacionamento;


typedef struct{
  no_veiculo **vagas;
  int capacidade;
  int ocupadas;
  historico_estacionamento *historico;
  int proximo_id;
} estacionamento;

// ===== PROTÓTIPOS =====
estacionamento *criar_estacionamento(int capacidade);
int estacionar(estacionamento *e, const char *placa, int hora);
void listar_estacionados(estacionamento *e);
void sair_estacionamento(estacionamento *e, int vaga, int hora_saida);
void listar_historico(estacionamento *e);
void liberar_estacionamento(estacionamento *e);

// ===== IMPLEMENTAÇÃO =====

estacionamento *criar_estacionamento(int capacidade){
    estacionamento *e = malloc(sizeof(estacionamento));
    e->capacidade = capacidade;
    e->ocupadas = 0;
    e->proximo_id = 1;

    e->vagas = calloc(capacidade, sizeof(no_veiculo*));

    e->historico = malloc(sizeof(historico_estacionamento));
    e->historico->cabeca = NULL;

    return e;
}

int estacionar(estacionamento *e, const char *placa, int hora){
    for(int i = 0; i < e->capacidade; i++){
        if(e->vagas[i] == NULL){
            no_veiculo *v = malloc(sizeof(no_veiculo));
            v->id = e->proximo_id++;
            strcpy(v->placa, placa);
            v->hora_entrada = hora;
            v->hora_saida = -1;

            e->vagas[i] = v;
            e->ocupadas++;

            printf("Carro %s estacionado na vaga %d\n", placa, i);
            return 1;
        }
    }
    printf("Estacionamento cheio!\n");
    return 0;
}

void listar_estacionados(estacionamento *e){
    for(int i = 0; i < e->capacidade; i++){
        if(e->vagas[i] != NULL){
            printf("Vaga %d: %s (entrada: %d)\n",
                   i,
                   e->vagas[i]->placa,
                   e->vagas[i]->hora_entrada);
        }
    }
}

void sair_estacionamento(estacionamento *e, int vaga, int hora_saida){
    if(e->vagas[vaga] == NULL){
        printf("Vaga vazia!\n");
        return;
    }

    no_veiculo *v = e->vagas[vaga];
    v->hora_saida = hora_saida;

    // adiciona no histórico
    historico_node *novo = malloc(sizeof(historico_node));
    novo->veiculo = v;
    novo->prox = e->historico->cabeca;
    e->historico->cabeca = novo;

    e->vagas[vaga] = NULL;
    e->ocupadas--;

    printf("Carro %s saiu da vaga %d\n", v->placa, vaga);
}

void listar_historico(estacionamento *e){
    historico_node *atual = e->historico->cabeca;

    while(atual != NULL){
        no_veiculo *v = atual->veiculo;
        printf("Placa: %s | Entrada: %d | Saída: %d\n",
               v->placa, v->hora_entrada, v->hora_saida);
        atual = atual->prox;
    }
}

void liberar_estacionamento(estacionamento *e){
    for(int i = 0; i < e->capacidade; i++){
        if(e->vagas[i] != NULL){
            free(e->vagas[i]);
        }
    }

    free(e->vagas);

    historico_node *atual = e->historico->cabeca;
    while(atual != NULL){
        historico_node *temp = atual;
        atual = atual->prox;
        free(temp->veiculo);
        free(temp);
    }

    free(e->historico);
    free(e);
}

// ===== MAIN =====

int main(){

  printf("========== SIMULADOR DE ESTACIONAMENTO ==========\n\n");

  estacionamento *e = criar_estacionamento(10);

  estacionar(e, "ABC-1234", 8);
  estacionar(e, "DEF-5678", 9);
  estacionar(e, "GHI-9012", 10);

  printf("\nCarros atualmente estacionados:\n");
  listar_estacionados(e);

  sair_estacionamento(e, 0, 12);

  printf("\nCarros atualmente estacionados após saída:\n");
  listar_estacionados(e);

  printf("\nHistórico de saídas:\n");
  listar_historico(e);

  liberar_estacionamento(e);

  printf("\nPrograma finalizado!\n");
  return 0;
}