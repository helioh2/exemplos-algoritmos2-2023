/**
 * Solução para o problema das n rainhas em C
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



/**
 * Função que verifica se o tabuleiro possui conflitos, considerando as colunas do 0
 * até a coluna 'maxcol'
*/
bool tem_conflitos(int* tab, int maxcol) {
    for (int col = 0; col < maxcol; col++) {
        for (int p = 1; p < maxcol - col + 1; p++) {
            if (tab[col] == tab[col+p]) {
                // se a rainha em outra coluna estiver na mesma linha que a rainha na coluna atual 
                return true;
            }
            if (tab[col] + p == tab[col+p] || tab[col] - p == tab[col+p]) {
                // se a rainha a p colunas a frente estiver na linha da coluna atual somado ou substraindo p linhas à frente
                return true;
            }
        } 
    }
    // caso não tenha encontrado conflito dentro do loop, não há conflitos
    return false;
}


/**
 * Função recursiva que de fato implementa o algoritmo de backtracking
 * responsável por encontrar a solução (se existir)
*/
bool resolve_n_rainhas_rec(int* tab, int col, int n) {
    if (col >= n) {  // caso base: finalizou a alocação de todas as rainhas
        return true;
    }

    for (int lin = 0; lin < n; lin++) {   // para cada linha possível (de 0 até n-1)
        tab[col] = lin;  // tenta colocar a rainha na coluna col, linha lin

        if (!tem_conflitos(tab, col)) {
            // se não tem conflitos, tenta colocar outra rainha na próxima coluna
            bool solucao = resolve_n_rainhas_rec(tab, col+1, n);

            if (solucao) {
                // se retornou true, então uma solução foi encontrada
                return true;
            }
            // senão, continua o loop atual, tentando colocar a rainha em outra linha
            // na atual coluna col
        }
    }
    // se o loop termina sem dar return dentro dele, significa que uma solução 
    // não foi encontrada, logo, retorne false
    return false;
}


/**
 * Função que resolve a n rainhas dado um valor n, preenchendo
 * um tabuleiro (tab) no formato de um vetor de inteiros, em que
 * cada inteiro representa a linha do tabuleiro em que a rainha
 * foi colocada. Retorna true caso uma solução tenha sido encontrada,
 * e false caso contrário
 * Ex: resolve_n_rainhas(4)
 *      retorna -> true e tab = [1, 3, 0, 2]
 *          que representa o seguinte tabuleiro:
 *              . . Q . 
                Q . . . 
                . . . Q 
                . Q . .    (onde cada Q representa uma rainha)
 *
 * */
bool resolve_n_rainhas(int n, int** tab) {
    *tab = calloc(sizeof(int), n);  // inicializa vetor com zeros
    bool res = resolve_n_rainhas_rec(*tab, 0, n);  // chama a função recursiva, começando na coluna 0

    if (res) {
        printf("Solução encontrada!\n");
    } else {
        printf("Solução não encontrada!\n");
    }

    return res;
}


void print_tab(int* tab, int n) {

    for (int col = 0; col < n; col++) {
        printf("%d ", tab[col]);
    }
    printf("\n");

    for (int lin = 0; lin < n; lin++) {
        for (int col = 0; col < n; col++) {
            if (tab[col] == lin) {
                printf("Q");
            } else {
                printf(".");
            }
            if (col < n-1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
}


int main() {

    int* tab;
    bool res;

    for (int n = 2; n < 100; n++) {
        printf("Resolvendo n rainhas para n=%d", n);
        res = resolve_n_rainhas(n, &tab);
        if (res) {
            print_tab(tab, n);
        }
        free(tab);
    }



    // Testes do tem_conflitos:
    int tab1[] = {0,0,0,0};
    assert(!tem_conflitos(tab1, 0));
    assert(tem_conflitos(tab1, 1));
    int tab2[] = {0,1,0,0};
    assert(tem_conflitos(tab2, 1));
    int tab3[] = {0,2,0,0};
    assert(!tem_conflitos(tab3, 1));
    int tab4[] = {0,2,0,0};
    assert(tem_conflitos(tab4, 2));
    int tab5[] = {0,2,1,0};
    assert(tem_conflitos(tab5, 2));
    int tab6[] = {0,2,2,0};
    assert(tem_conflitos(tab6, 2));
    int tab_perfeito[] = {1,3,0,2};
    assert(!tem_conflitos(tab_perfeito, 3));

    return 0;
}
