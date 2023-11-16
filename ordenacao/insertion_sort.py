



from random_list import random_list

import time

def insertion_sort(vetor):
    n = len(vetor)

    for i in range(1, n):  ## subvetor [0..i-1] permanece ordenado a cada iteração
        j = i - 1
        while j >= 0 and vetor[j+1] <= vetor[j]:         
            vetor[j], vetor[j+1] = vetor[j+1], vetor[j]
            j -= 1
        


## Testes
l1 = [12, 2, 7, 25, 9, 1]
insertion_sort(l1)
assert l1 == [1,2,7,9,12,25]

l2 = random_list(10)
# print(l2, "\n\n")

t_inicial = time.time() 

insertion_sort(l2)

t_fim = time.time()

t_total = t_fim - t_inicial

# print(l2)
print(t_total)


