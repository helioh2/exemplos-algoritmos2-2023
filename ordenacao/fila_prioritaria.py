"""
Implementação de fila prioritária utilizando heap máximo
"""


from dataclasses import dataclass


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



@dataclass   # é como se fosse um struct
class FilaPrioritaria:
    vetor: list
    capacidade: int
    n: int


def cria_fila_vazia(capacidade=100):
    fila = FilaPrioritaria([-99999999]*capacidade, capacidade, 0)  # criando o objeto/struct do tipo FilaPrioritaria
    return fila


def insere_na_fila(fila, item):
    if fila.n == fila.capacidade:
        print("ERRO: capacidade máxima atingida")
        return
    
    fila.n += 1
    i = fila.n - 1
    fila.vetor[i] = item  # insere no final
    
    # Ajustar valor para ficar na posição correta na árvore heap:
    # Custo: O(log n)
    pai = (i - 1) // 2   # calcula índice do pai na árvore heap
    while i > 0 and fila.vetor[pai] < fila.vetor[i]:
        fila.vetor[pai], fila.vetor[i] = fila.vetor[i], fila.vetor[pai] # troca
        i = pai   # atualiza o índice após a troca
        pai = (i - 1) // 2  # pega o novo pai


def remove_da_fila(fila):
    item = fila.vetor[0]
    fila.vetor[0] = fila.vetor[fila.n - 1]  # troca com o último
    fila.n -= 1
    heapify(fila.vetor, 0, fila.n)  #O(log n)   
    return item


# Testes:

fila = cria_fila_vazia()
insere_na_fila(fila, 10)
insere_na_fila(fila, 50)
insere_na_fila(fila, 5)
print(remove_da_fila(fila))
print(remove_da_fila(fila))
print(remove_da_fila(fila))
insere_na_fila(fila, 10)
insere_na_fila(fila, 50)
insere_na_fila(fila, 5)
insere_na_fila(fila, 200)
insere_na_fila(fila, 7)
insere_na_fila(fila, 300)
print(remove_da_fila(fila))
print(remove_da_fila(fila))
print(remove_da_fila(fila))
print(remove_da_fila(fila))
print(remove_da_fila(fila))
print(remove_da_fila(fila))