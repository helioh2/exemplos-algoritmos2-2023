
import random

def random_list(n: int):
    return [random.randrange(1,n+1) for _ in range(n)]