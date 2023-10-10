/**
 * Inverte uma lista encadeada de modo iterativo usando pilha auxiliar
*/


#include <stdlib.h>
#include <stdio.h>
#include "../listas_encadeadas/lista_encadeada_char.c"


/**
 * Inverte os nós de uma lista encadeada a partir de um primeiro
 * nó 'node'. A função deve também ter como saída o último nó,
 * que deverá se tornar o primeiro na nova lista. Portanto,
 * passa-se por parâmetro a referência a um ponteiro para o ultimo nó 
 * (inicialmente NULL), que deverá ser preenchido quando o 
 * último elemento for encontrado.
*/
Node* inverte_nodes(Node* node, Node** ultimo) {

    Node* atual = node;
    Node** pilha = malloc(10*sizeof(Node*)); //problema: só inverte no máximo 10 elementos. Solução: usar uma pilha encadeada com conteúdo do tipo Node*
    int topo = 0;

    while (atual->prox != NULL) {
        pilha[topo] = atual; //empilha
        topo++;
        atual = atual->prox;
    }
    *ultimo = atual;

    while (topo > 0) {
        atual->prox = pilha[topo-1]; //desempilha
        topo--;
        atual = atual->prox;  
    }

    return atual;
}


void inverte_lista(Lista* lista) {
    Node* ultimo = NULL;
    inverte_nodes(lista->cabeca, &ultimo); // passando ultimo por referência (endereço)
    lista->cabeca->prox = NULL;
    lista->cabeca = ultimo;
}


int main() {


    Node* node_lista1 = junta('a', junta('b', junta('c', junta('d', NULL))));
    Lista* lista1 = criar_lista_vazia();
    lista1->cabeca = node_lista1;

    inverte_lista(lista1);

    print_lista(lista1);

    return -1;
}