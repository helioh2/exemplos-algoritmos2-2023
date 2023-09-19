#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;


Pixel* cria_pixel(unsigned char r, unsigned char g, unsigned char b) {
    Pixel* novo = malloc(sizeof(Pixel));
    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }
    novo->r = r;
    novo->g = g;
    novo->b = b;

    return novo;
}


int main() {

    int altura = 15;
    int largura = 10;

    Pixel** imagem = malloc(altura*sizeof(Pixel*));  // alocando linhas
    for (int i = 0; i < altura; i++) {
        imagem[i] = malloc(largura*sizeof(Pixel));  // alocando colunas
        for (int j = 0; j < largura; j++) {
            imagem[i][j] = *cria_pixel(255, 255, 255);  // criando pixel com cor branca e inserindo na matriz
        }
    }

    imagem[0][0].r = 20;
    imagem[0][0].g = 100;
    imagem[0][0].b = 200;

    imagem[1][1].r = 32;
    imagem[1][1].g = 43;
    imagem[1][1].b = 123;

    // Pintando os demais pixels da diagonal com diferentes cores.
    for (int i = 2; i < largura; i++) {
        imagem[i][i].r = i*4;
        imagem[i][i].g = i*6;
        imagem[i][i].b = i*8;
    }

    // Printando os pixels:
    for (int i=0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            printf("#%02x%02x%02x\t", imagem[i][j].r, imagem[i][j].g, imagem[i][j].b);  // a máscara %02x imprime no formato de 2 caracteres hexa
        }
        printf("\n");
    }






}