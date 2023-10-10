#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Escreve o conteúdo de um arquivo linha por linha, pegando os dados do teclado
*/
void escreve_arquivo(char* nome_arquivo) {

    FILE *arquivo;
    arquivo = fopen(nome_arquivo, "w"); //(caminho, modo) -- abrindo no modo de escrita

    int n;
    printf("Digite a quantidade de itens que serão gravados no arquivo: ");
    scanf("%d", &n);

    // declara e aloca variável 'linha' para guardar uma string de no máximo 20 caracteres
    char* linha = malloc(sizeof(char)*20);  

    for (int i = 0; i < n; i++)
    {
        printf("Digite um item: ");
        scanf("%s", linha); // lê string do teclado
        // ATENÇÃO: No trabalho, no lugar de ler do teclado,
        // vc deve iterar sobre a lista encadeada, pegando cada item da lista
        fprintf(arquivo, "%s\n", linha);  // escreve string no arquivo
        // TODO (por fazer): não inserir '\n' na última linha
        
    }
    
    fclose(arquivo);
}


int main(void)
{
    escreve_arquivo("lista_compras2.txt");
    return EXIT_SUCCESS;
}