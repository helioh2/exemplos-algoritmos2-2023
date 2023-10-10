/**
 * Resolver o problema das n rainhas: 
 * https://pt.wikipedia.org/wiki/Problema_das_oito_damas
*/

#include <stdbool.h>

bool semConflitos(int* tabuleiro, int atual) {
    for (int i = 0; i < atual; i++) {
        if (tabuleiro[i] == tabuleiro[atual]) {
            return false;
        }
        if (tabuleiro[atual - i] == abs(tabuleiro[atual] - tabuleiro[i])) {
            return false;
        }
    }
}


bool resolver_n_rainhas_rec(int* tabuleiro, int atual, int n) {
    if (atual == n) {
        return true;
    }

    for (int i = 0; i < n; i++) {
        tabuleiro[atual] == i;
        if (semConflitos(tabuleiro, atual)) {
            bool terminado = resolver_n_rainhas_rec(tabuleiro, atual + 1, n);
            if (terminado) {
                return true;
            }
        }
    }
    return false;
}

bool resolver_n_rainhas(int n, int** tabuleiro) {
    *tabuleiro = malloc(sizeof(int)*n);
    return resolver_n_rainhas_rec(*tabuleiro, 0, n);
}

int main() {

    int n = 8;
    int* tabuleiro;

    resolver_n_rainhas(n, &tabuleiro);

    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d,", tabuleiro[i]);
    }
    printf("]");

    return -1;
}