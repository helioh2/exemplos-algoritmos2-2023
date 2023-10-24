/**
 * Calcule a potenciação de forma recursiva
*/

#include <assert.h>


/**
 * Faz a exponenciação da base x no expoente n
*/
int pot(int x, int n) {
    if (n == 0) {
        return 1;
    }
    // else
    return x * pot(x, n-1);
}


int pot_it(int x, int n) {

    int res = 1;

    for (int i = 0; i < n; i++) {
        res *= x;
    }

    return res;
}


int main() {

    assert(pot_it(2,0) == 1);
    assert(pot_it(2,1) == 2);
    assert(pot_it(2,2) == 4);
    assert(pot_it(2,3) == 8);

    printf("%d", pot_it(2,10));

    return -1;
}