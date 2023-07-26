
#include <stdio.h>



int main() {
    int n = 4;
    int numeros[] = {25, 50, 75, 100};
    printf("Acessado elemento na posição 0: %d\n", numeros[0]);
    printf("Acessado elemento na última posição: %d\n", numeros[n-1]);


    int nums[5];  // criando um vetor com 5 posições. Não é possível mudar o tamanho

    // Adicionando elementos:
    nums[0] = 25;
    nums[1] = 50;
    nums[2] = 75;
    nums[3] = 100;
    nums[4] = 125;

    printf("Printando os elementos de nums com for:\n");
    for (int i = 0; i <= 4; i++) {
        printf("%d\n", nums[i]);
    }

    printf("Multiplicando todos os númros de nums por 2 e printando resultado:\n");
    for (int i = 0; i <= 4; i++) {
        nums[i] = nums[i]*2;
    }
    for (int i = 0; i <= 4; i++) {
        printf("%d\n", nums[i]);
    }


    printf("Criando uma lista contendo todos os números pares de 0 até 20:\n");
    int pares[11];  //terá o 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 (total de 11)
    for (int i = 0; i <= 10; i++){
        pares[i] = i*2;
    }
    for (int i = 0; i <= 10; i++) {
        printf("%d\n", pares[i]);
    }

    return 0;
    
}

