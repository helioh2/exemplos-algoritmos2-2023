#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lista_encadeada.c"

struct pilha {
    Lista* lista;
    int n;
};
typedef struct pilha Pilha;

Pilha* cria_pilha_vazia(int capacidade_inicial) {
    Pilha* nova_pilha = malloc(sizeof(Pilha));
    if (nova_pilha == NULL) exit(EXIT_FAILURE);
    nova_pilha->lista = criar_lista_vazia();
    nova_pilha->n = 0;

    return nova_pilha;
}


bool pilha_vazia(Pilha* pilha) {
    return pilha->n == 0;
}

int topo(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("ERRO: Pilha vazia");
        return -1;
    }
    return pilha->lista->cabeca->conteudo;
}

void empilha(Pilha* pilha, int valor ) {
    adicionar_no_inicio(pilha->lista, valor);
    pilha->n ++;
}

int desempilha(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("ERRO: Pilha vazia");
        return -1;
    }
    int valor_removido = topo(pilha);
    remover_do_inicio(pilha->lista);
    pilha->n--;
    return valor_removido;
}


int main() {

    Pilha* pilha1 = cria_pilha_vazia(5);

    assert(pilha_vazia(pilha1));

    empilha(pilha1, 10);

    assert(!pilha_vazia(pilha1));

    empilha(pilha1, 20);
    empilha(pilha1, 30);

    printf("%d\n", topo(pilha1));
    assert(topo(pilha1) == 30);

    int x = desempilha(pilha1);
    assert(x == 30);

    printf("%d\n", topo(pilha1));
    assert(topo(pilha1) == 20);

    empilha(pilha1, 40);
    empilha(pilha1, 50);
    empilha(pilha1, 60);
    empilha(pilha1, 70);
    empilha(pilha1, 80);
    empilha(pilha1, 90);

    printf("%d\n", topo(pilha1));
    assert(topo(pilha1) == 90);

    return EXIT_SUCCESS;
}