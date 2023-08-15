
#include <stdlib.h>
#include <stdio.h>


int main() {

    int vetor[5]; // declara a existência do vetor na memória, mas não preenche com dados

    // LENDO VALORES DO ARRAY A PARTIR DO TECLADO
    for (int i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", vetor + i);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", *(vetor+i)*2);
    }


    return EXIT_SUCCESS;
}