
from colorama import Fore, Back, Style

def checa_parenteses(expressao: str) -> int:
    """
    str -> int
    Retorna -1 se todos os parênteses estão fechados corretamente
    Se encontrar parêntese aberto que não foi fechado, retorna o índice em que esse
    parêntese foi aberto
    Se encontrar parêntese fechado que não foi aberto, retorna o índice em que esse
    parêntese foi fechado
    """
    pilha = []  # criando a pilha vazia

    for i in range(0, len(expressao)):

        c = expressao[i]

        if c == "(":
            pilha.append(i)   # empilhando a posição do parentese

        elif c == ")":
            if not pilha:   # se pilha vazia
                return i  # retorna a posição do erro

            pilha.pop()  #desempilhar (retirar o topo)

    # após o for
    if pilha:  # se pilha nao for vazia
        return pilha.pop()  # retorna o topo da pilha, que é o indice do ultimo parentese nao fechado
        
    #senao
    return -1  # balanceado
   

def mostra_erro_parenteses(expressao: str, indice_erro: int):
    
    for i in range(len(expressao)):
        c = expressao[i]
        if i == indice_erro:
            print(Fore.RED + c, end="")
        else:
            print(Style.RESET_ALL, end="")
            print(c, end="")
    print()



# Testes
assert checa_parenteses("(a+(b-c))") == -1  # tudo certo, retorna -1
assert checa_parenteses("5-(a+(b-c)-5") == 2 # não fechou o primeiro parenteses (indice 2)
assert checa_parenteses("(a+b)-5)+2") == 7  # não abriu o parênteses fechado na posição 7

#print(Fore.RED + 'some red text')

indice = checa_parenteses("5-(a+(b-c)-5")

mostra_erro_parenteses("5-(a+(b-c)-5", indice)

indice = checa_parenteses("(a+b)-5)+2")

mostra_erro_parenteses("(a+b)-5)+2", indice)


indice = checa_parenteses("(2+(5+2)-(5-(7*2)-3)-5)*)10-5")

mostra_erro_parenteses("(2+(5+2)-(5-(7*2)-3)-5)*)10-5", indice)


