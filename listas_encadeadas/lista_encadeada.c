

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 
#include <stdbool.h> 

// typedef struct node {
//     int conteudo;  //é possivel definir outros tipos
//     Node* prox;
// } Node;


typedef struct {
   char nome[15];  //campo
   int matricula;  // outro campo
   float n1;   // campo
   float n2;  // campo
} Aluno;


/**
 * Representa um nó
*/
struct node {
    Aluno conteudo;  //é possivel definir outros tipos
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


Node* criar_node(Aluno aluno){
    Node* novo = malloc(sizeof(Node));  // criando novo nó
    if (novo == NULL) exit(EXIT_FAILURE);

    novo->conteudo = aluno;
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
void adicionar_no_inicio(Lista* lista, Aluno aluno){

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return;
    }

    // Criar novo nó
    Node* novo = criar_node(aluno);

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
void adicionar_no_final(Lista* lista, Aluno aluno) {

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return;
    }

    if (lista_vazia(lista)) { 
        adicionar_no_inicio(lista, aluno);
    }
    //else (nao vazia)

    // CRIAÇÃO DO NOVO NÓ
    Node* novo = criar_node(aluno);

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
 * adicionar_no_meio: Lista*, Aluno, int -> void
 * Adiciona um aluno na lista na posição indicada
*/
void adicionar_no_meio(Lista* lista, Aluno aluno, int posicao) {

    if (lista == NULL) {
        printf("ERRO: Lista inválida");
        return;
    }

    if (lista_vazia(lista) && (posicao > 0)) { 
        printf("ERRO: Tentando inserir em uma posição fora da lista\n");
        return;
    }
    if (posicao == 0) {
        adicionar_no_inicio(lista, aluno);
        return;
    }

    Node* novo = criar_node(aluno);

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
    printf("Nome: %s\n", node->conteudo.nome);
    printf("Matricula: %d\n", node->conteudo.matricula);
    printf("Nota 1: %f\n", node->conteudo.n1);
    printf("Nota 2: %f\n", node->conteudo.n2);
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
        printf("Nome: %s\n", atual->conteudo.nome);
        printf("Matricula: %d\n", atual->conteudo.matricula);
        printf("Nota 1: %f\n", atual->conteudo.n1);
        printf("Nota 2: %f\n", atual->conteudo.n2);
        printf("---------------\n\n");

        atual = atual->prox;
    }

}


int main() {

    // TESTES

    Lista* lista = criar_lista_vazia();
    assert(lista != NULL); 

    Aluno aluno1;
    strcpy(aluno1.nome, "Fulano");
    aluno1.matricula = 20234747;
    aluno1.n1 = 8.0;
    aluno1.n2 = 9.2;

    Aluno aluno2 = {"Beltrano", "202346464", 4.5, 9.1};

    adicionar_no_inicio(lista, aluno1); //uso da função

    printf("%s\n", lista->cabeca->conteudo.nome); 
    assert(strcmp(lista->cabeca->conteudo.nome, "Fulano") == 0); // strcmp retorna 0 quando igual

    adicionar_no_inicio(lista, aluno2);

    assert(strcmp(lista->cabeca->conteudo.nome, "Beltrano") == 0);
    assert(strcmp(lista->cabeca->prox->conteudo.nome, "Fulano") == 0);

    Aluno aluno3 = {"Maria", 20227689, 7.2, 10.0};
    adicionar_no_inicio(lista, aluno3);

    // print_lista(lista);

    // Removendo o primeiro:
    remover_do_inicio(lista);

    // Verificação
    assert(strcmp(lista->cabeca->conteudo.nome, "Beltrano") == 0);

    // print_lista_recursiva(lista->cabeca);

    // Adicionar no final

    adicionar_no_final(lista, aluno3);

    remover_do_final(lista);

    adicionar_no_meio(lista, aluno3, 1); // adiciona Maria na segunda posição (indice 1)

    print_lista_recursiva(lista->cabeca);

}

























//TESTES:
int brincando_com_a_estrutura() {

    // BRINCANDO COM A ESTRUTURA
    
    Aluno* aluno1 = malloc(sizeof(Aluno));
    Aluno* aluno2 = malloc(sizeof(Aluno));
    Aluno* aluno3 = malloc(sizeof(Aluno));
    
    strcpy(aluno1->nome, "Fulano");
    aluno1->matricula = 20234646;
    aluno1->n1 = 8.5;
    aluno1->n2 = 7.2;
    
    strcpy(aluno2->nome, "Beltrano");
    aluno2->matricula = 20234647;
    aluno2->n1 = 9.2;
    aluno2->n2 = 8.2;

    strcpy(aluno3->nome, "Ciclana");
    aluno3->matricula = 20234648;
    aluno3->n1 = 7.1;
    aluno3->n2 = 9.9;
    
    
    

     // PRIMEIRO
    Lista* lista = malloc(sizeof(Lista));
    lista->cabeca = NULL;  // LISTA VAZIA
    
    
    Node* node1 = malloc(sizeof(Node));  // alocando na heap e pegando o ponteiro

    lista->cabeca = node1;

    node1->conteudo = *aluno1;

    Node* node2 = malloc(sizeof(Node));

    node2->conteudo = *aluno2;

    node1->prox = node2;
    
    Node* node3 = malloc(sizeof(Node));
    
    node3->conteudo = *aluno3;
    
    node2->prox = node3;
    
    node3->prox = NULL;
    
    // PRINTAR O PRIMEIRO NÓ DA LISTA
    printf("Primeiro nome: %s\n", lista->cabeca->conteudo.nome);
    printf("Primeira matricula: %d\n", lista->cabeca->conteudo.matricula);
    
    // PRINTAR O SEGUNDO NÓ DA LISTA
    printf("Segundo nome: %s\n", lista->cabeca->prox->conteudo.nome);

    // PRINTAR O TERCEIRO NÓ DA LISTA
    printf("Terceiro nome:  %s\n", lista->cabeca->prox->prox->conteudo.nome);




    return 0;
}