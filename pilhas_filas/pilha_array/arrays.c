
#include <stdio.h>


int* redimensionar_vetor(int* vetor, int nova_capacidade) {
    vetor = realloc(vetor, sizeof(int)*nova_capacidade);
    if (vetor == NULL) {
        exit(EXIT_FAILURE);
    }
    return vetor;
}