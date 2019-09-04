#ifndef HEAPSORT_H
#define HEAPSORT_H


/* TAD HEAP GENERICO & DINAMICO - interface */
// ESQ(i) = 2i+1 			= i << 1 | 1
// DIR(i) = 2i+2 			=	(i << 1) + 2
// PAI(i) = (i-1)/2		= (i + (~1|1)) >> 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


typedef struct tipoHeap THeap;
typedef short			(*TComparacao)(void*,void*);
typedef short 		(*TInserir)	(THeap*,void*);
typedef void*			(*TRaiz)		(THeap*);
typedef void 			(*TRemover)	(THeap*);
typedef void*			(*TAcessar)	(THeap*,unsigned);
typedef int 			(*TVazia)		(THeap*);
typedef unsigned	(*TAltura)	(THeap*);

struct tipoHeap{
	void* dados;

	// Define o tipo de comparação de acordo com o tipo de Heap:
	// Se retornar TRUE quando a > b ==> Heap de Máxima
	// Se retornar TRUE quando a < b ==> Heap de Mínima
	TComparacao comparar;

	TInserir inserir;
	TRaiz raiz;
	TRemover remover;
	TAcessar acessar;
	TVazia vazia;
	TAltura altura;
};

unsigned tamanho(THeap*);
THeap* criarHeap(TComparacao);
void destruirHeap(THeap*);
void percorrer(THeap*, void (*)(void*));
void transformarEmHeap(void**, unsigned, TComparacao);
void transformarEmHeap2(void**, unsigned, TComparacao);

void heapSort(void** vetor, unsigned tamanho, TComparacao);


#endif
