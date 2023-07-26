
def busca(valor, vetor): 
    """
    Em Python, não precisa passar n (tamanho do vetor), pois é possível recuperá-la dentro da função usando a função len
    """
    
    n = len(vetor)
    for i in range(0, n):
        if (vetor[i] == valor):
            return i

    return -1



# PROGRAMA PRINCIPAL

listaDeCompras = ["arroz", "feijao", "batata", "macarrao", "carne"]

print("Procurando batata na lista:")

indice = busca("batata", listaDeCompras)

print("Resultado da busca:", indice)
    

