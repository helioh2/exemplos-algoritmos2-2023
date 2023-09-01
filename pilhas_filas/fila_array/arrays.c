
#include <stdio.h>
#include <stdlib.h>

int* redimensionar_vetor(int* vetor, int nova_capacidade) {
    vetor = realloc(vetor, sizeof(int)*nova_capacidade);
    if (vetor == NULL) {
        exit(EXIT_FAILURE);
    }
    return vetor;
}


int* adicionar_no_final(int* vetor, int valor, int* n, int capacidade){ 
    if (*n >= capacidade) {
        vetor = redimensionar_vetor(vetor, capacidade*2);
    }    
    vetor[*n] = valor;
    *n++;
    return vetor;
}


int remove_do_final(int* vetor, int* n){ 
    if (*n == 0) {
        printf("ERRO: Vetor vazio");
    }
    int valor_removido = vetor[*n];
    vetor[*n] = NULL;
    *n--;
    return valor_removido;
}


int adicionar_no_inicio(int* vetor, int valor, int* n, int capacidade) {
    if (*n >= capacidade) {
        vetor = redimensionar_vetor(vetor, capacidade*2);
    }  

    
}



