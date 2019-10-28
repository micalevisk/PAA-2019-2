#include "algorithms.h"

/*
(c) https://pt.wikipedia.org/wiki/Heapsort
Pior caso:
T(n) = T(n-1) + T(0) + Θ(n)
Melhor caso:
T(n) = 2T(n/2) + Θ(n)
-------------------------------------------------------------------------
______________
Rotina_Heapify
	Recebe:
	- um array 'vetor'
	- números 'pai' e 'posUltimo'

	eqs := 2 * pai + 1
	dir := esq + 1
	posMaior := pai

	Se esq < posUltimo, então
		Se vetor[esq] > vetor[pai], então
			posMaior := esq
		Se dir <= posUltimo e vetor[dir] > vetor[posMaior], então
			posMaior := dir
	Se posMaior != pai, então
		Swap(vetor[posMaior], vetor[pai])
		Rotina_Heapify(vetor, posMaior, posUltimo)

________________
Rotina_BuildHeap
	Recebe:
	- um array 'vetor'
	- quantidade 'N' de elementos nesse array

	Para i de (N-1)/2 até 0, faça
		Rotina_Heapify(vetor, i, n-1)

_______________
Rotina_Heapsort
	Recebe:
	- um array 'vetor'
	- quantidade 'N' de elementos nesse array

	Rotina_BuildHeap(vetor, N)
	Para i de N-1 até 1, faça
		Swap(vetor[i], vetor[0])
		i := i - 1
		Rotina_Heapify(vetor, 0, i)
-------------------------------------------------------------------------
*/


void maxHeapify(int64 *arr, int64 pai, int64 posUltimo) {
  int64 esq, dir, posMaior;
  esq = 2 * pai + 1;
  dir = esq + 1;
  posMaior = pai;

  if ((esq <= posUltimo) && (arr[esq] > arr[posMaior]))
    posMaior = esq;

  if ((dir <= posUltimo) && (arr[dir] > arr[posMaior]))
    posMaior = dir;

  if (posMaior != pai) {
    swap(arr, pai, posMaior);
    maxHeapify(arr, posMaior, posUltimo);
  }
}

void buildHeap(int64 *arr, uint64 n) {
  for (int64 i=(n-1)/2; i >= 0; --i)
    maxHeapify(arr, i, n-1);
}

void heapsort(int64 *vetor, uint64 tamanho) {
  buildHeap(vetor, tamanho);
  for (int64 i=tamanho-1; i > 0; ){
    swap(vetor, i, 0);
    --i;
    maxHeapify(vetor, 0, i);
  }
}
