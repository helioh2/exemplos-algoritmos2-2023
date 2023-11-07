



from random_list import random_list


def selection_sort(vetor):
    n = len(vetor)

    for i in range(n):   # vetor [i..n-1] permanece ordenado a cada iteração
        menor = i
        for j in range(i+1, n):
            if vetor[j] < vetor[menor]:
                menor = j
        
        vetor[i], vetor[menor] = vetor[menor], vetor[i]  # troca, swap


## Testes
l1 = [12, 2, 7, 25, 9, 1]
selection_sort(l1)
assert l1 == [1,2,7,9,12,25]

l2 = random_list(1000)
print(l2, "\n\n")

selection_sort(l2)
print(l2)


