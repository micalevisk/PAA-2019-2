# Run
```bash
cd questao4
pipenv install # apenas na primeira vez

pipenv run scripts/generate_input.py 10000 B "input"
cc src/main.c -I./src/algoritmos -o main && ./main 10000 "input"
```

# O relatório deve conter

- [ ] Trecho de código das implementações dos algoritmos
- [ ] Explicação dos algoritmos
- [ ] Análise de custos de tempo e espaço dos algoritmos (com elementos gráficos)
- [ ] Conclusões obtidas dos testes empíricos, devidamente embasadas

# Processo de execução dos experimentos

Cada um dos três algoritmos de ordenação (**heapsort**, **quicksort** e **radixsort**)
deve ser testado sob o mesmo conjunto de dados. Para tal, os dados foram gerados previamente e, em seguida, usados como entrada para cada execução projetada.

O programa final deverá ser executado pela linha de comandos, e possui a seguinte interface:
```bash
[OPÇÕES] <algoritmo> </caminho/para/o/arquivo/entrada>
# OPÇÕES:
## --quiet    [false] Flag para não mostrar o array ordenado
# Sendo `algoritmo` um dos listados abaixo:
## heapsort, quicksort, radixsort
```


## Cenários de entradas

### `A`
Vetor numérico em que, em média, 90% dos elementos têm o mesmo valor e
os demais apresentam valores distintos e distribuídos de maneira uniforme o longo do vetor.

### `B`
Vetor numérico onde os elementos não são repetidos e foram inseridos de maneira aleatória.
