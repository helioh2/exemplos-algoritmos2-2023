#include "utils.h"

typedef struct {
    int matricula;
    char nome[30];
    float n1,n2,n3;
} Aluno;

//Definição do tipo Node (nó)
typedef struct {
    int valor;
    Node* prox;
} Node; 

typedef Node* Lista;  // Definição de lista como um ponteiro para um nó


Lista* cria_lista() {
    Lista* li = (Lista*) mallocc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}