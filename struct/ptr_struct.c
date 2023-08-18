#include <stdio.h>
#include <string.h>

// Registro
typedef struct
{
  int dia;  // um campo
  int mes;
  int ano;
} Data;

typedef struct
{
  char nome[20];
  Data dataNascimento;
  char cpf[11];
} Pessoa;

// FUNCAO PURA QUE SOMA UMA QTDE DE MESES À DATA PASSADA POR PARAMETRO
Data somaMeses(Data data, int qtdeMeses)
{

  Data novaData;

  novaData.dia = data.dia;
  novaData.mes = (data.mes + qtdeMeses) % 12;
  novaData.ano = data.ano + (data.mes + qtdeMeses) / 12;

  return novaData;
}

/**
 * Soma uma quantidade de meses a uma data
*/
void somaMesesPorReferencia(Data* data, int qtdeMeses) {

  (*data).mes = ((*data).mes + qtdeMeses) % 12;
  (*data).ano = (*data).ano + ((*data).mes + qtdeMeses) / 12;

}




int main()
{
  
  Data dataNaPilha;
  
  Data* ptrData = malloc(sizeof(Data));
  
  // (*ptrData).mes = 10;
  
  ptrData->dia = 20;
  ptrData->mes = 10;
  ptrData->ano = 2023;


  return 0;
}