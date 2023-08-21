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
    Aluno dados;
    struct reg* prox;
};

typedef struct reg Node; 

/**
 * Definição de struct e tipo lista como uma struct que possui o ponteiro para o primeiro nó
*/
struct lista {
    Node* cabeca;
};

typedef struct lista Lista;


/**
 * Cria e retorna um ponteiro para uma lista. 
*/
Lista* cria_lista() {
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL)
        li->cabeca = NULL;
    return li;
}


bool lista_vazia(Lista* li) {
    return li == NULL || li->cabeca == NULL;
}


/**
 * Recebe um ponteiro para uma lista e insere o novo aluno 'al' no início da lista.
 * Para isso, é necessário criar um novo nó (Node), fazer o novo nó apontar
 * para o primeiro nó (li->cabeca) e por fim fazer a lista (li) apontar para o novo
 * nó como o primeiro nó da lista.
*/
bool insere_no_inicio(Lista* li, Aluno al){
    if (li == NULL) {
        return false;
    }
    Node* novo = malloc(sizeof(Node));
    if(novo == NULL)
        return false;  // não foi possível alocar espaço (memória cheia)
    novo->dados = al;
    novo->prox = li->cabeca;  //faz o novo nó apontar para o atual nó cabeça da lista
    li->cabeca = novo;   // faz a lista apontar para o novo nó como o primeiro nó da lista
    return true;
}

/**
 * Recebe um ponteiro para uma lista (o ponteiro para o ponteiro do primeiro nó),
 * e insere o novo aluno 'al' no final da lista
 * Para isso, é necessário criar um novo nó (Node), iterar até o final
 * da lista e inserir o novo nós após o último nó.
*/
bool insere_no_final(Lista* li, Aluno al){
    if (li == NULL)
        return false;

    Node* novo = malloc(sizeof(Node));
    
    if (novo == NULL)
        return false;
    
    novo->dados = al;
    novo->prox = NULL;  // será o último nó, logo apontará para null

    if (li->cabeca == NULL) { // lista vazia: insere no início
        li->cabeca = novo;
        return true;
    }

    // faz a iteração na lista até o último nó
    Node* aux;  // ponteiro para o nó da iteração
    aux = li->cabeca;  // inicializa aux com o primeiro nó da lista
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    // quando sair do while, aux estará apontando para o último nó
    aux->prox = novo;
    
    return true;
}


bool insere_no_meio(Lista* li, Aluno al, int posicao){
    if (lista_vazia(li)) {
        return false;
    }

    if (posicao == 0) {
        return insere_no_inicio(li, al);
    }

    Node* novo = malloc(sizeof(Node));
    novo->dados = al;

    Node* atual = li->cabeca; 
    
    for (int i = 1; i < posicao; i++) {
        atual = atual->prox;
        if (atual == NULL) { // acabou a lista
            return false;
        }
    }

    Node* aux = atual->prox;
    atual->prox = novo;
    novo->prox = aux;

    return true;
}


bool remove_do_inicio(Lista* li){
    if (lista_vazia(li)) {
        return false;
    }

    Node* node = li->cabeca;
    li->cabeca = node->prox; // faz a lista apontar para o segundo elemento
    free(node);
    return true;
}


bool remove_do_final(Lista* li){
    if (lista_vazia(li)) {
        return false;
    }

    Node *anterior, *atual = li->cabeca; //cria dois ponteiros para nós, ambos apontando para o inicio da lista
    
    // itera na lista guardando o ponteiro do nó anterior
    while(atual->prox != NULL){
        anterior = atual;
        atual = atual->prox;
    }

    // ao final do while, teremos ant apontando para o penúltimo nó, e node apontando para o último

    if(atual == li->cabeca) { //se o nó aponta para o primeiro
        li->cabeca = atual->prox;
    } else {
        anterior->prox = atual->prox; // faz o penúltimo apontar para o prox do último (NULL)
    }
    free(atual);
    return true;
}



/**
 * Calcula o tamanho da lista. Para isso, itera-se por todos os nós
 * da lista incrementando-se uma variável cont.
 * TODO (por fazer): modificar o struct para armazenar o tamanho da lista,
 * assim como as funções de inserção e remoção,
 * de modo a não precisar contar todas as vezes. 
*/
int tamanho_lista(Lista* li){
    if (li == NULL)
        return 0;
    int cont = 0;
    Node* node = li->cabeca;
    while(node != NULL){
        cont++;
        node = node->prox;
    }
    return cont;
}


void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Node* node = li->cabeca;
    while(node != NULL){
        printf("Matricula: %d\n",node->dados.matricula);
        printf("Nome: %s\n",node->dados.nome);
        printf("Nota: %f\n",node->dados.nota);
        printf("-------------------------------\n");

        node = node->prox;
    }
}



// int main() {
//     //TESTES

//     Aluno al;
//     Aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
//                          {4,"Ricardo",7.5,8.7,6.8},
//                          {1,"Bianca",9.7,6.7,8.4},
//                          {3,"Ana",5.7,6.1,7.4}};
//     Lista* li = cria_lista();
//     printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

//     int i;
//     for(i=0; i < 4; i++)
//         insere_no_inicio(li,a[i]);

//     imprime_lista(li);
//     printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));

//     for(i=0; i < 4; i++){
//         remove_do_inicio(li);
//         imprime_lista(li);
//         printf("\n Tamanho: %d\n\n\n",tamanho_lista(li));
//     }

//     for(i=0; i < 4; i++)
//         insere_no_final(li,a[i]);
//     imprime_lista(li);

//     libera_lista(li);

//     return 0;
// }



int main() {
    //TESTES DE INSERCAO NO MEIO

    Aluno al;
    Aluno a[4] = {{2,"Andre",9.5},
                         {4,"Ricardo",7.5},
                         {1,"Bianca",9.7},
                         {3,"Ana",5.7}};
    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for (i=0; i < 4; i++)
        insere_no_inicio(li,a[i]);

    imprime_lista(li);
    printf("\n\nTamanho: %d\n",tamanho_lista(li));

    Aluno novo = {5, "Fulano", 8.5};

    insere_no_meio(li, novo, 2);
    
    imprime_lista(li);

    return 0;
}