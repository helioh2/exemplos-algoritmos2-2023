/**
 * Inverte uma lista encadeada
*/

/**
 * EXERCÍCIO: Defina uma função não recursiva para inversão de lista
 * que utilize uma pilha auxiliar!!!
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

    if (node->prox == NULL) {
        *ultimo = node;  
        // Encontrou o último, então seta o parâmetro passado 
        // por referência 'ultimo'.
        // Como se trata de um mesmo endereço que foi utilizado
        // por todas as chamadas recursivas, o primeiro chamador da
        // função 'inverte_nodes' terá acesso a ele.
        return node;
        // Retorna o nó para que seja ligado ao anterior na pilha
        // de chamadas
    }

    Node* proximo = inverte_nodes(node->prox, ultimo);
    proximo->prox = node;
    return node;
}


void inverte_lista(Lista* lista) {
    Node* ultimo = NULL;
    inverte_nodes(lista->cabeca, &ultimo); // passando ultimo por referência (endereço)
    lista->cabeca->prox = NULL;
    lista->cabeca = ultimo;
}


int main() {


    Node* node_lista1 = cons('a', cons('b', cons('c', cons('d', NULL))));
    Lista* lista1 = criar_lista_vazia();
    lista1->cabeca = node_lista1;

    inverte_lista(lista1);

    print_lista(lista1);

    return -1;
}