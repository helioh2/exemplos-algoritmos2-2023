#include <stdio.h>


int main(){
    
    int animal;
    scanf("%d", &animal);

    switch (animal) {
        case 1:
            printf("AU AU");
            break;
        case 2:
            printf("MIAU");
            break;
        case 3:
            printf("MÉÉ");
            break;
        default:
            printf("Que animal o que, eu não sou animal não");
    }

    return 0;
}