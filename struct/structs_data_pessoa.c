
#include <string.h>


// Registro
typedef struct {
  int dia;
  int mes;
  int ano;
} Data;


typedef struct {
  char nome[20];
  Data dataNascimento;
  char cpf[11];
} Pessoa;




// FUNCAO PURA QUE SOMA UMA QTDE DE MESES À DATA PASSADA POR PARAMETROSSSSSSSSSSSSSSS
Data somaMeses(Data data, int qtdeMeses) {
  
  Data novaData;
  
  novaData.dia = data.dia;
  novaData.mes = data.mes + qtdeMeses;
  novaData.ano = data.ano;
  
  return novaData;
  
  
}



int main() {


  // char data[11] = "10/08/2023"; 

  int x = 20;

  Data minhaData;
  
  minhaData.dia = 10;
  minhaData.mes = 8;
  minhaData.ano = 2023;
  
  // Data aniversarioArthur;
  
  // aniversarioArthur.dia = 12;
  // aniversarioArthur.mes = 6;
  // aniversarioArthur.ano = 2004;
  
  
  // Pessoa p1;
  
  // strcpy(p1.nome, "Fulano de Souza\0");
  // p1.dataNascimento = aniversarioArthur;
  // strcpy(p1.cpf, "101010202\0");
  // // strcpy((*p1).nome


  Pessoa p2;
  
  strcpy(p2.nome, "Beltrano da Silva\0");
  p2.dataNascimento = minhaData;
  strcpy(p2.cpf, "2626262626\0");
  
  
  printf("%d\n", sizeof(p2));   // verirficar porque tem 1 byte a mais de tamanho
  printf("%d\n", sizeof(p2.nome));
  printf("%d\n", sizeof(p2.dataNascimento));
  printf("%d\n", sizeof(p2.cpf));

  
  
  Data novaData = somaMeses(minhaData, 10);
  
  printf("%d\n", novaData.mes);

  return 0;
}