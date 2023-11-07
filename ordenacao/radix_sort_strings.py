"""
Ordenação de strings de tamanho fixo e com quantidade limitade
de caracteres possíveis. Uma das melhores soluções de ordenação
para códigos de tamanho fixo, por exemplo, *placas de carro*.
Veja testes ao final do arquivo.
"""



def counting_sort(vetor, pos):
    """
    Counting sort supondo a ordenação de strings por caracteres, permitidos
    apenas caracteres da tabela ASCII relativos a números e letras
    maiusculas. Portanto, considera-se apenas os caracteres de 48 a 90.
    O parâmetro 'pos' representa qual posição na string será usada na ordenação.  
    """
    n = len(vetor)
    menor = 48
    maior = 90
    total = maior - menor + 1

    vetor_cont = [0]*total
    vetor_res = [None] * n

    # preenchendo vetor de contagem
    for x in vetor:
        char = x[pos]
        indice = ord(char) - menor
        vetor_cont[indice] += 1

    # fazendo a soma cumulativa:
    for i in range(len(vetor_cont)-1):
        vetor_cont[i+1] += vetor_cont[i]

    # Percorrendo vetor de entrada de trás para frente, realizando a inserção o resultante
    for i in range(n-1, -1, -1):
        x = vetor[i]
        char = x[pos]
        indice = ord(char) - menor
        vetor_cont[indice] -= 1
        indice_res = vetor_cont[indice]
        vetor_res[indice_res] = x
    
    return vetor_res
    

## Testes couting sort:
v1 = ["C","F","D","A","C","D","A","C"]
assert counting_sort(v1, 0) == ["A","A","C","C","C","D","D","F"]

v1 = ["AC","BF","CD","DA","EC","FD","GA","HC"]
assert counting_sort(v1, 1) == ["DA","GA","AC","EC","HC","CD","FD","BF"]


def radix_sort(vetor):
    """
    Radix sort para strings. Todas as strings tem que ter 
    tamanhos iguais e conter letras maiúsculas ou dígitos de 0 a 9
    """
    n_digitos = len(vetor[0])

    for i in range(n_digitos-1, -1, -1):
        vetor = counting_sort(vetor, i)

    return vetor


## Testes radix sort:
v1 = [
    "FON1723",
    "EAD3312",
    "CDA7891",
    "FAJ4021",
    "DOG1125",
    "BAT7271",
    "GIZ1234",
    "BAT7328",
    "BIG8733",
    "CAT9955"
    ]
assert radix_sort(v1) == [
    "BAT7271",
    "BAT7328",
    "BIG8733",
    "CAT9955",
    "CDA7891",
    "DOG1125",
    "EAD3312",
    "FAJ4021",
    "FON1723",
    "GIZ1234"
]