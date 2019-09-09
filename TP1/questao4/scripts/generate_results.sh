#!/bin/bash

set -e
set -x

cd "$(dirname "$0")" ; cd .. ; ## garantindo que será executado no diretório pai deste script

RESULTS_DIR="__results__"

## Criar a pasta que guardará os tempos das execuções
mkdir -p "$RESULTS_DIR"

## Compilar o código usando o GNU Make, e apagar os objetos gerados
make MILLISECONDS=true
make mostlyclean

clean_up() {
  ARG=$?
  if [ $ARG -eq 0 ]; then
    echo "Finalizado!"
    make clean
  else
    echo "Something went wrong!"
    # read -n1 -p "Clean up? (n)"

    rm -rf "$RESULTS_DIR"
    rm -f "${CURR_INPUT_FILE}"
    make clean
    exit $ARG
  fi
}
trap 'clean_up' EXIT ## Assume que nenhum comando pode dar erro (terminar com cod. diferente de 0)

## ===============================================================
CENARIOS=("A" "B") ## reconhecidos pelo `generate_input.py`
INSTANCIAS=("20k" "40k" "60k" "80k" "100k" "120k")
ALGORITMOS=("quicksort" "heapsort" "radixsort")
QTD_VEZES=5 ## quantidade de execuções para a mesma entrada

executar_cenario() {
  cenario_id="$1"
  cenario_dir="${RESULTS_DIR}/${cenario_id}"

  ## Criar o diretório das saídas para o cenário corrente
  mkdir -p "$cenario_dir"

  echo "#algoritmo,instancia,tempo(ms)"
  for N in "${INSTANCIAS[@]}"; do
    instancia="${N//k/000}" ## substituir os 'k' por '000'
    ## Gerar entrada para a instância corrente
    arquivo_entrada="$(make -s generate SCENARIO=$cenario_id N=$instancia)"
    CURR_INPUT_FILE="$arquivo_entrada"

    for algoritmo in "${ALGORITMOS[@]}"; do
      arquivo_saida="${cenario_dir}/${algoritmo}.exec_times-${instancia}.txt"
      echo -n "" > "$arquivo_saida" ## garantir que o arquivo não contém dados

      for i in `seq 1 $QTD_VEZES`; do
        make -s run ALGORITHM="$algoritmo" N="$instancia" INPUT="$arquivo_entrada" >> "$arquivo_saida"
        sleep 0.2
      done
      
      ## Mostrar média dos tempos de execuções
      tempo_medio=$(awk '{ soma+=$1 ; ++n } END { print soma/n }' "${arquivo_saida}")
      echo "${algoritmo},${instancia},${tempo_medio}"
    done

    ## Apagar entrada gerada
    rm "$arquivo_entrada"
  done
}

for cenario_id in "${CENARIOS[@]}"; do
  executar_cenario "$cenario_id" | tee "${RESULTS_DIR}/${cenario_id}.tempos.csv"
done
