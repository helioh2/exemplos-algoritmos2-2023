/**
 * Adaptado de https://github.com/arbackes/Estrutura-de-Dados-em-C/blob/main/Lista%20Dinamica%20Encadeada/ListaDinEncad.c
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/**
 * Definição do struct e tipo Node, representando um nó contendo os dados e o ponteiro
 * para o próximo nó.
*/
struct reg {
    int conteudo;
    struct reg* prox;
    struct reg* ante;
};

typedef struct reg Node; 

/**
 * Definição de struct e tipo lista como uma struct que possui o ponteiro para o primeiro nó
*/
struct lista {
    Node* cabeca;
    Node* cauda;
    int tamanho;
};

typedef struct lista Lista;


/**
 * Cria e retorna um ponteiro para uma lista. 
*/
Lista* cria_lista() {
    Lista* lista = malloc(sizeof(Lista));
    if(lista != NULL)
        lista->cabeca = NULL;
        lista->cauda = NULL;
        lista->tamanho = 0;
    return lista;
}


bool lista_vazia(Lista* lista) {
    return lista->cabeca == NULL;
}


Node* criar_node(int valor) {
    Node* novo = malloc(sizeof(Node));
    if(novo == NULL) {
        exit(EXIT_FAILURE);  // não foi possível alocar espaço (memória cheia)
    }
    novo->conteudo = valor;
    novo->prox, novo->ante = NULL;
    return novo;
    
}


/**
 * Recebe um ponteiro para uma lista e insere o novo valor 'valor' no início da lista.
 * Para isso, é necessário criar um novo nó (Node), fazer o novo nó apontar
 * para o primeiro nó (lista->cabeca) e por fim fazer a lista (lista) apontar para o novo
 * nó como o primeiro nó da lista.
*/
bool insere_no_inicio(Lista* lista, int valor){
    if (lista == NULL) {
        printf("ERRO: Lista inválida\n");
        return false;
    }
    Node* novo = criar_node(valor);
    novo->prox = lista->cabeca;  //faz o novo nó apontar para o atual nó cabeça da lista
    if (lista->cabeca != NULL){
        lista->cabeca->ante = novo;
    }
    lista->cabeca = novo;   // faz a cabeça da lista apontar para o novo nó como o primeiro nó da lista
    if (novo->prox == NULL) {
        lista->cauda = novo;  //faz a cauda também apontar para novo se só tiver um nó
    }
    lista->tamanho++;
    return true;
}

/**
 * Recebe um ponteiro para uma lista (o ponteiro para o ponteiro do primeiro nó),
 * e insere o novo valor 'valor' no final da lista
*/
bool insere_no_final(Lista* lista, int valor){
    if (lista == NULL) {
        printf("ERRO: Lista inválida\n");
        return false;
    }

    if (lista_vazia(lista)) { // lista vazia: insere no início
        return insere_no_inicio(lista, valor);
    }

    Node* novo = criar_node(valor);
    novo->ante = lista->cauda;  // faz o anterior do node apontar para a atual cauda
    novo->ante->prox = novo;  //faz o prox da atual cauda atual apontar para novo

    lista->cauda = novo;  //faz a o novo se tornar a cauda atual
    
    lista->tamanho++;

    return true;
}


bool insere_no_meio(Lista* lista, int valor, int posicao){

    if (lista == NULL) {
        printf("ERRO: Lista inválida\n");
        return false;
    }

    if (posicao == 0) {
        return insere_no_inicio(lista, valor);
    }

    if (posicao == lista->tamanho) {
        return insere_no_final(lista, valor);
    }

    if(lista_vazia(lista) || posicao > (lista->tamanho)) {
        printf("ERRO: Tentando inserir em uma posição fora da lista\n");
        return false;
    }

    Node* novo = criar_node(valor);

    Node* atual = lista->cabeca; 
    
    for (int i = 0; i < posicao - 1; i++) {
        if (atual == NULL) { // acabou a lista
            printf("ERRO: Tentando inserir em uma posição fora da lista\n");
            return false;
        }
        atual = atual->prox;
    }

    novo->prox = atual->prox;  // faz o novo nó apontar para o próximo do atual
    if (atual->prox != NULL) {
        atual->prox->ante = novo;  // faz o próximo do atual apontar (ante) para o novo
    }
    novo->ante = atual;   // faz o novo nó apontar (ante) para o atual
    atual->prox = novo;  // faz o nó atual apontar (prox) para o novo
    
    lista->tamanho++;

    return true;
}


bool remove_do_inicio(Lista* lista){

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return false;
    }

    if (lista_vazia(lista)) {
        printf("ERRO: Não é possível remover de lista vazia");
        return false;
    }

    Node* node = lista->cabeca;
    lista->cabeca = node->prox; // faz a lista apontar para o segundo elemento
    free(node);

    if (lista->cabeca == NULL) {
        lista->cauda = NULL;  // se lista ficou vazia, faz a cauda também apontar para NULL    
    }

    lista->tamanho--;
    
    return true;
}



bool remove_do_final(Lista* lista){

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return false;
    }

    if (lista_vazia(lista)) {
        printf("ERRO: Não é possível remover de lista vazia");
        return false;
    }

    Node* node = lista->cauda;
    lista->cauda = node->ante; // faz a cauda apontar para o penultimo elemento
    free(node);

    if (lista->cauda == NULL) {
        lista->cabeca = NULL;  // se lista ficou vazia, faz a cabeca também apontar para NULL    
    }

    lista->tamanho--;

    return true;
}


int tamanho_lista(Lista* lista){
    return lista->tamanho;
}


void imprime_lista(Lista* lista){
    if(lista == NULL)
        return;
    Node* node = lista->cabeca;
    while(node != NULL){
        printf("-------------------------------\n");
        printf("Valor: %d\n",node->conteudo);
        printf("-------------------------------\n");

        node = node->prox;
    }
}
