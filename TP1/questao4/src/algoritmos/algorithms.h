#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define int64 long long // `int64_t` é {long int}
#define uint64 unsigned long long

typedef void (*Sorter)(int64*, uint64);

// [a,b] => [b,a]
void swap(int64* a, int64* b) {
  int64 aux = *a;
  *a = *b;
  *b = aux;
}

// Sorter heapsort;
void heapsort(int64* v, uint64 n);

#endif
