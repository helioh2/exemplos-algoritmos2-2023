int main() {


  int vetor[5];  //ARRAY DE INT  (aloca 20 bytes para aramzernar 5 inteiros)
  
  vetor[0] = 10;
  vetor[1] = 20;
  vetor[2] = 30;
  vetor[3] = 40;
  vetor[4] = 50;
  
  int* p = &vetor;
  
  *p = 100; // altera o primeiro elemento do vetor
  *(p+1) = 200;  // vai na proxima gaveta e coloca o 200
  *(p+2) = 300;
  *(p+3) = 400;
  *(p+4) = 500;
  //*(p+5) = 600;  //ISSO É UM ERRO
  
  
  for (int i = 0; i < 5; i++) {
    printf("%d\n", vetor[i]); 
  }
  
  for (int i = 0; i < 5; ++i) {
    printf("Digite: ");
    scanf("%d", &p[i]);
  } 
  

  for (int i = 0; i < 5; i++) {
    printf("%d\n", vetor[i]); 
  }
  // for (int i = 0; i < 5; i++) {
  //   printf("%d\n", *(vetor+i)); 
  // }

  return 0;
}