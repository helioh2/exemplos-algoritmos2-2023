#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Escreve o conteúdo de um arquivo linha por linha, pegando os dados do teclado
*/
void escreve_arquivo(char* nome_arquivo) {

    FILE* arquivo;
    arquivo = fopen(nome_arquivo, "w"); //(caminho, modo) -- abrindo no modo de escrita

    int n;
    printf("Digite a quantidade de itens que serão gravados no arquivo: ");
    scanf("%d", &n);

    // declara e aloca variável 'linha' para guardar uma string de no máximo 20 caracteres
    char linha[20];

    char temp;
    scanf("%c",&temp); // Limpando buffer do scanf

    for (int i = 0; i < n; i++)
    {
        printf("Digite um item: ");
        fgets(linha, 20, stdin); // Lendo do teclado. O valor 20 define o tamanho máximo da string lida
        // ATENÇÃO: No trabalho, no lugar de ler do teclado,
        // vc deve iterar sobre a lista encadeada, pegando cada item da lista
        fprintf(arquivo, "%s", linha);  // escreve string no arquivo
        
    }
    
    fclose(arquivo);
}


int main(void)
{
    escreve_arquivo("lista_compras2.txt");
    return EXIT_SUCCESS;
}