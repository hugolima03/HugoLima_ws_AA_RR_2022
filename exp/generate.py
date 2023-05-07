import csv
import random

for n in range(0, 500001, 1000):
    asc = list(range(n+1))
    with open(f'./asc/{n}.csv', 'w') as f:
        f.write(' '.join(map(str, asc)))

    desc = list(range(n, -1, -1))
    with open(f'./desc/{n}.csv', 'w') as f:
        f.write(' '.join(map(str, desc)))

    lista = [random.randint(0, n) for i in range(n)]
    with open(f'./rand/{n}.csv', 'w') as file:
        writer = csv.writer(file, delimiter=' ')
        writer.writerow(lista)