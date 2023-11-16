



from random_list import random_list
import time

def partition(vetor, inicio, fim):

    pivo = vetor[fim]

    i = inicio  # aponta para o atual maior elemento

    for j in range(inicio, fim):
        if vetor[j] <= pivo:

            # se elemento for menor que o pivô, 
            # troca a posição j pela posição i (maior elemento até o momento)
            vetor[i], vetor[j] = vetor[j], vetor[i]

            # Intuição: elementos menores que o pivô são jogados mais
            # para trás no vetor, enquanto que os maiores vão
            # sendo jogados para frente. No final, atrás da posição
            # i estarão todos os elementos menores que o pivô,
            # e na frente estarão todos os maiores que o pivô.

            i += 1
    
    # troca o pivô pela posição i, que é logo após o último maior elemento
    # que o pivô achado
    vetor[i], vetor[fim] = vetor[fim], vetor[i]

    return i  ## endereço do pivô


def quick_sort_rec(vetor, inicio, fim):
        
        if inicio >= fim:  # caso base
            return 

        pivo = partition(vetor, inicio, fim)

        quick_sort_rec(vetor, inicio, pivo - 1)
        quick_sort_rec(vetor, pivo + 1, fim)


def quick_sort(vetor):

    # Start quicksort
    quick_sort_rec(vetor, 0, len(vetor) - 1)




## Testes
l1 = [12, 2, 7, 25, 1, 9]
quick_sort(l1)
assert l1 == [1,2,7,9,12,25]

l2 = random_list(10000)
# quick_sort(l2)
# print(l2, "\n\n")

t_inicial = time.time() 

quick_sort(l2)

t_fim = time.time()

t_total = t_fim - t_inicial

# print(l2)
print(t_total)

