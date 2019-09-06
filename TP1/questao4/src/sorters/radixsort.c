#include "algorithms.h"

/*
(c) https://pt.wikipedia.org/wiki/Radix_sort
------------------------------------------------------
------------------------------------------------------
*/

void radixsort(int64 *vetor, uint64 tamanho) {
  int64 maior = vetor[0];
  int64 exp = 1;

  int64 *b = (int64*)calloc(tamanho, sizeof(int64));

  for (int64 i = 0; i < tamanho; i++){
    if (vetor[i] > maior)
      maior = vetor[i];
  }

  while (maior / exp > 0) {
    int bucket[10] = {0};
    for (int64 i = 0; i < tamanho; i++)
      bucket[(vetor[i] / exp) % 10]++;

    for (int64 i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    for (int64 i = tamanho - 1; i >= 0; i--)
      b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];

    for (int64 i = 0; i < tamanho; i++)
      vetor[i] = b[i];

    exp *= 10;
  }

  free(b);
}
