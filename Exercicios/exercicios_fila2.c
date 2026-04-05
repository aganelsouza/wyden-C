#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========== EXERCÍCIO 2: BUSCA LINEAR ==========




int buscaLinear(int lista[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) {
            return i; // Retorna o índice onde encontrou o valor
        }
    }
    return -1; // Retorna -1 se não encontrou
} 
