#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
 * Definição da struct e do tipo que representa uma data, com dia, mês e ano.
*/
typedef struct
{
  int dia;  // um campo
  int mes;  // outro campo
  int ano;  // outro campo
} Data;

// FUNCAO PURA QUE SOMA UMA QTDE DE MESES À DATA PASSADA POR PARAMETRO
Data somaMesesPorValor(Data data, int qtdeMeses)
{

  Data novaData;

  novaData.dia = data.dia;
  novaData.mes = (data.mes-1 + qtdeMeses) % 12 + 1;
  novaData.ano = data.ano + (data.mes + qtdeMeses) / 13;

  return novaData;
}

/**
 * Soma uma quantidade de meses a uma data
*/
void somaMesesPorReferencia(Data* data, int qtdeMeses) {

  data->ano = data->ano + (data->mes + qtdeMeses) / 13;
  // Explicação: se eu somar os meses e der menor que 12, então ao dividir por 13 teremos
  // (data->mes + qtdeMeses) / 13 = 0 (quociente da divisão). Logo, não houve
  // passagem de ano. Se o novo mês der maior que 12, então o quociente da divisão será >=1,
  // que será usado para somar a quantidade de anos que se passaram.
  data->mes = (data->mes-1 + qtdeMeses) % 12 + 1;
  // Explicação: usa o resto da divisão para fazer a aritmética modular.
  // Isto é, quando eu somo a quantidade de meses e divido por 12, o resto será
  // a quantidade de meses que passou do 12. 
  // No entanto, a aritmética modular funciona sempre com os valores do intervalo
  // começando em 0. Ou seja, pegar o resto da divisão por 12 sempre daria
  // números de 0 a 11. Como os meses do ano começam
  // em 1 (janeiro) e terminam em 12 (dezembro), é necessário subtrair um mês
  // do mês atual antes da divisão, e, após a divisão, somar 1 ao resto da divisão.
  // Assim, obtemos o número do mês sempre no intervalo entre 1 e 12.

}




int main()
{
  
  Data dataNaPilha;
  
  Data* ptrData = malloc(sizeof(Data));
  
  // (*ptrData).mes = 10;
  
  ptrData->dia = 20;
  ptrData->mes = 10;
  ptrData->ano = 2023;

  //TESTES:
  
  somaMesesPorReferencia(ptrData, 1);

  assert(ptrData->mes == 11);
  assert(ptrData->ano == 2023);
  printf("Nova data: %d/%d/%d\n", ptrData->dia, ptrData->mes, ptrData->ano);

  somaMesesPorReferencia(ptrData, 3);
  assert(ptrData->mes == 2);
  assert(ptrData->ano == 2024);
  printf("Nova data: %d/%d/%d\n", ptrData->dia, ptrData->mes, ptrData->ano);

  somaMesesPorReferencia(ptrData, 24);
  assert(ptrData->mes == 2);
  assert(ptrData->ano == 2026);
  printf("Nova data: %d/%d/%d\n", ptrData->dia, ptrData->mes, ptrData->ano);

  return 0;
}