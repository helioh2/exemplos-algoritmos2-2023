
"""
Não existe o comando switch case em Python. No lugar, podemos usar elif ou
dicionários. De fato, em qualquer linguagem é possível usar
uma dessas abordagens, mas nem toda linguagem possui o switch... case
Logo, podemos dizer que if.. elif e dicionários são mais gerais do que
switch... case, embora seja interessante saber que existe e útil
em alguns casos.
"""

# if... elif .. else

animal = int(input("Digite o número de um animal: "))

if animal == 1:
    print("AU AU")
elif animal == 2:
    print("MIAU")
elif animal == 3:
    print("MÉÉ")
else:
    print("Que animal o que, eu não sou animal não");



# com dicionário:

animal = int(input("Digite o número de um animal: "))

# cria um dicionário mapeando cada número ao seu "som". Os números são chamados de chaves (keys) e o que vem na frente são chamados de valores (values)
animais = {
    1: "AU AU",
    2: "MIAU",
    3: "MEÉ"
} 
default = "Que animal o que, eu não sou animal não"

if animal in animais.keys():  # verifica se o número digitado é uma das chaves do dicionário
    print(animais[animal])  # se for, acessa o valor ("som") por meio da chave (animal)
else:
    print(default)  #senão, imprime mensagem padrão (default)

## OBS: dicionário é uma das estruturas mais úteis no dia a dia do 
## bom programador, mas vc verá ela com mais detalhes em Algoritmos 3
## e/ou Programação Orientada a Objetos. Elas são construídas por meio
## de tabelas hash, mas na maioria das linguagens vc já tem
## elas prontas. Por exemplo, em Java, é chamado de Map.
## Se o professor dessas disciplinas por acaso não mostrar, cobre!!! rs
