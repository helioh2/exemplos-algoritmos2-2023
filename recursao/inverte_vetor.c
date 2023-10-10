/**
 * Inverter vetor usando recursão
*/

#include <assert.h>


void inverte(int* vetor, int esq, int dir) {

} 


int main() {

    int n1 = 0;
    int v1[] = {};
    int n2 = 1;
    int v2[] = {10};

    int n3 = 5;
    int v3 = {1,2,3,4,5};

    inverte(v1, 0, n1-1); // -> {}
    inverte(v2, 0, n2-1); // -> {10}
    inverte(v3, 0, n3-1); // -> {5,4,3,2,1}


    return -1;
}