/**
 * Faça um programa que leia dois valores inteiros e chame uma funcao que 
 * receba estes 2 valores de entrada e retorne o maior valor na primeira 
 * variavel e o menor valor na segunda variavel. Escreva o conteudo 
 * das 2 variaveis na tela
*/

#include <assert.h>
#include <stdio.h>

void menor_maior(int* a, int* b) {
    if (*a < *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {

    int x = 10;
    int y = 20;

    menor_maior(&x, &y);

    printf("%d, %d", x, y);

    assert(x == 20);
    assert(y == 10);

    menor_maior(&x, &y);

    assert(x == 20);
    assert(y == 10);

    return 0;
}



