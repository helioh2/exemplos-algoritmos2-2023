#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void) {
   FILE* arquivo;
   arquivo = fopen("dados.txt", "r");  //(caminho, modo)
   if (arquivo == NULL) {
      printf("\nNão encontrei o arquivo!\n");
      exit(EXIT_FAILURE);
   }  
   
   double soma = 0.0;
   int n = 0;
   while (true) {
      int x;
      int k = fscanf(arquivo, "%d", &x);
      if (k != 1) break;
      soma += x;
      n += 1;
   }
   fclose(arquivo);
   printf("A média dos números é %f\n", soma/n);
   return EXIT_SUCCESS;
}