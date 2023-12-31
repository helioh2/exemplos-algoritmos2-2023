#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "arrays.c"


/**
 * O primeiro elemento da fila está na posição inicio e o último na posição fim-1.
*/
struct fila {
    int* vetor;
    int inicio;  // indice do primeiro elemento
    int fim;  // indice do último elemento + 1
    int capacidade;
};
typedef struct fila Fila;


Fila* cria_fila_vazia(int capacidade_inicial) {
    Fila* nova_fila = malloc(sizeof(Fila));
    if (nova_fila == NULL) exit(EXIT_FAILURE);
    nova_fila->vetor = malloc(sizeof(int)*capacidade_inicial);
    if (nova_fila->vetor == NULL) exit(EXIT_FAILURE);

    nova_fila->inicio = 0;
    nova_fila->fim = 0;
    nova_fila->capacidade = capacidade_inicial;

    return nova_fila;
}

bool fila_vazia(Fila* fila) {
    return fila->inicio == fila->fim;
}

bool fila_cheia(Fila* fila) {
    return fila->fim == (fila->inicio - 1) % fila->capacidade;
}

void redimensionar_fila(Fila* fila) {
    int capacidade_antiga = fila->capacidade;
    fila->capacidade *= 2;
    int* novo_vetor = malloc(fila->capacidade * sizeof(int));
    
    int j = 0;
    int i = fila->inicio;
    while (i != fila->fim) {
        novo_vetor[j] = fila->vetor[i];
        i = (i + 1) % capacidade_antiga;
        j++;
    }

    fila->inicio = 0;
    fila->fim = capacidade_antiga - 1;
    fila->vetor = novo_vetor;
}

bool adicionar(Fila* fila, int valor) {

    if (fila_cheia(fila)) {
        redimensionar_fila(fila);
    }

    fila->vetor[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    return true;
}

int remover(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("ERRO: Fila vazia");
        return false;
    }
    int removido = fila->vetor[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    return removido;
}


int inicio_fila(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("ERRO: Fila vazia");
        return -1;
    }

    return fila->vetor[fila->inicio];

}

int fim_fila(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("ERRO: Fila vazia");
        return -1;
    }

    return fila->vetor[fila->fim - 1];  // final da fila em fim-1
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
    adicionar(fila1, 30);
    adicionar(fila1, 40);
    adicionar(fila1, 50);
    adicionar(fila1, 60);

    assert(inicio_fila(fila1) == 10);
    assert(fim_fila(fila1) == 60);


    return EXIT_SUCCESS;
}