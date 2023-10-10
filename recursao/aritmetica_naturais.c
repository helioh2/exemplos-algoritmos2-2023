/**
 * Aritmética de números naturais "na raça". Artimética de Peano
*/

#include <stdio.h>
#include "../listas_encadeadas/lista_encadeada_char.c"

/**
 * Representação de dados de um número natural:
*/

typedef Node Natural;
/**
 * Um Número Natural é uma lista encadeada, tal que:
 *  - Lista vazia (NULL) representa o número 0 (zero)
 *  - Cada item de uma lista não vazia representa uma unidade
*/


int natural_to_int(Natural* numero) {
    if (numero == NULL){
        return 0;
    }
    //else
    return 1 + natural_to_int(numero->prox);
} 

void print_natural(Natural* numero) {
    if (numero == NULL){
        printf("\n");
        return;
    }
    //else
    printf("%c", numero->conteudo);
    print_natural(numero->prox);
}

/**
 * soma: Natural* Natural* -> Natural*
 * Calcula a soma dos números naturais
 * 
 * Por exemplo:
 * 
 * soma(|||, ||) 
 *  --> junta(|, soma(||, ||))
 *     --> junta(|, soma(|, ||)) 
 *       --> junta(|, soma(0, ||))
 *          retorna ||
 *       retorna |||
 *     retorna ||||
 *  retorna |||||
 * 
*/
Natural* soma(Natural* n1, Natural* n2) {
    if (n1 == NULL) {  // caso base
        return n2;
    }
    //else
    return junta('|', soma(resto(n1), n2));
    // Explicação: retorna 1 + (n1 - 1) + n2
    // de forma que em algum momento, após
    // sucessivas chamadas recursivas,
    // n1 valerá 0 e cairá no "caso base".
    // Quando isso acontecer, todos os junta que foram
    // adicionados no decorrer das chamadas recursivas
    // serão atrelados a n2, completando-se assim
    // a soma

}


/**
 * subtrai: Natural*, Natural* -> Natural*
 * Realiza a subtração dos números
 * 
 * Exemplo:
 * 
 * subtrai(|||||, |||)
 *  -> subtrai(||||, ||)
 *      -> subtrai(|||, |)
 *          -> subtrai(||, 0)
 *              retorna ||
 *          retorna ||
 *      retorna ||
 *  retorna ||
*/
Natural* subtrai(Natural* n1, Natural* n2) {
    if (n2 == NULL) {  // caso base
        return n1;
    }
    if (n1 == NULL) {
        printf("ERRO: não é possível subtrair numero menor por número maior");
        return NULL;
    }
    //else
    return subtrai(resto(n1), resto(n2));
    // Explicação: a ideia é sucessivamente subtrair 1
    // de n1 e 1 de n2, até que n2 chegue a 0. Então, n1
    // será o resultado da subtração. Um erro é impresso
    // ao tentar subtrair um numero menor por um maior
}


/**
 * Natural*, Natural* -> Natural*
 * Multiplica dois numeros
 * 
 * Exemplo 1:
 * 
 * multiplica(||||, ||) ->
 *  soma(||, multiplica(|||, ||))
 *              --> soma(||, multiplica(||, ||))
 *                              --> soma(||, multiplica(|, ||))
 *                                              retorna ||
 *                                  retorna ||||
 *                  retorna ||||||
 *      retorna ||||||||                 
*/
Natural* multiplica(Natural* n1, Natural* n2) {
    if (n1 == NULL || n2 == NULL) { // quando n1 ou n2 são zero, resultado é imediatamete zero
        return NULL;
    }
 
    if (n1->prox == NULL) { // n1 = 1  --> caso base
        return n2;
    }

    return soma(n2, multiplica(resto(n1), n2)); 
    // Explicacao: a ideia aqui é somar n2 por n1 vezes.
    // Assim, a cada chamada recursiva, executa-se a soma
    // de n2 pela multiplicação de (n1-1) por n2.
    // Em algum momento, n1 chegará a 1, retornando n2
    // no caso base, que então agregará todas as somas de n2
    // feitas até então

}


int main() {

    //EXEMPLOS:
    Natural* ZERO = NULL;
    Natural* UM = junta('|', ZERO); 
    // 'junta' cria uma nova lista que é o resultado de se 
    // inserir um novo nó no início. Veja no arquivo lista_encadeada_char.c
    
    Natural* DOIS = junta('|', UM);
    Natural* TRES = junta('|', DOIS);
    Natural* QUATRO = junta('|', TRES);

    printf("%d\n", natural_to_int(QUATRO));
    print_natural(QUATRO);

    Natural* SETE = soma(TRES, QUATRO);
    printf("Soma de 3 e 4: ");
    print_natural(SETE);

    printf("Subtração de 7 por 4: ");
    print_natural(subtrai(SETE, QUATRO));

    print_natural(multiplica(SETE, SETE));
    printf("%d\n", natural_to_int(multiplica(SETE, SETE)));

}

