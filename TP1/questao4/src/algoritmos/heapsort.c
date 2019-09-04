#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE O(nlogn) ou O(nlogn):
// COMPARAÇÕES  = 2*n*logn+2*n
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

void* sort(void* arr, size_t size, unsigned long nitems) {
  return NULL;
}
