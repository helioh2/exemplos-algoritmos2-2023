
//FUNÇÃO MODIFICADORA (RECEBE PONTEIROS/REFERENCIAS PARA VALORES DEFINIDOS FORA DA FUNÇÃO)
void troca(int* x, int* y){ //void --> significa que funcao nao retorna valor  -- recebe dois ponteiros para inteiros e não retorna nada
   int temp;
   temp = *x; //temp = 10
   *x = *y;  //x = 20
   *y = temp;  // y = 10
}


int soma(int x, int y) { // ASSINATURA/CONTRATO  -- recebe dois inteiros e retorna um inteiro  (int, int -> int)
  return x + y; 
}


int main() {

  int a = 10;
  int b = 20;
 
  // PASSAGEM DE PARAMETROS POR REFERENCIA
  troca(&a, &b);  // quero que a = 20, e b = 10
  
  printf("a=%d\n", a);
  printf("b=%d\n", b);
  
  return 0;
}