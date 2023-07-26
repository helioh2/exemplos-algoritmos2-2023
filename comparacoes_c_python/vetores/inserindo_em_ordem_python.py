


def adicionar(valor: int, pos: int, vetor: list[int]):
    """
    Em Python, não precisa passar n (tamanho do vetor), pois é possível recuperá-la dentro da função usando a função len
    """

    n = len(vetor)
    if vetor[n-1] != None:
        print("ERRO: LISTA CHEIA")
        return  # termina
    
    for i in range(n-2, pos-1, -1):
        vetor[i+1] = vetor[i]

    vetor[pos] = valor




## PROGRAMA PRINCIPAL
n = 6
numeros = [25, 75, 100, 125, 150, None]

## Gostaria de adicionar o valor 50, e manter os elementos na ordem correta
## Para isso, preciso deslocar todos os elementos a partir da posição 1 para frente
## e então inserir o valor 50 na posição 1
adicionar(50, 1, numeros);

print("Printando o vetor:")
for i in range(0, n):
    print(numeros[i])
