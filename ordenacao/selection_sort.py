



from random_list import random_list



def selection_sort(vetor: list):
    n = len(vetor)

    for i in range(0, n-1):  # for (int i = 0; i < n-1; i++)
         # vetor [0..i] permanece ordenado a cada iteração
        ind_menor = i
        
        for j in range(i+1, n):  # for (int j = i+1; j < n; j++)
            if vetor[j] < vetor[ind_menor]:
                ind_menor = j

        # troca
        vetor[i], vetor[ind_menor] = vetor[ind_menor], vetor[i]
        
        
## Testes
l1 = [12, 2, 7, 25, 9, 1]
selection_sort(l1)
assert l1 == [1,2,7,9,12,25]

l2 = random_list(1000)
print(l2, "\n\n")

selection_sort(l2)
print(l2)


