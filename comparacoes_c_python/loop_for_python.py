"""
Considerando uma variável de laço chamada i:
Estrutura do FOR em pseudocódigo (português):

para cada valor i entre INICIO e FIM com passo PASSO:
	... FAZ ALGUMA COISA

Em Python:

for i in range(INICIO, FIM, PASSO):
  # corpo do código a ser executado
}
"""

#PROGRAMA PRINCIPAL (MAIN)

print("Imprimindo todos os números de 0 a 20:")
for i in range(0, 21): #ou: for i in range(0, 21, 1)
    print(i)

print("Imprimindo todos os números de 0 a 20, pulando de 2 em 2:")
for i in range(0, 21, 2):
    print(i)

print("Imprimindo os números de 20 a 0, de traz pra frente:\n")
for i in range(20, -1, -1): 
    print("%d\n", i)




