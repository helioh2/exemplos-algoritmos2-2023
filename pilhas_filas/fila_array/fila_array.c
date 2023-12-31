#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "arrays.c"


/**
 * O primeiro elemento da fila está na posição p e o último na posição u-1.
*/
struct fila {
    int* vetor;
    int p;  // indice do primeiro elemento
    int u;  // indice do último elemento + 1
    int capacidade;
};
typedef struct fila Fila;


Fila* cria_fila_vazia(int capacidade_inicial) {
    Fila* nova_fila = malloc(sizeof(Fila));
    if (nova_fila == NULL) exit(EXIT_FAILURE);
    nova_fila->vetor = malloc(sizeof(int)*capacidade_inicial);
    if (nova_fila->vetor == NULL) exit(EXIT_FAILURE);

    nova_fila->p = 0;
    nova_fila->u = 0;
    nova_fila->capacidade = capacidade_inicial;

    return nova_fila;
}

bool fila_vazia(Fila* fila) {
    return fila->p == fila->u;
}

bool fila_cheia(Fila* fila) {
    return fila->u == fila->capacidade;
}

bool adicionar(Fila* fila, int valor) {
    if (fila_cheia(fila)) {
        printf("ERRO: Fila cheia");
        return false;
    }
    fila->vetor[fila->u] = valor;
    fila->u ++;
    return true;
}

int remover(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("ERRO: Fila vazia");
        return -1;
    }
    fila->p ++;
    return fila->vetor[fila->p - 1];
}


int inicio_fila(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("ERRO: Fila vazia");
        return -1;
    }

    return fila->vetor[fila->p];

}

int fim_fila(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("ERRO: Fila vazia");
        return -1;
    }

    return fila->vetor[fila->u - 1];  // final da fila em u-1
}


int main() {

    Fila* fila1 = cria_fila_vazia(5);

    assert(fila_vazia(fila1));

    adicionar(fila1, 10);

    assert(!fila_vazia(fila1));
    assert(inicio_fila(fila1) == 10);
    assert(fim_fila(fila1) == 10);

    adicionar(fila1, 20);
    adicionar(fila1, 30);

    assert(inicio_fila(fila1) == 10);
    assert(fim_fila(fila1) == 30);

    remover(fila1);

    assert(inicio_fila(fila1) == 20);
    assert(fim_fila(fila1) == 30);

    remover(fila1);

    assert(inicio_fila(fila1) == 30);
    assert(fim_fila(fila1) == 30);

    remover(fila1);

    assert(fila_vazia(fila1));

    adicionar(fila1, 10);
    adicionar(fila1, 20);
    assert(adicionar(fila1, 30) == false);
    // adicionar(fila1, 40);
    // adicionar(fila1, 50);
    // assert(adicionar(fila1, 60) == false);


    return EXIT_SUCCESS;
}