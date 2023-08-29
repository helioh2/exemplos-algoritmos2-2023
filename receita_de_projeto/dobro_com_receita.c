/**
 * Problema: crie uma função que retorne o dobro 
 * de um número.
*/

#include <assert.h>
#include <stdio.h>


/**
 * dobro: float -> float  [assinatura]
 * Calcula e retorna o dobro do valor passado
*/
// prototipo bobo (stub)
float dobro(float numero) {
    return numero*2;
}


int main() {

    //TESTES:

    // TESTE VISUAL:
    float res1 = dobro(10);  //chamando a função dobro
    printf("%f", res1);

    //TESTE AUTOMATIZADO:
    assert(dobro(10) == 10*2);  // VERIFICA SE AO CHAMAR DOBRO PASSANDO 10, ME RETORNA 20
    assert(dobro(0) == 0*2);
    // assert(dobro(4.28) == 4.28*2);  //TODO: Corrigir depois
    assert(dobro(20) == 40);

    return 0;
}

