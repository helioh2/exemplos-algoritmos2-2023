#include <stdio.h>

int main() {
    printf("Hello World!\n");


    int myNum = 15;
    printf("%d\n", myNum);  // Imprime 15. Note que é necessário incluir %d para imprimir um int

    char palavra[] = "banana";  // cria string, que é um vetor de char (caracter)
    printf("%s\n", &palavra);  // note que é necessário colocar %s para imprimir uma string. Também é necessário colocar um & antes da variável (somente para o caso de string)

    float pi = 3.1415;
    printf("%f\n", pi);  // note que é necessário colocar %f para imprimir um float


    // Lendo entrada do teclado:
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);  //necessário colocar o & antes da variavel quando é int ou float, pois é necessário passar o ponteiro para o int/float
    printf("O número digitado foi: %d\n", numero);

    char texto[30];  // Quando se cria string sem valor predefinido, é necessário definir o tamanho máximo da string
    printf("Digite uma palavra: ");
    scanf("%s", texto);  //não colocar o & antes da variavel quando é string, pois a string (char[]) há é um ponteiro
    printf("A palavra digitada foi: %s\n", texto);



    return 0;
}