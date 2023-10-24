#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para construir uma lista encadeada a partir de um vetor
Node* construirLista(int* V, int n) {
    if (n == 0) {
        return NULL;
    }

    Node* head = malloc(sizeof(Node));
    head->data = V[0];
    head->next = NULL;
    Node* atual = head;

    for (int i = 1; i < n; i++) {
        Node* novoNo = malloc(sizeof(Node));
        novoNo->data = V[i];
        novoNo->next = NULL;
        atual->next = novoNo;
        atual = novoNo;
    }

    return head;
}

// Função para imprimir a lista
void imprimirLista(Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

// Função para liberar a memória alocada para a lista
void liberarLista(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int V[] = {4, 1, 5, 9, 13, 26};
    int n = sizeof(V) / sizeof(V[0]);

    Node* lista = construirLista(V, n);

    printf("Lista construída a partir do vetor:\n");
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}