#ifndef RADIX_H
#define RADIX_H

// define o tipo de ordenação
// '>' para ordenação crescente
// '<' para ordenação decrescente
#define SINAL >

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// deve retornar:
// > 0 se 'a' for MAIOR que 'b'
// < 0 se 'a' for MENOR que 'b'
// = 0 se 'a' for IGUAL a 'b'
typedef short	(*TComparacao)(void* a,void* b);
typedef void	(*TImpressao)(void*);
typedef unsigned (*TGetKey)(void*);
void imprimirVetorGenerico(void** v, unsigned, TImpressao);

// ORDENAÇÃO POR RADIX: [ESTÁVEL]
// conjuntos com chaves únicas;
//
// Pelo MSB, se for conhecido um número mínimo de dígitos
// necessário para distinguir todos os elementos, então somente esse número
// de dígitos precisa ser examinado.
// No LSD será necessário a complementação das chaves de tamanho variável,
// já que todos os dígitos precisam ser examinados.
//
// melhor: O(nk) | pior: O(d(n + k))
// - k = número de compartimentos
// - d = quantidade de dígitos das chaves (devem ser iguais)
//
void radixSort(void** v, unsigned n, TComparacao cmp, TGetKey chv);

/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE PARA NÚMEROS (começando pelo LSD):
-------------------------------------------------------------------------
Recebe:
- um array 'vetor'
- quantidade 'N' de elementos nesse array

d := quantidade de dígitos dos elementos

Para i de 0 até d-1, faça
  Usar ordenação estável (countingSort ou bubbleSort) para ordenar vetor pelo i-ésimo dígito
Fim-para
-------------------------------------------------------------------------
*/


#endif


//	https://www.cs.usfca.edu/~galles/visualization/RadixSort.html
