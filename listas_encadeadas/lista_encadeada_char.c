

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 
#include <stdbool.h> 


/**
 * Representa um nó
*/
struct node {
    char conteudo;  //é possivel definir outros tipos
    struct node* prox;
};

/**
 * Define o tipo Node para nó
*/
typedef struct node Node;

struct lista {
    Node* cabeca;  // ponteiro para o primeiro nó da lista
};

typedef struct lista Lista;


/**
 * criar_lista_vazia: void -> Lista*
 * Cria uma lista vazia
*/
Lista* criar_lista_vazia() {
    Lista* nova_lista = malloc(sizeof(Lista)); //cria lista na memória e retorna o endereço para essa lista
    if (nova_lista == NULL) {
        exit(EXIT_FAILURE);  // deu ruim, sem espaço na memória
    }

    nova_lista->cabeca = NULL;

    return nova_lista;
}


Node* criar_node(char valor){
    Node* novo = malloc(sizeof(Node));  // criando novo nó
    if (novo == NULL) exit(EXIT_FAILURE);

    novo->conteudo = valor;
    novo->prox = NULL;

    return novo;
}


bool lista_vazia(Lista* lista) {
    return (lista->cabeca == NULL);  // valor booleana
}

/**
 * adicionar_no_inicio: Lista*, Aluno -> void
 * Adicionar o elemento no início da lista.
*/
// Prototipo bobo (stub)
void adicionar_no_inicio(Lista* lista, char valor){

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return;
    }

    // Criar novo nó
    Node* novo = criar_node(valor);

    novo->prox = lista->cabeca;
    lista->cabeca = novo;
}

/**
 * remover_do_inicio: Lista* -> void
 * Remover o primeiro elemento da lista
*/
void remover_do_inicio(Lista* lista) {

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return;
    }

    if (lista_vazia(lista)){
        printf("ERRO: Imposível remover de lista vazia");
        return;
    }
    //else: lista não vazia
    Node* cabeca_anterior = lista->cabeca;
    lista->cabeca = lista->cabeca->prox;

    free(cabeca_anterior); // libera (desaloca) o espaço ocupado pelo o que era primeiro

}




/**
 * adicionar_no_final: Lista*, Aluno -> void
 * Adiciona o novo aluno no final da lista
*/
void adicionar_no_final(Lista* lista, char valor) {

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return;
    }

    if (lista_vazia(lista)) { 
        adicionar_no_inicio(lista, valor);
    }
    //else (nao vazia)

    // CRIAÇÃO DO NOVO NÓ
    Node* novo = criar_node(valor);

    //PERCORRER A LISTA ATÉ CHEGAR AO FINAL

    Node* atual = lista->cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    // atual aqui será o último
    atual->prox = novo;

}


/**
 * remover_do_final: Lista* -> void
 * Remove do final da lista
*/
void remover_do_final(Lista* lista) {

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return;
    }

    if (lista_vazia(lista)) {
        printf("ERRO: Impossível remover de uma lista vazia");
        return;
    }
    if (lista->cabeca->prox == NULL) {  // lista com um único elemento
        remover_do_inicio(lista);
        return;
    }

    // Percorrer a lista até o penúltimo
    Node* atual = lista->cabeca;
    while (atual->prox->prox != NULL) {
        atual = atual->prox;
    }

    // após o while, estará no antepenultim,o nó
    free(atual->prox);
    atual->prox = NULL;

}


/**
 * adicionar_no_meio: Lista*, Aluno, char -> void
 * Adiciona um aluno na lista na posição indicada
*/
void adicionar_no_meio(Lista* lista, char valor, int posicao) {

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return;
    }

    if (lista_vazia(lista) && (posicao > 0)) { 
        printf("ERRO: Tentando inserir em uma posição fora da lista\n");
        return;
    }
    if (posicao == 0) {
        adicionar_no_inicio(lista, valor);
        return;
    }

    Node* novo = criar_node(valor);

    // Percorrer a lista até a posição desejada ou até acabar a lista
    Node* atual = lista->cabeca;
    int i = 0;   //indice atual no loop
    while ((i < posicao-1) && atual != NULL) {  // para quando i == posicao-1 ou atual == NULL
        atual = atual->prox;
        i++;  // i += 1  ;  i = i + 1
    }

    if (atual == NULL) {  // passou do final da lista
        printf("ERRO: Tentando inserir em uma posição fora da lista\n");
    } else {
        // após o while, estarei no elemento (posicao - 1)
        novo->prox = atual->prox;  // faz o novo nó apontar para o próximo do atual
        atual->prox = novo;  // faz o nó atual apontar para o novo
    }

}


/**
 * print_lista_recursiva: Node* -> void
 * Imprime a lista de forma recursiva.
*/
void print_lista_recursiva(Node* node) {

    if (node == NULL){ // CASO BASE (CONDIÇÃO DE PARADA)
        return;
    }
    //else  (!= NULL)
    printf("---------------\n");
    printf("Valor: %d\n", node->conteudo);
    printf("---------------\n\n");

    print_lista_recursiva(node->prox);

}


/**
 * print_lista: Lista* -> void
 * Imprime a lista de forma iterativa.
*/
void print_lista(Lista* lista) {

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return;
    }

    Node* atual = lista->cabeca;
    while (atual != NULL) {  // o atual existe?
        printf("---------------\n");
        printf("Valor: %c\n", atual->conteudo);
        printf("---------------\n\n");

        atual = atual->prox;
    }

}

/**
 * junta: Node* -> Node*
 * Cria uma nova lista a partir de uma lista
 * adicionando-se um novo valor
 * na cabeça da lista
 * Esta é uma versão funcional (pura) de adicionar_no_inicio,
 * pois adiciona um novo elemento no inicio,
 * mas criando uma nova lista, sem alterar a existente
 * 
 * VER APLICAÇÃO NO ARQUIVO recursao/aritmetica_naturais
*/
Node* junta(char valor, Node* lista) {
    Node* novo = criar_node(valor);
    novo->prox = lista;
    return novo;
}

/**
 * Retorna somente a "cauda" da lista, isto é, todos os
 * itens menos o primeiro
*/
Node* resto(Node* lista) {
    return lista->prox;
}