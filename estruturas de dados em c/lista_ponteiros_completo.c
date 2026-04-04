#include <stdio.h>
#include <stdlib.h>

// ========== ESTRUTURA DE NÓ PARA LISTA ENCADEADA ==========
// Cada nó contém um valor e apontadores para próximo (e anterior em lista dupla)
typedef struct no {
    int valor;
    struct no *proximo;  // Aponta para o próximo nó (linear)
} no;

// ========== ESTRUTURA DE NÓ PARA LISTA CIRCULAR ==========
// Lista circular: o último nó aponta para o primeiro
typedef struct no_circular {
    int valor;
    struct no_circular *proximo;
} no_circular;

// ========== FUNÇÕES PARA LISTA ENCADEADA SIMPLES/LINEAR ==========

// Função para criar um novo nó
no *criar_no(int valor) {
    no *novo = (no *)malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return NULL;
    }
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

// Função para inserir no INÍCIO da lista
no *inserir_inicio(no *cabeca, int valor) {
    no *novo = criar_no(valor);
    if (novo == NULL) return cabeca;
    
    novo->proximo = cabeca;
    return novo;  // O novo nó vira a cabeça
}

// Função para inserir no FINAL da lista
no *inserir_fim(no *cabeca, int valor) {
    no *novo = criar_no(valor);
    if (novo == NULL) return cabeca;
    
    // Se a lista está vazia
    if (cabeca == NULL) {
        return novo;
    }
    
    // Procura o último nó
    no *atual = cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
    // Insere no final
    atual->proximo = novo;
    return cabeca;
}

// Função para EXIBIR a lista
void exibir_lista(no *cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    printf("Lista: ");
    no *atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para REMOVER um elemento
no *remover_elemento(no *cabeca, int valor) {
    if (cabeca == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }
    
    // Se o elemento está no início
    if (cabeca->valor == valor) {
        no *temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
        printf("Elemento %d removido do início!\n", valor);
        return cabeca;
    }
    
    // Procura o elemento na lista
    no *atual = cabeca;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor) {
            no *temp = atual->proximo;
            atual->proximo = temp->proximo;
            free(temp);
            printf("Elemento %d removido!\n", valor);
            return cabeca;
        }
        atual = atual->proximo;
    }
    
    printf("Elemento %d não encontrado!\n", valor);
    return cabeca;
}

// Função para LIBERAR a memória da lista
void liberar_lista(no *cabeca) {
    no *atual = cabeca;
    while (atual != NULL) {
        no *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

// ========== FUNÇÕES PARA LISTA ENCADEADA CIRCULAR ==========

// Função para criar um novo nó circular
no_circular *criar_no_circular(int valor) {
    no_circular *novo = (no_circular *)malloc(sizeof(no_circular));
    if (novo == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return NULL;
    }
    novo->valor = valor;
    novo->proximo = novo;  // Aponta para si mesmo inicialmente
    return novo;
}

// Função para inserir na lista circular
no_circular *inserir_circular(no_circular *cabeca, int valor) {
    no_circular *novo = criar_no_circular(valor);
    if (novo == NULL) return cabeca;
    
    // Se a lista está vazia
    if (cabeca == NULL) {
        return novo;
    }
    
    // Procura o último nó (aquele cujo próximo é a cabeça)
    no_circular *atual = cabeca;
    while (atual->proximo != cabeca) {
        atual = atual->proximo;
    }
    
    // Insere entre o último e o primeiro
    novo->proximo = cabeca;
    atual->proximo = novo;
    
    return cabeca;
}

// Função para exibir lista CIRCULAR (com limite para evitar loop infinito)
void exibir_lista_circular(no_circular *cabeca) {
    if (cabeca == NULL) {
        printf("Lista circular vazia!\n");
        return;
    }
    
    printf("Lista circular: ");
    no_circular *atual = cabeca;
    int contador = 0;
    int limite = 100;  // Proteção contra loops infinitos
    
    do {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
        contador++;
    } while (atual != cabeca && contador < limite);
    
    printf("(volta ao início)\n");
}

// Função para liberar lista circular
void liberar_lista_circular(no_circular *cabeca) {
    if (cabeca == NULL) return;
    
    no_circular *atual = cabeca;
    no_circular *primeiro = cabeca;
    
    do {
        no_circular *temp = atual;
        atual = atual->proximo;
        free(temp);
    } while (atual != primeiro);
}

// ========== PROGRAMA PRINCIPAL ==========
int main(int argc, char const *argv[]) {
    printf("=== LISTA ENCADEADA LINEAR ===\n\n");
    
    // Criando uma lista linear
    no *lista = NULL;
    
    // Inserindo elementos
    lista = inserir_fim(lista, 10);
    lista = inserir_fim(lista, 20);
    lista = inserir_fim(lista, 30);
    lista = inserir_inicio(lista, 5);
    
    exibir_lista(lista);
    
    // Removendo um elemento
    lista = remover_elemento(lista, 20);
    exibir_lista(lista);
    
    // Limpando memória
    liberar_lista(lista);
    
    printf("\n=== LISTA ENCADEADA CIRCULAR ===\n\n");
    
    // Criando uma lista circular
    no_circular *lista_circ = NULL;
    
    // Inserindo elementos
    lista_circ = inserir_circular(lista_circ, 100);
    lista_circ = inserir_circular(lista_circ, 200);
    lista_circ = inserir_circular(lista_circ, 300);
    lista_circ = inserir_circular(lista_circ, 400);
    
    exibir_lista_circular(lista_circ);
    
    // Limpando memória
    liberar_lista_circular(lista_circ);
    
    printf("\nPrograma finalizado!\n");
    return 0;
}
