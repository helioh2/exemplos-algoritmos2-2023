#include <stdio.h>



int* func1() {
  int vetor[5];

  vetor[0] = 50;
  vetor[1] = 100;
  vetor[2] = 200;
  vetor[3] = 300;
  vetor[4] = 500;

  return vetor;
}

int main() {
  printf("Hello World!\n");
  

  int* vetor_resultante = func1();

  for (int i = 0; i < 5; i++) {
    printf("%d\n", vetor_resultante[i]);
  }

  return 0;
}