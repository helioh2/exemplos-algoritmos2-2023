#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Este arquivo tem como objetivo, em conjunto com os slides sobre o assunto,
 * apresentar uma receita/método para o desenvolvimento de novas funções.
 * Ao usar essa receita para cada nova função que você precisar criar, vc 
 * terá as seguintes vantagens:
 *  1. Será muito mais simples resolver o problema, pois você o compreenderá
 * melhor. A receita te ajudará a compreender o problema antes de resolvê-lo
 *  2. Seu código tenderá a ficar menos confuso e com menos erro, melhorando
 * portanto sua qualidade e manutenibilidade
 *  3. Seu código estará sempre testado, pois você usará a ideia de testes
 * automatizados juntamente com a metodologia TDD (Test Driven Development) 
 * 
 * 
 * RECEITA DE PROJETO (DESIGN):
 * 1. Definir assinatura (contrato), propósito e cabeçalho (stub, protótipo bobo)
   2. Definir exemplos (testes automatizados) --> comando assert
   3. Usar Template (se houver; caso não haja, pule esta etapa)
   4. Escreva a solução no corpo da função (lógica da solução)
   5. Execute os testes, faça depuração (debugging) se necessário
   6. Veja se é possível refatorar (melhore o código)
        6.1 Sempre que refatorar, execute os testes novamente (passo 5)

*/


/**
 * Exemplo de aplicação da receita de projeto.
 * Considere o seguinte problema: crie uma função que retorne o dobro de um número
 * Vamos seguir a receita:
**/

//Passo 1: Definição da assinatura, propósito e cabeçalho:

/**
 * dobro: float -> float   
 * Propósito: Calcula e retorna o dobro de um número
*/
// Protótipo bobo (é uma versão da função que não resolve ainda o problema)
float dobro(float x) {
    return 0;
}


// Passo 2: Definição de exemplos:

/**
 * Os exemplos serão criados na função 'main'. Em programas mais complexos,
 * com vários arquivos e nos quais o 'main' é utilizado para executar
 * o fluxo de controle do programa, recomenda-se utilizar arquivos separados
 * para os testes. Neste caso, como se trata apenas de um exemplo de único arquivo,
 * criaremos os testes diretamente no 'main'.
*/
int main() {

    // CASOS DE TESTE (EXEMPLOS):

    assert(dobro(2) == 4); 
    // Explicação: o comando assert faz uma verificação. Neste caso, ele verifica se,
    // ao chamarmos dobro(2), a função retorna 4. O assert dará um erro caso
    // essa condição não se concretize.
    
    // SEMPRE FAÇA VÁRIOS CASOS DE TESTE, PARA TER CERTEZA DE TER TRATADO DE TODOS OS
    // CASOS POSSÍVEIS
    assert(dobro(0) == 0);
    assert(dobro(1) == 1*2);
    assert(dobro(3) == 3*2);  
    // É interessante colocar o cálculo que vc deveria fazer para resolver cada
    // caso, como foi feito nas duas linhas acima. Assim, vc já descobre também
    // qual será a lógica utilizada para resolver o problema.

    // CRIANDO VARIÁVEIS PARA TESTAR
    int x = 10;
    int res = dobro(x);
    assert(res == 20);
    
    printf("Parabéns, os testes passaram!\n");

    // UMA VEZ ESCRITOS OS TESTES, RODE O CÓDIGO!! É INTERESSANTE
    // QUE VOCÊ VEJA OS TESTES FALHAREM.

    return 0;
}

// Passo 3 será ignorado pois não definimos templates

// Passo 4: Escreva a solução do problema no corpo da função.

/**
 * Aqui no passo 4, você deve voltar à definição do protótipo bobo (stub)
 * e escrever, no corpo da função, de fato qual é a solução.
 * No caso, uma solução para o problema é a seguinte:
 * float dobro(float x) {
 *      return x*2;
 * }
 * Tente você mesmo escrever essa solução na função dobro, linhas 44 a 46.
*/

// Passo 5:  Execute os testes, faça depuração (debugging) se necessário

/**
 * O passo 5 consiste em, após escrever a solução da função, rodar novamente
 * os testes e verificando se agora nenhum dos testes lança um erro.
 * Se nenhum erro for dado, significa que vc concluiu a solução do problema.
 * Caso contrário, continue tentando chegar uma solução, escreva novos testes
 * e use a ferramente de debug (ou o C Tutor) para descobrir o que está
 * dando errado.
 * O objetivo é sempre passar em todos os testes.
 * Logo, nunca exclua os testes!! Se precisar, copie-os para outro arquivo.
*/

// Passo 6: refatore, se puder

/**
 * O passo 6 consiste em melhorar o código, melhorando sua legibilidade, por exemplo.
 * No caso do dobro, não há muito que possa ser melhorado, mas em geral as 
 * primeiras soluções que damos sempre podem ser melhoradas.
 * Veja dicas de refatoração nos slides sobre a Receita.
*/



