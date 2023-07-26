#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static float PI = 3.1415;

int dobra(int x) {
  int res = x * 2;
  return res;
}

int subtrai_e_dobra(int x, int y) {
  int res = x - y;
  res = dobra(res);
  return res;
}

int main() {
  int x = 5;
  int y = 4;
  int z;
  char* nome;

  z = subtrai_e_dobra(x, y);
  
  nome = malloc(sizeof(char)*5);
  strcpy(nome, "joao");
  
  printf("%s", nome);

}