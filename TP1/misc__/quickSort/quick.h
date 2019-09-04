#ifndef QUICK_H
#define QUICK_H


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


// ORDENAÇÃO POR PARTICIONAMENTO: [INSTÁVEL]
// espaço extra logarítmico;
//
// melhor: O(n logn) | pior: O(n²)
//
// melhor caso:
// pior caso:
//
// COMPARAÇÕES  = 2*n logn
// MOVIMETAÇÕES = (1/3)*n logn
//
void quickSort(void** v, unsigned n, TComparacao cmp);


/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE:
-------------------------------------------------------------------------
Recebe:
- um array 'vetor'
- quantidade 'N' de elementos nesse array

Particionar(array, inicio, fim)
{
  Se fim > inicio, então
    i := inicio
    j := fim
    pivot := array[(i+j)/2]

    Fazer,
      Enquanto array[i] < pivot, faça
        i := i + 1
      Fim-enquanto

      Enquanto array[j] > pivot, faça
        j := j - 1
      Fim-enquanto

      Se i <= j, então
        Swap(array[i], array[j])
        i := i + 1
        j := j - 1
      Fim-se
    Enquanto i <= j, repetir processo anterior

    Se inicio < j, então
      Particionar(array, inicio, j)
    Fim-se

    Se i < fim, então
      Particionar(array, i, fim)
    Fim-se
  Fim-se
}

QuickSort(vetor, N)
{
  Particionar(vetor, 0, N-1)
}

-------------------------------------------------------------------------
*/


#endif
