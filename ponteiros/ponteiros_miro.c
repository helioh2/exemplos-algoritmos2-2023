#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void incrementa(int *a)
{
    *a = *a + 1;
}

int main()
{

    char *ola;
    ola = malloc(sizeof(char) * 6); // aloca espaço para uma string de tamanho 5
    strcpy(ola, "Hello");

    int *x = malloc(sizeof(int));
    *x = 10;
    incrementa(x); // passagem por referência
    printf("Valor de x apos incrementa: %d\n", *x);

    int z = 10;
    // incrementa(z);  //dá erro, pois 'incrementa' recebe ponteiro para int
    incrementa(&z); // passagem por referência do endereço da variável dentro da pilha
    printf("Valor de z apos incrementa: %d\n", z);
}