#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[20];
    char sobrenome[40];
    Data data_nascimento;
    char cpf[12];
    Data data_admissao;
    double salario;
} Colaborador;

void print_colaborador(Colaborador* colaborador) {
    printf("-------------\n");
    printf("Nome: %s %s\n", colaborador->nome, colaborador->sobrenome);
    printf("Salario: %f\n", colaborador->salario);
    printf("-------------\n");
}


/**
 * altera_salario: Colaborador, double -> Colaborador
 * Alterar salário de forma não modificadora (pura)
*/
//stub
Colaborador altera_salario(Colaborador colab, double novoSalario) {
    colab.salario = novoSalario;
    return colab;  // retorna o valor (struct) do colab
}


/**
 * altera_salario_mod: Colaborador*, double -> void
 * Alterar salário de forma modificadora
*/
void altera_salario_mod(Colaborador* colab, double novoSalario) {
    colab->salario = novoSalario;
}


int dobro(int x) {
    return x*2;
}



int main() {

    Colaborador colaboradores[500];

    Colaborador gerente1;
    strcpy(gerente1.nome, "Ciclano");
    strcpy(gerente1.sobrenome, "Lopes");
    Data dt1 = {15, 8, 1990};
    gerente1.data_nascimento = dt1;
    strcpy(gerente1.cpf, "89898989898");
    Data dt2 = {5, 9, 2023};
    gerente1.data_admissao = dt2;
    gerente1.salario = 7000.0;

    colaboradores[0] = gerente1;

    // for (int i = 0; i < 100; i++) {
    //     print_colaborador(&colaboradores[i]);
    // }   


    // TESTES altera_salario:
    gerente1 = altera_salario(gerente1, 8000.0);
    // assert(gerente1.salario == 7000.0);
    assert(gerente1.salario == 8000.0);
    

    int num = 10;
    num = dobro(num);  // num <- 20


    // TESTES altera_salario_mod:
    altera_salario_mod(&gerente1, 9000.50);
    assert(gerente1.salario == 9000.50);

    return 0;
}