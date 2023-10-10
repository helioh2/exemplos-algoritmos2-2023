/**
 * Calcula o n-ésimo número da sequência de fibonacci
 * 
 * Exemplos:
 * 
 * fib(1) = 1
 * fib(2) = 1
 * fib(3) = 1 + 1 = 2 = fib(2) + fib(1)
 * fib(4) = 2 + 1 = 3 = fib(3) + fib(2)
 * fib(5) = 3 + 2 = 5 = fib(4) + fib(3)
 * fib(6) = 5 + 3 = 8 = fib(5) + fib(4)
 * fib(7) = 8 + 5 = 13 = fib(6) + fib(5)
*/

#include <assert.h>
#include <stdio.h>

long int fib(long int n) {

    int a = 1;  //penultimo

    printf("%d\n", a);

    if (n == 1) return 1;

    int b = 1; //ultimo

    printf("%d\n", b);
    
    if (n == 2) return 1;

    int cont = 2;
    while (cont < n) {
        int b_ant = b;
        b = a + b;
        a = b_ant;
        printf("%d\n", b);
        cont++;
    }

    return b;
}

int main() {

    // assert(fib(1) == 1);
    // assert(fib(2) == 1);
    // assert(fib(3) == 2);
    // assert(fib(7) == 13);

    printf("%d", fib(40));


    return 0;
}