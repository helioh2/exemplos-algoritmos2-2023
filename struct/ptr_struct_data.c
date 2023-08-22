#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

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



void testesAutomatizadosSomaMeses() {
  Data* ptrData = malloc(sizeof(Data));
  
  // (*ptrData).mes = 10;
  
  ptrData->dia = 20;
  ptrData->mes = 10;
  ptrData->ano = 2023;

  //TESTES:
  
  somaMesesPorReferencia(ptrData, 1);

  assert(ptrData->mes == 11);  // VERIFICA SE O MES EH IGUAL A 11
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
}

/**
 * Função que cria uma nova data.
*/
Data* cria_data(int dia, int mes, int ano) {
   Data* ptrData = malloc(sizeof(Data));
   if (ptrData == NULL) {
      exit(EXIT_FAILURE);
   }
   ptrData->dia = dia;
   ptrData->mes = mes;
   ptrData->ano = ano;

   return ptrData;
}

/**
 * Cria uma lista de datas de tamanho n, 
 * lê do teclado as datas e retorna o 
 * ponteiro para a lista
*/
Data** le_datas(int n) {

  Data** lista_de_datas = malloc(n*sizeof(Data*));
  if (lista_de_datas == NULL) {
    exit(EXIT_FAILURE);
  }
  
  int dia, mes, ano;
  // ESTE LOOP LÊ AS DATAS DO TECLADO, CRIA A DATA E ARMAZENA O PONTEIRO NA LISTA
  for (int i = 0; i < n; i++) {
    printf("Nova data:\n");
    printf("Digite o dia: ");
    scanf("%d", &dia);

    printf("\nDigite o mes: ");
    scanf("%d", &mes);

    printf("\nDigite o ano: ");
    scanf("%d", &ano);

    Data* novaData = cria_data(dia, mes, ano);

    lista_de_datas[i] = novaData;  //guarda no vetor
  }

  return lista_de_datas;
}

/**
 * Imprime (print) nas datas da lista.
*/
void imprime_datas(Data** lista, int n) {

  // ESCREVE NA TELA AS DATAS DA LISTA
  for (int i = 0; i < n; i++) {
    Data* data = lista[i];
    printf("\n%d/%d/%d", data->dia, data->mes, data->ano);
  }

}


int main()
{
  
  Data dataNaPilha;
  
  Data* ptrData1 = cria_data(20, 10, 2023);

  printf("%d,%d,%d\n", ptrData1->dia, ptrData1->mes, ptrData1->ano);

  ptrData1->mes = 8;

  printf("%d,%d,%d\n", ptrData1->dia, ptrData1->mes, ptrData1->ano);
  // (*ptrData).mes = 10;
  
  free(ptrData1);

  int* x = malloc(sizeof(int)*10);

  int n;  // tamanho da lista
  printf("Insira a quantidade de datas a guardar:");
  scanf("%d", &n);
 
  Data** lista_datas = le_datas(n);

  imprime_datas(lista_datas, n);

  free(lista_datas); 
  // TODO: ERRATA: NECESSÁRIO DAR FREE EM CADA DATA DENTRO DA LISTA TAMBÉM

  //TESTES:
  // testesAutomatizadosSomaMeses();

  // TODO: fazer função de criar data

  return 0;
}