
#include <stdio.h>
#include <string.h>


int busca(char* valor, char **vetor, int n) {
    
    for (int i = 0; i < n; i++) {
        if (strcmp(vetor[i], valor) == 0) {
            return i;
        }
    }

    return -1;
}


int main() {
    // EXPLICAÇÃO SOBRE ARRAY (VETOR) DE STRINGS: https://www.geeksforgeeks.org/array-of-strings-in-c/

    int n = 5;
    char *listaDeCompras[] = {"arroz", "feijao", "batata", "macarrao", "carne"};

    printf("Procurando batata na lista:\n");

    int indice = busca("batata", listaDeCompras, n);

    printf("Resultado da busca: %d\n", indice);
    
    return 0;

}

