/**
 * Um ponteiro pode ser usado para dizer a uma fun¸c˜ao onde ela deve depositar o resultado
de seus c´alculos. Escreva uma fun¸c˜ao hm que converta minutos em horas-e-minutos. A
fun¸c˜ao recebe um inteiro mnts e os endere¸cos de duas vari´aveis inteiras, digamos h e m,
e atribui valores a essas vari´aveis de modo que m seja menor que 60 e que 60*h + m
seja igual a mnts. Escreva tamb´em uma fun¸c˜ao main que use a fun¸c˜ao hm.
*/

#include <assert.h>
#include <stdio.h>

/**
 * Converte de minutos para "horas e minutos". A hora e o minuto
 * resultantes são guardados nas variáveis h  e m, que são ponteiros.
*/
void minutos_to_horas_minutos(int mnts, int* h, int* m) {
    *h = mnts / 60;  // setando o valor da variável para qual h aponta
    *m = mnts % 60;  // setando o valor da variável para qual m aponta
}

int main() {

    int mins = 150;  // entrada da função
    int horas, minutos;  //variáveis em que serão guardados o resultado da funcao

    minutos_to_horas_minutos(150, &horas, &minutos);  //endereços das variaveis 'horas' e 'minutos' é passado por referência

    printf("%d:%d\n", horas, minutos);

    assert(horas == 2);
    assert(minutos = 30);

    return 0;
}



