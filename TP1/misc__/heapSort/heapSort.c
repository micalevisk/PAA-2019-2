//
//	[heapSort.c]
//	Created by Micael Levi on 08/18/2016
//	Copyright (c) 2016 mllc@icomp.ufam.edu.br; All rights reserved.
//


#include "heapSort.h"


#define SWAP(arr, a, b) \
{ \
  void* tmp = arr[a]; \
  arr[a] = arr[b]; \
  arr[b] = tmp; \
}


void imprimirVetorGenerico(void** v, unsigned tam, TImpressao imprimir){
	if(!v) printf("NULL\n");
	else{
		int i;
		for(i=0; i < tam; i++) imprimir(v[i]);
	}
	printf("\n");
}



/*================ FUNÇÕES AUXILIARES ==================*/

// Heapify:
// Garante a manutenção da propriedade ordem do Heap. O(log n)
static void ajustarHeap(void** vetor, unsigned pai, int posUltimo, TComparacao comparar){
	unsigned esq, dir, posMaior;

	esq = 2*pai + 1;
	dir = esq + 1;
	posMaior = pai;
	if((esq <= posUltimo) && (comparar(vetor[esq],vetor[posMaior]) SINAL 0))	posMaior = esq;
	if((dir <= posUltimo) && (comparar(vetor[dir],vetor[posMaior]) SINAL 0))	posMaior = dir;

	if(posMaior != pai){
		SWAP(vetor, pai, posMaior);
		ajustarHeap(vetor, posMaior, posUltimo, comparar);
	}
}


// Build-Heap:
// Produz um heap a partir de um vetor não ordenado. O(n)
static void transformarEmHeap(void** vetor, unsigned n, TComparacao comparar){
	int i;
	for(i=(n-1)/2; i >= 0; --i)
		ajustarHeap(vetor, i, n-1, comparar);
}


/*==================================================================*/


void heapSort(void** vetor, unsigned n, TComparacao comparar){
	transformarEmHeap(vetor, n, comparar); // build_heapMax
	int i;
	for(i=n-1; i > 0; ){
		SWAP(vetor, i, 0);
		ajustarHeap(vetor, 0, --i, comparar);
	}
}
