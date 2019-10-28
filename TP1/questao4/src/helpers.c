#include <stdio.h>
#include "dtypes.h"

void swap(int64* arr, uint64 aIdx, uint64 bIdx) {
  int64 temp = arr[aIdx];
  arr[aIdx] = arr[bIdx];
  arr[bIdx] = temp;
}

void printAll(int64* data, uint64 nitems) {
  if (data) {
  for (uint64 i=0; i < nitems; ++i)
    fprintf(stdout, "%ld\n", data[i]);
  }
}
