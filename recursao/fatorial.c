/**
 * Calcule o fatorial de um número
 * 
 * Exemplos:
 * 
 * 1! = 1  = 1   ##caso base
 * 2! = 2*1 = 2 = 2*1! = 2 * (2-1)!
 * 3! = 3*2*1 = 6 = 3*2! = 3 * (3-1)!
 * 4! = 4*3*2*1 = 24 = 4*3! = 4 * (4-1)!
 * 5! = 5*4*3*2*1 = 5*24 = 5*4! = 5 * (5-1)!
*/

#include <stdlib.h>
#include <assert.h>

/**
 * fat: int -> int
*/
int fat(int x) {
    if (x == 1) {  // CASO BASE
        return 1;
    }
    //else
    int res = x * fat(x-1);  
    return res;
    // a cada chamada recursiva, diminui o tamanho da entrada
}


int main() {

    assert(fat(1) == 1);
    assert(fat(2) == 2);
    assert(fat(5) == 120);

    printf("%d", fat(15));

    return EXIT_SUCCESS;
}

