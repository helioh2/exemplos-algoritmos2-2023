#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lista_duplamente_encadeada_deque.c"


/**
 * O primeiro elemento da fila está na posição p e o último na posição u-1.
*/
struct fila {
    Lista* lista;
};
typedef struct fila Fila;


Fila* cria_fila_vazia(int capacidade_inicial) {
    Fila* nova_fila = malloc(sizeof(Fila));
    if (nova_fila == NULL) exit(EXIT_FAILURE);
    nova_fila->lista = cria_lista();

    return nova_fila;
}

bool fila_vazia(Fila* fila) {
    return fila->lista->tamanho == 0;
}

int inicio_fila(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("ERRO: Fila vazia");
        return -1;
    }

    return fila->lista->cabeca->conteudo;

}

int fim_fila(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("ERRO: Fila vazia");
        return -1;
    }

    return fila->lista->cauda->conteudo;
}


bool adicionar(Fila* fila, int valor) {
    insere_no_final(fila->lista, valor);
    return true;
}

int remover(Fila* fila) {
    int removido = inicio_fila(fila);
    remove_do_inicio(fila->lista);
    return removido;
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