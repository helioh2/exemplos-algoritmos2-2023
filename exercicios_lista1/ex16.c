/**
 * Deteccao de overflow. Escreva uma funcao booleana que receba unsigned ints n e m e
decida (true ou false) se a adicao de n e m produz overflow. Repita o exercicio supondo
que n e m sao do tipo int
*/

#include <stdbool.h>
#include <limits.h>
#include <assert.h>

bool adicao_resulta_em_overflow(unsigned a, unsigned b) {
    return a + b < a || a + b < b;  // || é o operador lógico "or" ("ou")
    // EXPLICAÇÃO: overflow ocorre quando vc soma e passa do tamanho máximo
    // do tipo. Por exemplo, o último número representável por um unsigned int
    // é 2**32-1 = 4294967295. Se somarmos 1 a esse número, voltamos ao número 0,
    // pois não há como representar um número maior que 4294967295 com 32 bits.
    // Logo, para detectar esse overflow, bastaria somar os dois números (operandos)
    // e verificar se o resultado da soma é menor que os próprios operandos.
}

int main() {

    //TESTES
    assert(adicao_resulta_em_overflow(10,20) == false);
    assert(adicao_resulta_em_overflow(4294967295, 1) == true);
    assert(adicao_resulta_em_overflow(UINT_MAX, 1) == true);
    assert(adicao_resulta_em_overflow(UINT_MAX, 2) == true);
    assert(adicao_resulta_em_overflow(UINT_MAX-10, UINT_MAX) == true);
    assert(adicao_resulta_em_overflow(UINT_MAX-10, UINT_MAX-10) == true);

    return 0;
}