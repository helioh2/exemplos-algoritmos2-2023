#include <stdlib.h>
#include <stdbool.h>

typedef int Aluno;


struct reg {
    Aluno dados;
    struct reg* prox;
};

typedef struct reg Node; 


struct lista {
    Node* cabeca;
};

typedef struct lista Lista;


Lista* cria_lista() {
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL)
        li->cabeca = NULL;
    return li;
}


bool insere_no_inicio(Lista* li, Aluno al){
    if (li == NULL) {
        return false;
    }
    Node* novo = malloc(sizeof(Node));
    if(novo == NULL)
        return false;  
    novo->dados = al;
    novo->prox = li->cabeca; 
    li->cabeca = novo;   
    return true;
}

bool insere_no_final(Lista* li, Aluno al){
    if (li == NULL)
        return false;

    Node* novo = malloc(sizeof(Node));
    
    if (novo == NULL)
        return false;
    
    novo->dados = al;
    novo->prox = NULL;  

    if (li->cabeca == NULL) {
        li->cabeca = novo;
        return true;
    }


    Node* aux;  
    aux = li->cabeca;  
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    
    aux->prox = novo;
    
    return true;
}


bool insere_no_meio(Lista* li, Aluno al, int posicao){
    if(li == NULL)
        return false;
    if(li->cabeca == NULL) //lista vazia
        return false;

    if (posicao == 0) {
        return insere_no_inicio(li, al);
    }

    Node* novo = malloc(sizeof(Node));
    novo->dados = al;

    Node* atual = li->cabeca; 
    
    for (int i = 1; i < posicao; i++) {
        atual = atual->prox;
        if (atual == NULL) { 
            return false;
        }
    }

    Node* aux = atual->prox;
    atual->prox = novo;
    novo->prox = aux;

    return true;
}


bool remove_do_final(Lista* li){
    if (li == NULL)
        return false;
    if (li->cabeca == NULL)
        return false;

    Node *anterior, *atual = li->cabeca; 
    
    while(atual->prox != NULL){
        anterior = atual;
        atual = atual->prox;
    }

   

    if(atual == li->cabeca) { 
        li->cabeca = atual->prox;
    } else {
        anterior->prox = atual->prox; 
    }
    free(atual);
    return true;
}



int main() {
  
    Aluno al;
    Aluno a[4] = {2,4,1,3};
    Lista* li = cria_lista();

    int i;
    for (i=0; i < 4; i++)
        insere_no_inicio(li,a[i]);

    Aluno novo = 5;

    insere_no_meio(li, novo, 2);
    

    return 0;
}