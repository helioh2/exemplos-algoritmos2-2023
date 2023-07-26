
#include <stdio.h>

/**
 * Remove o valor dentro de um vetor na posição pos, deslocando-se os elementos
 * da posição pos em diante uma posição para trás, deixando um valor 0 após a última posição
*/
void remover(int pos, int vetor[], int n){  // vetor é passado por referência (ponteiro)

    // Deslocando os valores para trás
    for (int i = pos; i < n-1; i++){ // começa em pos e vai até o penultimo elemento
        
        if (vetor[pos] == 0) {  // se encontrar vazio (0), nada mais a fazer
            return;   // cabou
        }
        vetor[i] = vetor[i+1];  // passa o da frente para o atual
    }

    // Inserindo o valor 0 na posição n-1
    vetor[n-1] = 0;
}

int main() {
    int n = 6;
    int numeros[] = {25, 50, 75, 100, 125, 150};

    // Gostaria de remover o valor 50, sem deixar "buracos" no vetor.
    // Para isso, preciso deslocar todos os elementos a partir da posição 1 para trás
    // e então inserir o valor 0 (nulo) na posição n-1
    remover(1, numeros, n);

    printf("Printando o vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", numeros[i]);
    }

    return 0;
    
    
}

