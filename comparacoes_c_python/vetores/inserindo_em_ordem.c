
#include <stdio.h>

/**
 * Adiciona o um valor dentro de um vetor na posição pos, deslocando-se os elementos
 * da posição pos em diante uma posição para frente
*/
void adicionar(int valor, int pos, int vetor[], int n){  // vetor é passado por referência (ponteiro)

    if (vetor[n-1] != 0){
        printf("ERRO: LISTA CHEIA\n");
        return;  // termina
    }
    // Deslocando os valores para frente
    for (int i = n-2; i >= pos; i--){  //começa no penúltimo e vai até pos, de traz pra frente
        vetor[i+1] = vetor[i];   // passa o de trás (i) para o da frente (i+1)
    }

    // Inserindo o valor na posição pos
    vetor[pos] = valor;
}

int main() {
    int n = 6;
    int numeros[] = {25, 75, 100, 125, 150, 0};

    // Gostaria de adicionar o valor 50, e manter os elementos na ordem correta
    // Para isso, preciso deslocar todos os elementos a partir da posição 1 para frente
    // e então inserir o valor 50 na posição 1
    adicionar(50, 1, numeros, n);

    printf("Printando o vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", numeros[i]);
    }

    return 0;
    
    
}

