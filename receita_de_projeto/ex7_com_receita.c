/**
 * PROBLEMA: Fa¸ca um programa que leia dois valores inteiros 
 * e chame uma fun¸c˜ao que receba estes
2 valores de entrada e retorne o maior valor na primeira vari´avel e o menor valor na
segunda vari´avel. Escreva o conte´udo das 2 vari´aveis na tela.
*/

#include <assert.h>
#include <stdio.h>

void troca(int* x, int* y){ 
   int temp;
   temp = *x; 
   *x = *y;  
   *y = temp;  
}


/**
 * coloca_maior_na_primeira_variavel: int*, int* -> muda os valores de entrada
 * Recebe duas variaveis e vou colocar o maior valor na primeira
*/
void coloca_maior_na_primeira_variavel(int* a, int* b) {
    // COmparar os valores das variaveis a e b
    if (*a < *b) {
        troca(a, b);
    }

}

// PROGRAMA PRINCIPAL
int main() {
    
    // TESTES:

    // Cenário 1: quando a primeira variavel é menor que a segunda
    int x = 10;
    int y = 20;

    //CHAMA A FUNÇÃO:
    coloca_maior_na_primeira_variavel(&x, &y);

    //VERIFICAR SE AS VARIAVEIS MUDARAM:
    assert(x == 20);
    assert(y == 10);

    // Cenário 2: quando a primeira variavel é maior que a segunda
    int m = 30;
    int n = 15;

    ////CHAMA A FUNÇÃO:
    coloca_maior_na_primeira_variavel(&m, &n);

    // VERIFICAR:
    assert(m == 30);
    assert(n == 15);

    return 0;
}


