#include <stdlib.h>
#include <string.h>

void incrementa(int *a)
{
    *a = *a + 1;
}

int main()
{

    char *ola;
    ola = malloc(sizeof(char) * 5); // aloca espaço para uma string de tamanho 4
    strcpy(ola, "Hello");

    int *x = malloc(sizeof(int));
    *x = 10;
    incrementa(x); // passagem por referência
    printf("Valor de x apos incrementa: %d", *x);

    int z = 10;
    // incrementa(z);  //dá erro, pois 'incrementa' recebe ponteiro para int
    incrementa(&z); // passagem por referência do endereço da variável dentro da pilha
    printf("Valor de x apos incrementa: %d", z);

    return 0;
}