

def busca_binaria_it(vetor: list, elemento) -> int:
    
    n = len(vetor)
    inicio = 0
    fim = n-1

    meio = (inicio + fim) // 2   

    while inicio <= fim:   # condição de parada do caso de não encontrar
        
        if (vetor[meio] == elemento):  # condição de parada quando encontra
            return meio
        elif (elemento < vetor[meio]):
            fim = meio - 1
        elif (elemento > vetor[meio]):
            inicio = meio + 1
        
        meio = (inicio + fim) // 2   


    return -1



def busca_binaria_rec(vetor: list, elemento, inicio: int, fim: int) -> int:

    meio = (inicio + fim) // 2   

    if fim < inicio:
        return -1
    
    if vetor[meio] == elemento:
        return meio
    
    # else
    if elemento > vetor[meio]:
        return busca_binaria_rec(vetor, elemento, meio+1, fim)

    if elemento < vetor[meio]:
        return busca_binaria_rec(vetor, elemento, inicio, meio-1)


def busca_binaria_rec_starter(vetor, elemento) -> int:
    return busca_binaria_rec(vetor, elemento, inicio=0, fim=len(vetor)-1)


# Testes
l1 = [4,10,14,23,52,67,75,100,120]
assert busca_binaria_it(l1, 23) == 3

assert busca_binaria_it(l1, 4) == 0
assert busca_binaria_it(l1, 10) == 1
assert busca_binaria_it(l1, 14) == 2
assert busca_binaria_it(l1, 52) == 4
assert busca_binaria_it(l1, 67) == 5
assert busca_binaria_it(l1, 75) == 6
assert busca_binaria_it(l1, 100) == 7
assert busca_binaria_it(l1, 120) == 8
assert busca_binaria_it(l1, 24) == -1


print(busca_binaria_rec_starter(l1, 23))
