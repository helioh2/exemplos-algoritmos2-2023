#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void incrementa(int *a)
{
    for (int i = 0; i < 5; i++) {  //for (int i = 0; i < 5; i+=3)
      
      // *(a + i) = *(a + i) + 1;
      a[i] = a[i] + 1;
    }
}

int main()
{

    char* ola;
    ola = malloc(6*sizeof(char)); // aloca espaço para uma string de tamanho 5
    strcpy(ola, "Hello");

    int* x = malloc(sizeof(int)*5);
    *x = 10;
    x[0] = 20;
    x[1] = 30;
    x[2] = 40;
    x[3] = 50;
    x[4] = 60;
    incrementa(x); // passagem por referência
    printf("Valor de x apos incrementa: %d\n", *x);

    int y[5] = {20,30,40,50,60}; 
    
    y[2] = 70;
    
    y[3] = 90;
    
    *(y+4) = 100;

    int z = 10;
    // incrementa(z);  //dá erro, pois 'incrementa' recebe ponteiro para int
    incrementa(&z); // passagem por referência do endereço da variável dentro da pilha
    printf("Valor de z apos incrementa: %d\n", z);
}