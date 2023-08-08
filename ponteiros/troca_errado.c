
void troca(int x, int y){ // NÃO FUNCIONA, POIS x E y SÓ EXISTEM DENTRO DA FUNCAO troca
   int temp;
   temp = x; //temp = 10
   x = y;  //x = 20
   y = temp;  // y = 10
}


int main() {

  int a = 10;
  int b = 20;
 
  // PASSAGEM DE PARAMETROS POR VALOR
  troca(a,b);  // quero que a = 20, e b = 10
  
  printf("a=%d", a); // NAO ALTEROU
  printf("b=%d", b);
  
  return 0;
}