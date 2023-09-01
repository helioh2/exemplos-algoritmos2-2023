#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "arrays.c"

struct fila {
    int* vetor;
    int idx_inicio;
    int idx_final;
    int capacidade;
};
typedef struct fila Fila;

Fila* cria_fila_vazia(int capacidade_inicial) {
    Fila* nova_fila = malloc(sizeof(Fila));
    if (nova_fila == NULL) exit(EXIT_FAILURE);
    nova_fila->vetor = malloc(sizeof(int)*capacidade_inicial);
    if (nova_fila->vetor == NULL) exit(EXIT_FAILURE);

    nova_fila->idx_inicio = -1;
    nova_fila->idx_final = -1;
    nova_fila->capacidade = capacidade_inicial;

    return nova_fila;
}

bool fila_vazia(Fila* fila) {
    return fila->idx_inicio == -1 && 
}


int main() {



    return EXIT_SUCCESS;
}