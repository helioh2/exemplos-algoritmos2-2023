#include <stdlib.h>


/**
 * No pior caso, ela demoraria mais ou menos n "processamentos"/iterações (O(n))
 * No melhor caso, seria O(1)
 * No caso médio, n/2 iterações
*/
int busca_linear(int* vetor, int elemento, int n) {
    for (int i = 0; i < n; i++) {
        if (vetor[i] == elemento) {
            return i;
        }
    }
    return -1;  // não encontrei
}



int main() {

    int n = 6;
    int v1[] = {10, 30, 45, 23, 100, 90};

    printf("%d\n", busca_linear(v1, 300, 6));

    return 0;
}