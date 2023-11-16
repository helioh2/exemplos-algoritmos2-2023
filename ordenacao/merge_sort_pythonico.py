


from random_list import random_list
import time

def merge(esq, dir):
    res = []
    i = 0; j = 0
    while i < len(esq) and j < len(dir):
        if esq[i] <= dir[j]:
            res.append(esq[i])
            i += 1
        else:
            res.append(dir[j])
            j += 1

    while i < len(esq):
        res.append(esq[i])
        i += 1

    while j < len(dir):
        res.append(dir[j])
        j += 1

    return res

def merge_sort(vetor):
    """
    Versão mais "pythonica"
    """
    if len(vetor) <= 1:  ##caso base
        return vetor
    
    #else
    meio = len(vetor) // 2

    ## Dividindo o vetor em dois subvetores (sublistas) usando slice (fatiamento)
    esq = vetor[:meio]
    dir = vetor[meio:]

    ## Chamando merge recursivamente para os dois subvetores:
    esq = merge_sort(esq)
    dir = merge_sort(dir)

    ## Mesclagem:
    mesclado = merge(esq, dir)

    return mesclado



## Testes
l1 = [12, 2, 7, 25, 9, 1]
l1 = merge_sort(l1)
assert l1 == [1,2,7,9,12,25]

l2 = random_list(1000000)
# print(l2, "\n\n")

t_inicial = time.time() 

l2 = merge_sort(l2)

t_fim = time.time()

t_total = t_fim - t_inicial

# print(l2)
print(t_total)


