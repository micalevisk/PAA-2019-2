#include "algorithms.h"

/*
Pior caso:
T(n) = T(n-1) + T(0) + Θ(n)
O(n²)
Melhor caso:
T(n) = 2T(n/2) + Θ(n)
O(nlogn)
------------------------------------------------------
algorithm quicksort(A, lo, hi) is
    if lo < hi then
        p := particiona(A, lo, hi)
        quicksort(A, lo, p – 1)
        quicksort(A, p + 1, hi)

algorithm particiona(A, lo, hi) is
    pivot := A[hi]
    i := lo - 1
    for j := lo to hi - 1 do
        if A[j] < pivot then
            i := i + 1
            swap A[i] with A[j]
    if pivot < A[i + 1] then
        swap A[i + 1] with A[hi]
    return i + 1
------------------------------------------------------
*/

// Codificado como o pseudo-código do Cormem p.124
uint64 partition(int64* arr, int64 inicio, int64 fim) {
  int64 pivo = arr[fim];
  int64 i = inicio - 1;

  for (uint64 j=inicio; j < fim; ++j) {
    if (arr[j] <= pivo) {
      ++i;
      swap(arr, i, j);
    }
  }

  swap(arr, i + 1, fim);
  return i + 1;
}

void sort(int64* arr, int64 inicio, int64 fim) {
  if (inicio < fim) {
    int64 meio = partition(arr, inicio, fim);
    sort(arr, inicio, meio - 1);
    sort(arr, meio + 1, fim);
  }
}

void quicksort(int64* arr, uint64 n) {
  sort(arr, 0, n);
}
