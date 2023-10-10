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

int fib(int n) {
    if (n <= 2) {  // caso base
        return 1;
    }

    //else
    int res = fib(n-1) + fib(n-2);
    return res;
}

int main() {

    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(7) == 13);

    printf("%d", fib(500));

    // printf("%d", fib(500)); trava: muitas chamadas

    return 0;
}