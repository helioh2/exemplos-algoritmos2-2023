/**
 * Encontra o menor valor em um vetor
*/
#include <assert.h>


/**
 * Função recursiva que encontra o menor valor tal que
 * cada chamada recursiva decremente o valor de n.
 * Assim, a primeira chamada pergunta qual o mínimo em 
 * um vetor[0..n-1], e a cada chamada recursiva
 * pergunta qual o menor entre vetor[n-1] (último),
 * e minimo(vetor[0..n-2])
 * 
 * 
 * Exemplo:
 * minimo([2,4,1,7], 4)
 *  --> 7 < minimo([2,4,1], 3)?
 *           --> 1 < minimo([2,4], 2)?
 *                      --> 4 < minimo([2], 1)?  (CASO BASE!!)
 *                                  retorna 2
 *                          4 < 2? false
 *                              retorna 2
 *               1 < 2? true
 *                  retorna 1
 *      7 < 1? false
 *          retorna 1
 *  fim
 *                 
*/
int minimo(int* vetor, int n) {

    if (n == 1) {  // CASO BASE (quando há um único elemento, este elemento sempre será o mínimo)
        return vetor[n-1];
    }

    if (vetor[n-1] < minimo(vetor, n-1)) {
        return vetor[n-1];
    } 

}

/**
 * Função recursiva que encontra o menor valor tal que
 * cada chamada recursiva incrementa o valor de i 
 * (que deve valer 0 na chamada inicial).
 * Assim, a primeira chamada pergunta qual o mínimo em 
 * um vetor[0..n-1], e a cada chamada recursiva
 * pergunta qual o menor entre vetor[i] e minimo(vetor[i..n-1])
 * 
 * 
 * Exemplo:
 * minimo2([2,1,4,7], 0, 4)
 *  --> 2 < minimo2([1,4,7], 1, 4)?
 *           --> 1 < minimo2([4,7], 2, 4)?
 *                      --> 4 < minimo2([7], 3, 4)?  (CASO BASE!!)
 *                                  retorna 7
 *                          4 < 7? true
 *                              retorna 4
 *               1 < 4? true
 *                  retorna 1
 *      2 < 1? false
 *          retorna 1
 *  fim
 *                 
*/
int minimo2(int* vetor, int i, int n) {

    if (i == n-1) {  // CASO BASE (quando há um único elemento, este elemento sempre será o mínimo)
        return vetor[i];
    }

    if (vetor[i] < minimo2(vetor, i+1, n)) {
        return vetor[i];
    } 

}


int main() {

    int v1[] = {2,1,5,7};
    assert(minimo(v1, 4) == 1);
    assert(minimo2(v1, 0, 4) == 1);
   

    return -1;
}