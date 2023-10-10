/**
 * Calcule o somatório de um vetor recursivamente
*/

#include <assert.h>

// prototipo
int somatorio(int* vetor, int n) {
    return 0;
}


int main() {
    int n1 = 0;
    int v1[] = {}; //vetor vazio
    int n2 = 5;
    int v2[] = {1,2,3,4,5};

    assert(somatorio(v1, n1) == 0);
    assert(somatorio(v2, n2) == 1+2+3+4+5);

    return -1;
}