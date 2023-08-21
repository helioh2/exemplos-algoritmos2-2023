#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// SIMULAR EM: https://pythontutor.com/c.html


typedef struct {
  char nome[10];
  char cpf[12];
  int anoNascimento;
} Pessoa;


void mudaAnoPorReferencia(Pessoa* pessoa) {
    pessoa->anoNascimento += 1;
}

Pessoa mudaAnoPorValor(Pessoa pessoa) {
    pessoa.anoNascimento += 1;
    return pessoa;
}

int main() {
  
    // CRIANDO ESTRUTURAS SOMENTE NA PILHA:

    Pessoa pessoa1  = {"Fulano", "12345678912", 1999}; //variável local, alocação de memória na pilha, a struct está na pilha

    printf("Conteudo do struct pessoa1: %s %s %d\n", pessoa1.nome, pessoa1.cpf, pessoa1.anoNascimento);

    mudaAnoPorReferencia(&pessoa1);  // aqui está passando o endereço da pilha onde se encontra o struct pessoa1

    printf("Endereco de pessoa1 dentro da pilha: %d\n", &pessoa1);  
    
    printf("Conteudo de pessoa1 apos alteração por referencia: %s %s %d\n", pessoa1.nome, pessoa1.cpf, pessoa1.anoNascimento);
    
  
    Pessoa pessoa2 = mudaAnoPorValor(pessoa1); //passagem por valor e retorno por valor --> copia a struct para novo frame na pilha e copia de volta no retorno para nova variável pessoa2
    printf("Conteudo de pessoa2, nova variavel retornada pela função que recebe e retorna por valor: %s %s %d\n", pessoa2.nome, pessoa2.cpf, pessoa2.anoNascimento); 
    printf("Conteudo de pessoa1, que foi passada por valor e portanto não alterada na função chamadora: %s %s %d\n", pessoa1.nome, pessoa1.cpf, pessoa1.anoNascimento);

  
    // CRIANDO ESTRUTURA NA HEAP E USANDO PONTEIRO:
  
    Pessoa* pessoa_ptr1 = (Pessoa*) malloc(sizeof(Pessoa)); //criação de ponteiro/referência e alocação de memória na heap, o ponteiro (endereço) está na pilha, a struct na heap

    strcpy(pessoa_ptr1->nome, "Beltrano"); 
    strcpy(pessoa_ptr1->cpf, "98765432198");
    pessoa_ptr1->anoNascimento = 2006;  //ou (*pessoa_ptr1).anoNascimento  [desreferenciação]
    
    mudaAnoPorReferencia(pessoa_ptr1); //passa ponteiro por referência, alterando o objeto na heap
    
    printf("Endereco do ponteiro pessoa_ptr1: %d\n", pessoa_ptr1);
    
    printf("Conteudo do struct de pessoa_ptr1: %s %s %d\n", pessoa_ptr1->nome, pessoa_ptr1->cpf, pessoa_ptr1->anoNascimento);

   
    

    
   
    
  return 0;
}