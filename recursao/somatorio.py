"""
Exemplo usando recursão em cauda, típico de linguagens funcionais.
Em algumas linguagens, especialmente as puramente funcionais,
esse tipo de recursão é otimizado de forma que o compilador a
transforma em uma iteração sobre a lista. Dessa forma,
não ocorre a desvantagem da recursão, que é o uso excessivo de
memória e overflow de pilha.

Em outras linguagens, como C e Python, não há essa otimização,
logo, é mais recomendado que se utilize a versão iterativa.
"""

def somatorio(lista):
    if not lista:  # se a lista estiver vazia
        return 0
    #else  (passo recursivo)
    res = lista[0] + somatorio(lista[1:])
    return res
    ## soma o primeiro elemento com o somatorio do resto


def somatorio_it(lista):

    soma = 0

    for x in lista:
        soma += x

    return soma


# Testes:
v1 = [10, 30, 50, 70, 90]
res = somatorio(v1)
print(res)