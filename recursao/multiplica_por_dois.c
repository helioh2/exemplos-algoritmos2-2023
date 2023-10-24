/**
 * Função que multiplica todos os elementos de um vetor por 2
 * de forma recursiva.
*/



void M2(int vetor[], int n) {
    if (n == 0) {
        return;  // cabô
    }
    //else
    vetor[n-1] = vetor[n-1] * 2;
    M2(vetor, n-1);
}


int main() {

    int n = 5;
    int v1[] = {10, 30, 50, 70, 90};

    M2(v1, n);

    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d, ", v1[i]);
    }
    printf("]");

    return 0;
}