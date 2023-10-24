


def tem_conflitos(tab: list, maxcol: int) -> bool:
    """
    Função que verifica se o tabuleiro possui conflitos, considerando as colunas do 0
    até a coluna 'maxcol'
    """
    for col in range(maxcol):
        for p in range(1, maxcol - col + 1):
            if (tab[col] == tab[col+p] 
                    or
                    tab[col] + p == tab[col+p] 
                        or tab[col] - p == tab[col+p]):
                # se a rainha em outra coluna estiver na mesma linha que a rainha na coluna atual 
                # ou se a rainha a p colunas a frente estiver na linha da coluna atual somado ou substraindo p linhas à frente
                return True
    # caso não tenha encontrado conflito dentro do loop, não há conflitos
    return False


def resolve_n_rainhas(n: int):
    """
    Função que resolve a n rainhas dado um valor n, preenchendo
    um tabuleiro (tab) no formato de um vetor de inteiros, em que
    cada inteiro representa a linha do tabuleiro em que a rainha
    foi colocada. Retorna true caso uma solução tenha sido encontrada,
    e false caso contrário
    Ex: resolve_n_rainhas(4)
        retorna -> True, [1, 3, 0, 2]
            que representa o seguinte tabuleiro:
                . . Q . 
                Q . . . 
                . . . Q 
                . Q . .    (onde cada Q representa uma rainha)
    """
    
    def resolve_n_rainhas_rec(tab: list, col: int):
        """
        Função recursiva que de fato implementa o algoritmo de backtracking
        responsável por encontrar a solução (se existir)
        """
        n = len(tab)

        if (col >= n): #caso base: finalizou a alocação de todas as rainhas
            return True
        
        for lin in range(n): # para cada linha possível (de 0 até n-1)
            tab[col] = lin # tenta colocar a rainha na coluna col, linha lin

            if not tem_conflitos(tab, col):
                # se não tem conflitos, tenta colocar outra rainha na próxima coluna
                solucao = resolve_n_rainhas_rec(tab, col+1)
                if solucao:
                    # se retornou True, então uma solução foi encontrada
                    return True
                # senão, continua o loop atual, tentando colocar a rainha em outra linha
                # na atual coluna col

        # se o loop termina sem dar return dentro dele, significa que uma solução 
        # não foi encontrada, logo, retorne false
        return False
    

    tab = [0] * n  # inicializa vetor com zeros
    res = resolve_n_rainhas_rec(tab, col=0)  # chama a função recursiva, começando na coluna 0
    if res:
        print("Solução encontrada")
    else:
        print("Solução não encontrada")

    return res, tab


def print_tab(tab: list):
    n = len(tab)
    for col in range(n):
        print(tab[col], end=" ")
    print()

    for lin in range(n):
        for col in range(n):
            if tab[col] == lin:
                print("Q", end=" ")
            else:
                print(".", end=" ")
            if col == n-1:
                print()


## Main:

for n in range(2, 100):
    print("Resolvendo n rainhas para n=", n)
    res, tab = resolve_n_rainhas(n)
    if res:
        print_tab(tab);
    