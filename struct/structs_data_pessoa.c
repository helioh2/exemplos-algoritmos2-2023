#include <stdio.h>
#include <string.h>

/**
 * Definição da struct e do tipo que representa uma data, com dia, mês e ano.
*/
typedef struct
{
  int dia;  // um campo
  int mes;  // outro campo
  int ano;  // outro campo
} Data;

/**
 * Definição da struct e do tipo que representa uma pessoa,
 * com nome, data de nascimento e CPF.
*/
typedef struct
{
  char nome[20];
  Data dataNascimento;
  char cpf[11];
} Pessoa;


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

  int x = 20;

  Data minhaData;

  minhaData.dia = 10;
  minhaData.mes = 8;
  minhaData.ano = 2023;

  Data aniversarioArthur;

  aniversarioArthur.dia = 12;
  aniversarioArthur.mes = 6;
  aniversarioArthur.ano = 2004;

  Pessoa p1;

  strcpy(p1.nome, "Fulano de Souza\0");
  p1.dataNascimento = aniversarioArthur;
  strcpy(p1.cpf, "101010202\0");
  // strcpy((*p1).nome

  Pessoa p2;

  strcpy(p2.nome, "Beltrano da Silva\0");
  p2.dataNascimento = minhaData;
  strcpy(p2.cpf, "2626262626\0");

  printf("%d\n", sizeof(p2)); // verirficar porque tem 1 byte a mais de tamanho
  printf("%d\n", sizeof(p2.nome));
  printf("%d\n", sizeof(p2.dataNascimento));
  printf("%d\n", sizeof(p2.cpf));

  printf("Minha data: %d/%d/%d\n", minhaData.dia, minhaData.mes, minhaData.ano);

  Data novaData = somaMesesPorValor(minhaData, 10);

  printf("Nova data: %d/%d/%d\n", novaData.dia, novaData.mes, novaData.ano);


  Data* ptrData = malloc(sizeof(Data));
  
  // (*ptrData).mes = 10;
  ptrData->dia = 15;
  ptrData->mes = 10;
  ptrData->ano = 2023;


  return 0;
}