#!/usr/bin/env python3
# Executar no diretório pai deste script.
# Vai gerar as duas figuras para os arquivos `A.tempos.csv` e `B.tempos.csv` em `__resultados__`
import random
import pandas as pd
import matplotlib.pyplot as plt

def plot_dataframe(source_df, filename_img, cenario_id):
    fig = plt.figure()

    algoritmos = ['quicksort', 'heapsort', 'radixsort']
    marcas = ['o', '^', 'x']
    for (idx, algoritmo) in enumerate(algoritmos):
        df = source_df[source_df['#algoritmo'] == algoritmo]
        plt.plot(df['instancia'], df['tempo(ms)'],
                marker=marcas[idx], label=algoritmo)

    plt.xlabel('quantidade de elementos', fontsize=12)
    plt.ylabel('tempo (ms)', fontsize=12)

    plt.title('Tempos de execução para o cenário ' + cenario_id, fontsize=14)

    plt.grid(linestyle='-', linewidth=1)
    plt.legend()
    plt.yscale('log')

    # plt.show()
    fig.savefig(filename_img + '.png', dpi=100)

dados = [
    ('_resultados_/A.tempos.csv', 'A'),
    ('_resultados_/B.tempos.csv', 'B')
]

for (dado, cid) in dados:
    plot_dataframe(pd.read_csv(dado), dado, cid)