#include <stdio.h>
#include <stdlib.h>

// ============================================================================

typedef struct{
  int *vetor;
  int tamanho;
} Lista;


Lista* criar_lista(int tamanho){
  Lista *l = (Lista*) malloc(sizeof(Lista));
  l->vetor = (int*) malloc(tamanho * sizeof(int));
  l->tamanho = tamanho;
  return l;
}

void preencher_lista(Lista *l){
  for(int i = 0; i < l->tamanho; i++){
    printf("Digite o elemento %d: ", i + 1);
    scanf("%d", &l->vetor[i]);
  }
}

void imprimir_lista(Lista *l){
  printf("Elementos da lista: ");
  for(int i = 0; i < l->tamanho; i++){
    printf("%d ", l->vetor[i]);
  }
  printf("\n");
}

void liberar_lista(Lista *l){
  free(l->vetor);
  free(l);
}

// ============================================================================

int main(){
  int tamanho;

  printf("Digite o tamanho da lista: ");
  scanf("%d", &tamanho);

  Lista *minha_lista = criar_lista(tamanho);
  preencher_lista(minha_lista);
  imprimir_lista(minha_lista);
  liberar_lista(minha_lista);

  return 0;
}
