



from random_list import random_list


def bubble_sort(vetor):
    n = len(vetor)

    for k in range(n-1, -1, -1):  # subvetor [k..n-1] permanece ordenado a cada iteração 
        for i in range(0, k):  # contador que sai fazendo as trocas até o limite do final já ordenado
            if vetor[i] > vetor[i+1]:
                vetor[i], vetor[i+1] = vetor[i+1], vetor[i]   # swap/troca
            


## Testes
l1 = [12, 2, 7, 25, 9, 1]
bubble_sort(l1)
assert l1 == [1,2,7,9,12,25]

l2 = random_list(1000)
print(l2, "\n\n")

bubble_sort(l2)
print(l2)


