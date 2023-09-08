#include <stdlib.h>

typedef struct {
    char marca[21];
    char modelo[21];
    double preco;
} Carro;


/**
 * cria_carro: char*, char*, double -> Carro*
*/
Carro* cria_carro(char* marca, char* modelo, double preco) {
    Carro* novo_carro = malloc(sizeof(Carro));
    if (novo_carro == NULL) {
        exit(EXIT_FAILURE);
    }

    strcpy(novo_carro->marca, marca);
    strcpy(novo_carro->modelo, modelo);
    novo_carro->preco = preco;

    return novo_carro;
    
}


int main() {

    // TESTES

    Carro* carro1 = cria_carro("Volksvagen", "Fox", 30000);
    printf("%s\n", carro1->marca);
    

    return 0;
}