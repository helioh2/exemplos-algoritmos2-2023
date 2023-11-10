
import random


from random_list import random_list



def bubble_sort(vetor: list):
    n = len(vetor)
    for fim in range(n-1, -1, -1): # for (int fim = n-1; i > -1; i-- )
        for i in range(0, fim): # subvetor [fim..n-1] permanece ordenado a cada iteração 
            if vetor[i] < vetor[i+1]:
                vetor[i], vetor[i+1] = vetor[i+1], vetor[i]  # swap/troca





# def bubble_sort(vetor):
#     n = len(vetor)
#     for k in range(n-1, -1, -1):  # subvetor [k..n-1] permanece ordenado a cada iteração 
#         trocou = False
#         for i in range(0, k):  # contador que sai fazendo as trocas até o limite do final já ordenado
#             if vetor[i] > vetor[i+1]:
#                 vetor[i], vetor[i+1] = vetor[i+1], vetor[i]   # swap/troca
#                 trocou = True
#         if not trocou:
#               break

## Testes
l1 = [12, 2, 7, 25, 2, 9, 1]
bubble_sort(l1)
# assert l1 == [1,2,2,7,9,12,25]
print(l1)

compras = [
    "feijao",
    "batata",
    "arroz",
    "leite",
    "farinha"
]
random.shuffle(compras)

bubble_sort(compras)

print(compras)




# v2 = list(range(1000))
# random.shuffle(v2)
# print(v2, "\n\n")

# bubble_sort(v2)
# print(v2)


