#!/bin/bash
# Compila com o modo DEBUG ativo,
# para executar ./main_with_debug.exe <ALGORITHM_ID> <N> "<INPUT_FILE>"
# afim de verificar se o resultado obtido está ordenado

set -e
# set -x

EXECUTABLE="./main_with_debug.exe"
ALGORITHM_ID="$1"
N="$2"
INPUT_FILE="$3"

# cd ..
## compila
# cc src/**/*.c -I./src/headers -D DEBUG -o "${EXECUTABLE}"

sort -n -c <( ${EXECUTABLE} ${ALGORITHM_ID} ${N} "${INPUT_FILE}" | sed 1d ) && echo "SORTED" || echo "NOT SORTED"
