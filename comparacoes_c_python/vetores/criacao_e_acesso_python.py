

## PROGRAMA PRINCIPAL

n = 4
numeros = [25, 50, 75, 100]
print("Acessando elemento na posição 0:", numeros[0])
print("Acessando elemento na última posição:", numeros[n-1])


nums = [None]*5  # criando um vetor com 5 posições vazias

# Adicionando elementos:
nums[0] = 25
nums[1] = 50
nums[2] = 75
nums[3] = 100
nums[4] = 125

print("Printando os elementos de nums com for:")
for i in range(0, 5):
    print(nums[i])

print("Multiplicando todos os númros de nums por 2 e printando resultado:");
for i in range(0, 5):
    nums[i] = nums[i]*2

for i in range(0, 5):
    print(nums[i])



print("Criando uma lista contendo todos os números pares de 0 até 20:");
pares = [None]*11  #terá o 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 (total de 11)
for i in range(0, 11):
    pares[i] = i*2

for i in range(0, 11):
    print(pares[i])




