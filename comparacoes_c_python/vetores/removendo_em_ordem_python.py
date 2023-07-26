
def remover(pos: int, vetor: list[int], n: int):  # vetor é passado por referência (ponteiro)

    # Deslocando os valores para trás
    for i in range(pos, n-1):  # começa em pos e vai até o penultimo elemento
    
        if vetor[pos] == None:  # se encontrar vazio, nada mais a fazer
            return   #cabou

        vetor[i] = vetor[i+1]   # passa o da frente para o atual
    
    # Inserindo o valor None na posição n-1
    vetor[n-1] = None;


## PROGRAMA PRINCIPAL
n = 6
numeros = [25, 50, 75, 100, 125, 150]

# Gostaria de remover o valor 50, sem deixar "buracos" no vetor.
# Para isso, preciso deslocar todos os elementos a partir da posição 1 para trás
# e então inserir o valor 0 (nulo) na posição n-1
remover(1, numeros, n)

print("Printando o vetor:")
for i in range(0, n):
    print(numeros[i])






