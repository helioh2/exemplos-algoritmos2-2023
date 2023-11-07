



def counting_sort(vetor, exp):
    """
    Counting sort supondo a ordenação de dígitos de 0 a 9.
    O expoente exp serve para calcular o múltiplo de 10 que será
    dividido pelo valor no vetor, para assim pegar unidades, dezenas,
    centenas, etc.
    Por exemplos: 
    exp = 0 ordena pelas unidades, 
    exp = 1 ordena pelas dezenas,
    exp = 2 ordena pelas centenas, e assim por diante
    """
    n = len(vetor)
    vetor_cont = [0]*10
    vetor_res = [None] * n
    divisor = 10**exp

    # preenchendo vetor de contagem
    for x in vetor:
        digito = (x // divisor) % 10
        vetor_cont[digito] += 1

    # fazendo a soma cumulativa:
    for i in range(len(vetor_cont)-1):
        vetor_cont[i+1] += vetor_cont[i]

    # Percorrendo vetor de entrada de trás para frente, realizando a inserção o resultante
    for i in range(n-1, -1, -1):
        valor = (vetor[i] // divisor) % 10
        vetor_cont[valor] -= 1
        indice_res = vetor_cont[valor]
        vetor_res[indice_res] = vetor[i]
    
    return vetor_res
    

## Testes couting sort:
v1 = [2,5,3,0,2,3,0,3]
assert counting_sort(v1, 0) == [0,0,2,2,3,3,3,5]

v1 = [20,50,30,0,20,30,0,30]
assert counting_sort(v1, 1) == [0,0,20,20,30,30,30,50]


def radix_sort(vetor):
    """
    Radix sort para números inteiros
    """
    maior = max(vetor)
    n_digitos = len(str(maior))

    for i in range(n_digitos):
        vetor = counting_sort(vetor, i)

    return vetor


## Testes radix sort:
v1 = [170, 45, 75, 90, 802, 24, 2, 66]
assert radix_sort(v1) == [2, 24, 45, 66, 75, 90, 170, 802]