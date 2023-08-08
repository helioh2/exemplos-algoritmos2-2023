int main() {

  int a = 10;
  int b = 20;
  int c;

  int* p; // p é um ponteiro para um inteiro
  int* q; 
  p = &a; // o valor de p é o endereço de a
  q = &b; // q aponta para b
  
  printf("Valor da variavel p: %p\n", p);
  printf("Valor da variavel q: %p\n", q);
  
  printf("Valor do endereço para onde a variavel p aponta: %d\n", *p);
  printf("Valor do endereço para onde a variavel q aponta: %d\n", *q);
  
  return 0;
}