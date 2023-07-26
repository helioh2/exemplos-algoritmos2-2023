#include <stdio.h>
#include <stdbool.h>  // importando biblitorca para uso de booleanos

int main() {
    // criando variáveis booleanas
    bool programarEhDivertido = true;
    bool ficarDeExameEhBom = false;

    // imprimindo variáveis booleanas
    printf("%d\n", programarEhDivertido);   // Returns 1 (true)
    printf("%d\n", ficarDeExameEhBom);        // Returns 0 (false)


    if (programarEhDivertido) {
         printf("Programar é divertido!\n");
    }
    if (!ficarDeExameEhBom) {  // o operador not (não) é o ! (exclamação)
        printf("Ficar de exame não é bom!\n");
    }

    int x = 1;
    int y = 0;

    if (x) {
        printf("Entrou no if porque condição é diferente de 0!!\n");
    }
    if (y) {
        printf("Não entra nesse if pois y é igual a zero!!\n");
    }
    
    return 0;

}