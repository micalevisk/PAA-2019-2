//
//  [quick.c]
//  Created by Micael Levi on 08/19/2016
//  Copyright (c) 2016 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include "quick.h"

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


TComparacao comparar;

void particionar(void** a, int inicio, int fim) {
    int i, j;

    i = inicio;
    j = fim;
    void* x = a[(inicio + fim) / 2];

    while(i <= j) {
		while((comparar(x, a[i]) SINAL 0) && (i < fim)) i++;
        while((comparar(a[j], x) SINAL 0) && (j > inicio)) j--;
        if(i <= j) {
			SWAP(a, i, j);
            i++;
            j--;
        }
    }

    if(j > inicio) particionar(a, inicio, j);
    if(i < fim) particionar(a, i, fim);
}

void quickSort(void** v, unsigned n, TComparacao cmp){
  comparar = cmp;
  particionar(v, 0, n-1);
}
