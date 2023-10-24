/**
 * Calcule o somatório de um vetor recursivamente
*/

#include <assert.h>

// prototipo
int somatorio(int* vetor, int n) {
    
    if (n == 0) {   // n==0 significa que o vetor que eu tenho que considerar é vazio
        return 0;
    }

    // else
    int res = vetor[n-1] + somatorio(vetor, n-1);

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