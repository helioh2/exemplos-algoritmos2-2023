/**
 * Adaptado de https://github.com/arbackes/Estrutura-de-Dados-em-C/blob/main/Lista%20Dinamica%20Encadeada/ListaDinEncad.c
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * Definição do struct e tipo Aluno, que representa os dados dos alunos que
 * desejamos armazenar na lista.
*/
typedef struct {
    int matricula;
    char nome[30];
    float nota;
} Aluno;

/**
 * Definição do struct e tipo Node, representando um nó contendo os dados e o ponteiro
 * para o próximo nó.
*/
struct reg {
    Aluno conteudo;
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


Node* criar_node(Aluno aluno) {
    Node* novo = malloc(sizeof(Node));
    if(novo == NULL) {
        exit(EXIT_FAILURE);  // não foi possível alocar espaço (memória cheia)
    }
    novo->conteudo = aluno;
    novo->prox, novo->ante = NULL;
    return novo;
    
}


/**
 * Recebe um ponteiro para uma lista e insere o novo aluno 'aluno' no início da lista.
 * Para isso, é necessário criar um novo nó (Node), fazer o novo nó apontar
 * para o primeiro nó (lista->cabeca) e por fim fazer a lista (lista) apontar para o novo
 * nó como o primeiro nó da lista.
*/
bool insere_no_inicio(Lista* lista, Aluno aluno){
    if (lista == NULL) {
        printf("ERRO: Lista inválida\n");
        return false;
    }
    Node* novo = criar_node(aluno);
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
 * e insere o novo aluno 'aluno' no final da lista
*/
bool insere_no_final(Lista* lista, Aluno aluno){
    if (lista == NULL) {
        printf("ERRO: Lista inválida\n");
        return false;
    }

    if (lista_vazia(lista)) { // lista vazia: insere no início
        return insere_no_inicio(lista, aluno);
    }

    Node* novo = criar_node(aluno);
    novo->ante = lista->cauda;  // faz o anterior do node apontar para a atual cauda
    novo->ante->prox = novo;  //faz o prox da atual cauda atual apontar para novo

    lista->cauda = novo;  //faz a o novo se tornar a cauda atual
    
    lista->tamanho++;

    return true;
}


bool insere_no_meio(Lista* lista, Aluno aluno, int posicao){

    if (lista == NULL) {
        printf("ERRO: Lista inválida\n");
        return false;
    }

    if (posicao == 0) {
        return insere_no_inicio(lista, aluno);
    }

    if (posicao == lista->tamanho) {
        return insere_no_final(lista, aluno);
    }

    if(lista_vazia(lista) || posicao > (lista->tamanho)) {
        printf("ERRO: Tentando inserir em uma posição fora da lista\n");
        return false;
    }

    Node* novo = criar_node(aluno);

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
        printf("Matricula: %d\n",node->conteudo.matricula);
        printf("Nome: %s\n",node->conteudo.nome);
        printf("Nota: %f %f %f\n",node->conteudo.nota);
        printf("-------------------------------\n");

        node = node->prox;
    }
}


int main() {
    //TESTES DE INSERCAO NO MEIO

    Aluno aluno;
    Aluno a[4] = {{2,"Andre",9.5},
                         {4,"Ricardo",7.5},
                         {1,"Bianca",9.7},
                         {3,"Ana",5.7}};
    Lista* lista = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(lista));

    int i;
    for (i=0; i < 4; i++)
        insere_no_inicio(lista,a[i]);

    imprime_lista(lista);
    printf("\n\nTamanho: %d\n",tamanho_lista(lista));

    Aluno novo = {5, "Fulano", 8.5};

    insere_no_meio(lista, novo, 2);
    
    imprime_lista(lista);

    return 0;
}