
#include <stdio.h>

/* ESTRUTURA DO COMANDO FOR

Considerando uma variável de laço chamada i:
Estrutura do FOR em pseudocódigo (português):

para cada valor i entre INICIO e FIM com passo PASSO:
	... FAZ ALGUMA COISA


Em C, o for tem a seguinte estrutura genérica:

for (inicialização da variavel; condição de continuidade; incremento) {
  // corpo do código a ser executado
}

Colocando em modelo similar ao pseudocódigo (com INICIO, FIM e PASSO):

// Considerando uma variável de laço chamada i:
for (int i = INICIO; i < FIM+1; i += PASSO) {
  // corpo do código a ser executado
}

*/

int main() {

    printf("Imprimindo todos os números de 0 a 20:\n");
    for (int i = 0; i < 21; i++) {  //ou: for (int i = 0; i < 21; i += 1)
        printf("%d\n", i);
    }

    printf("Imprimindo todos os números de 0 a 20, pulando de 2 em 2:\n");
    for (int i = 0; i < 21; i += 2) {
        printf("%d\n", i);
    }


    printf("Imprimindo os números de 20 a 0, de traz pra frente:\n");
    for (int i = 20; i >= 0; i -= 1) {  // ou: (int i = 20; i >= 0; i--)
        printf("%d\n", i);
    }

    return 0;
}


