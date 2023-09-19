#include <stdlib.h>
#include <stdio.h>

typedef struct {
    unsigned int horas;
    unsigned int minutos;
    unsigned int segundos;
} Relogio;


Relogio* cria_relogio (unsigned int horas, unsigned int minutos, unsigned int segundos){
    Relogio* novo = malloc(sizeof(Relogio));
    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }
    novo->horas = horas;
    novo-> minutos = minutos;
    novo->segundos = segundos;

    return novo;
}

void tick(Relogio* relogio){
    relogio->segundos = (relogio->segundos + 1) % 60;  // soma 1 e pega o resto da divisao por 60. Se der 60, volta para o zero automaticamente
    if (relogio->segundos == 0) { // ocorreu a virada do "ponteiro" dos segundos
        
        relogio->minutos = (relogio->minutos + 1) % 60;

        if (relogio->minutos == 0) { // ocorreu a virada do "ponteiro" dos minutos
            relogio->horas = (relogio->horas + 1) % 24;
        }
    }
}

int main (){

    Relogio* relogio = cria_relogio(23,59,0);

    for (int i = 0; i < 120; i++) {
        tick(relogio);
        printf("%d:%d:%d\n", relogio->horas, relogio->minutos, relogio->segundos);
    }

}