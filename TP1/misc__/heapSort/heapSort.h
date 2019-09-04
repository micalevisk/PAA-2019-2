#ifndef HEAPSORT_H
#define HEAPSORT_H


// define o tipo de ordenação
// '>' para ordenação crescente
// '<' para ordenação decrescente
#define SINAL >

#include <stdio.h>
#include <stdlib.h>

// deve retornar:
// > 0 se 'a' for MAIOR que 'b'
// < 0 se 'a' for MENOR que 'b'
// = 0 se 'a' for IGUAL a 'b'
typedef short	(*TComparacao)(void* a,void* b);
typedef void	(*TImpressao)(void*);
void imprimirVetorGenerico(void** v, unsigned, TImpressao);


// ORDENAÇÃO POR HEAP: [INSTÁVEL]
// espaço extra constante;
//
// melhor: O(n logn) | pior: O(n logn)
//
// melhor caso:
// pior caso: há alto consumo de memória;
//
// COMPARAÇÕES  = 2*n * logn + 2*n
// MOVIMETAÇÕES =
//
void heapSort(void** vetor, unsigned tamanho, TComparacao);


/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE:
-------------------------------------------------------------------------
Recebe:
- um array 'vetor'
- quantidade 'N' de elementos nesse array


Heapify(array, pai, posUltimo)
{
  esq := 2 * pai + 1
  dir := esq + 1
  posMaior := pai;

  Se esq < posUltimo, então
    Se array[esq] > array[pai], então
      posMaior := esq
    Fim-se
    Se dir <= posUltimo e array[dir] > array[posMaior], então
      posMaior := dir
    Fim-se
  Fim-se

  Se posMaior != pai, então
    Swap(array[posMaior], array[pai])
    Heapify(array, posMaior, posUltimo)
  Fim-se
}

BuildHeap(array, n)
{
  Para i de (n-1)/2 até 0, faça
    heapify(array, i, n-1)
  Fim-para
}

HeapSort(vetor, N)
{
  BuildHeap(vetor, N)

  Para i de N-1 até 1, faça
    Swap(vetor[i], vetor[0])
    i := i - 1
    Heapify(vetor, 0, i)
  Fim-Para
}
-------------------------------------------------------------------------
*/


#endif

// https://www.cs.usfca.edu/~galles/visualization/HeapSort.html
