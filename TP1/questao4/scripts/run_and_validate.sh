#!/bin/bash
# Assume que será executado no diretório `questao4`

[ $# -ne 3 ] && { echo "ARGS: <ALGORITHM_ID> <N> <INPUT_FILE>" ; exit 1; }

set -e
# set -x

EXECUTABLE="./main_with_debug.exe"
ALGORITHM_ID="$1"
N="$2"
INPUT_FILE="$3"

[ -x "${EXECUTABLE}" ] || {
  echo "Compilar com modo DEBUG"
  make -f "Makefile" DEBUG=true
  make mostlyclean
}

sort -n -c <( ${EXECUTABLE} ${ALGORITHM_ID} ${N} "${INPUT_FILE}" | sed 1d ) && echo "SORTED" || echo "NOT SORTED"
