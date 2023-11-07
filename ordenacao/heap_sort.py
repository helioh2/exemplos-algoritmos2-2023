

from random_list import random_list



def heapify(vetor, ind_raiz, N):

    ind_maior = ind_raiz    # inicializa maior como a raiz da arvore
    ind_esq = 2 * ind_raiz + 1   # indice do filho da esquerda
    ind_dir = 2 * ind_raiz + 2   # indice do filho da direita

    if ind_esq < N and vetor[ind_maior] < vetor[ind_esq]:
        ind_maior = ind_esq
    
    if ind_dir < N and vetor[ind_maior] < vetor[ind_dir]:
        ind_maior = ind_dir

    if ind_maior != ind_raiz:
        vetor[ind_raiz], vetor[ind_maior] = vetor[ind_maior], vetor[ind_raiz]  # troca

        heapify(vetor, ind_maior, N)  # heapifica a partir do nó trocado


## Testes do heapify: 

# ver exemplo em https://www.geeksforgeeks.org/heap-sort/
v1 = [4, 10, 3, 5, 1]
heapify(v1, 0, len(v1))
assert v1 == [10, 5, 3, 4, 1]


def heap_sort(vetor):

    N = len(vetor)
 
    # Construir heap máxima (todos os nós pai maiores que nós filhos)
    for i in range(N//2 - 1, -1, -1):
        # A ideia aqui é heapificar a partir de cada nó não-folha, de baixo pra cima,
        # por isso começa-se pelo elemento em N // 2 - 1, que é o último
        # nó não-folha. Por exemplo, no caso de vetor=[12, 2, 7, 25, 1, 9],
        # heapificaria a posição 2, trocando o 7 pelo 9. Em seguida, heapificaria a 
        # posição 1, que trocaria o 2 por 25. Em seguida, heapificaria a posição 0,
        # trocando o 12 pelo 25. Ao final, teremos [25,12,9,2,1,7]
        heapify(vetor, i, N)
 
    # Troca o último pelo primeiro, fazendo o maior parar na ultima posição.
    # Em seguida, aplica-se heapify descondiderando o último.
    # Repete-se isso, sempre decrementando o valor do último, até que esteja ordenado.
    for ultimo in range(N-1, 0, -1):
        vetor[ultimo], vetor[0] = vetor[0], vetor[ultimo]  # swap
        heapify(vetor, 0, ultimo)



## Testes
l1 = [12, 2, 7, 25, 1, 9]
heap_sort(l1)
assert l1 == [1,2,7,9,12,25]

l2 = random_list(1000)
print(l2, "\n\n")

heap_sort(l2)
print(l2)


