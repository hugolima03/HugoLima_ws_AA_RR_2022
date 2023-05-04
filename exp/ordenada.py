n = 1000000
lista = list(range(n+1))
with open(f'./inputs/asc{n}.txt', 'w') as f:
    f.write(' '.join(map(str, lista)))
