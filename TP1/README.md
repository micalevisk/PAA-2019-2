# Run

## With GNU Make
```bash
cd questao4
make MILLISECONDS=true # vai gerar um executável de nome `main.exe`
make mostlyclean # apagar os objetos gerados

make generate SCENARIO=B N=1000 # gerar uma entrada para o cenário B com tamanho 1.000

## verificar se está ordenando de fato
make check ALGORITHM=heap  N=1000 INPUT=__input.1000
make check ALGORITHM=quick N=1000 INPUT=__input.1000
make check ALGORITHM=radix N=1000 INPUT=__input.1000
## verificar o tempo de ordenação
make run ALGORITHM=heap  N=1000 INPUT=__input.1000
make run ALGORITHM=quick N=1000 INPUT=__input.1000
make run ALGORITHM=radix N=1000 INPUT=__input.1000

## para executar o benchmark
make bench
```

## Without GNU Make
```bash
cd questao4
pipenv install # apenas na primeira vez

pipenv run scripts/generate_input.py 10000 B "input"
cc src/**/*.c -I./src/headers -D MS -o main.exe && ./main.exe h 10000 "input"
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
<algoritmo> <quantidade_de_elementos> </caminho/para/o/arquivo/entrada>
# OPÇÕES:
# Sendo `algoritmo` um dos listados abaixo:
## heapsort, quicksort, radixsort
```


## Cenários de entradas

### `A`
Vetor numérico em que, em média, 90% dos elementos têm o mesmo valor e
os demais apresentam valores distintos e distribuídos de maneira uniforme o longo do vetor.

### `B`
Vetor numérico onde os elementos não são repetidos e foram inseridos de maneira aleatória.
