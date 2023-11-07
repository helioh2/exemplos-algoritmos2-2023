




from random_list import random_list


def merge_sort(vetor):

    def merge(vetor, inicio, meio, fim):

        ## cria vetores auxiliares contendo as duas partes
        esq_temp = vetor[inicio : meio+1]  # fatiamento / slice
        dir_temp = vetor[meio+1 : fim+1]  # fatiamento / slice
        ## Em C, não existe fatiamento, logo é necessário "manualmente"
        ## criar vetores vazios e preenchê-los com os valores das partes
        ## esquerda e direita. Veja um exemplo em C em: 
        # https://www.geeksforgeeks.org/merge-sort/

        n_esq = len(esq_temp)
        n_dir = len(dir_temp)

        ## mescla as partes, iterando conjuntamente nos dois vetores auxiliares
        i, j = 0, 0  # i itera em esq_temp, j itera em dir_temp
        k = inicio
        while i < n_esq and j < n_dir:
            if esq_temp[i] <= dir_temp[j]:
                vetor[k] = esq_temp[i]
                i += 1
            else:
                vetor[k] = dir_temp[j]
                j += 1
            k += 1
        
        ## copia os elementos restantes de esq_temp, se houver
        while i < n_esq:
            vetor[k] = esq_temp[i]
            i += 1
            k += 1
        
        ## copia os elementos restantes de dir_temp, se houver
        while j < n_dir:
            vetor[k] = dir_temp[j]
            j += 1
            k += 1
        

    def merge_sort_rec(vetor, inicio, fim):

        if inicio >= fim:
            return

        meio = (inicio + fim)//2
        merge_sort_rec(vetor, inicio, meio)
        merge_sort_rec(vetor, meio + 1, fim)

        merge(vetor, inicio, meio, fim)


    # Start
    merge_sort_rec(vetor, 0, len(vetor) - 1)




def merge_sort2(vetor):
    """
    Versão mais "pythonica"
    """

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


    if len(vetor) <= 1:
        return vetor
    
    #else
    meio = len(vetor) // 2

    ## Dividindo o vetor em dois subvetores (sublistas) usando slice (fatiamento)
    esq = vetor[:meio]
    dir = vetor[meio:]

    ## Chamando merge recursivamente para os dois subvetores:
    esq = merge_sort2(esq)
    dir = merge_sort2(dir)

    ## Mesclagem:
    return merge(esq, dir)


## Testes
l1 = [12, 2, 7, 25, 9, 1]
l1 = merge_sort2(l1)
assert l1 == [1,2,7,9,12,25]

l2 = random_list(1000)
print(l2, "\n\n")

l2 = merge_sort2(l2)
print(l2)


