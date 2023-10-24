"""
Exemplo usando recursão em cauda, típico de linguagens funcionais.
Em algumas linguagens, especialmente as puramente funcionais,
esse tipo de recursão é otimizado de forma que o compilador o
transforma em uma iteração sobre a lista. Dessa forma,
não ocorre a desvantagem da recursão, que é o uso excessivo de
memória e overflow de pilha.

Em outras linguagens, como C e Python, não há essa otimização,
logo, é mais recomendado que se utilize a versão iterativa.
"""

def M2(lista):
    if not lista:  #vetor vazio
        return []
    #else:
    primeiro_mod = lista[0] * 2
    return [primeiro_mod] + M2(lista[1:])
    # explicação: concatena-se o primeiro modificado
    # à aplicação de M2 ao resto (cauda) da lista


# Testes:
v1 = [10, 30, 50, 70, 90]
v2 = M2(v1)
print(v2)