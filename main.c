#include <stdio.h>

void recursiva() {
  int x = 0;
  recursiva();
}


int main() {
  printf("Hello World!\n");
  recursiva();
  return 0;
}