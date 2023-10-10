#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Imprime o conteúdo de um arquivo linha por linha
*/
void print_arquivo(char* nome_arquivo) {

    FILE* arquivo;
    arquivo = fopen(nome_arquivo, "r"); //(caminho, modo) -- abrindo no modo leitura
    if (arquivo == NULL)
    {
        printf("\nNão encontrei o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    // declara e aloca variável 'linha' para guardar uma string de no máximo 20 caracteres
    char* linha = malloc(sizeof(char)*20);  

    while (true)
    {
        int k = fscanf(arquivo, "%[^\n]\n", linha);  // lendo cada linha do arquivo
        if (k != 1)  // se arquivo terminou, interrompe o loop
            break;
        printf("%s\n", linha);  // imprime linha
        // ATENÇÃO: No trabalho, no lugar de imprimir a linha, vc deverá adicionar
        // a linha a uma lista encadeada!!
    }
    fclose(arquivo);
}


int main(void)
{
    print_arquivo("lista_compras.txt");
    return EXIT_SUCCESS;
}