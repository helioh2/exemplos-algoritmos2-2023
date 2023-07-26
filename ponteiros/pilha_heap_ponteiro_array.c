#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// SIMULAR EM: https://pythontutor.com/c.html


void alteraPrimeiroPorReferencia(int* vetor) {
    vetor[0] = 500;
    // *vetor = 500; // também funciona, pois o ponteiro vetor aponta para o inicio do array
}

void alteraSegundoPorReferencia(int* vetor) {
    //vetor[1] = 500;
    *(vetor+1) = 500; // também funciona, pois o ponteiro vetor aponta para o inicio do array
}

int main() {
  
    // CRIANDO ESTRUTURAS SOMENTE NA PILHA:

    int x[] = {10,20,30,40}; 
    
    printf("Conteudo do x: %d\n", x);

    alteraPrimeiroPorReferencia(x);  // Arrays em C são sempre passados por referência. Ou seja, a variável é um ponteiro. Aqui está passando o endereço da pilha (no frame main) onde se encontra o vetor

    printf("Endereco de x dentro da pilha (main): %d\n", &x);
    
    printf("Conteudo de x apos alteração por referencia: %d\n", x);
    

  
    // CRIANDO NA HEAP E USANDO PONTEIRO:
  
    int* z = malloc(4*sizeof(int));  // z é um ponteiro para um array de int alocado dinamicamente na heap, e não o próprio int
    z[0] = 100; z[1] = 200; z[2] = 300; z[3] = 400;  

    alteraPrimeiroPorReferencia(z); //passa ponteiro z por referência, alterando o objeto na heap
    
    alteraSegundoPorReferencia(z);
    
    printf("Endereco do ponteiro z: %d\n", z);
    
    printf("Conteudo de z: %d\n", *z);

    
  return 0;
}