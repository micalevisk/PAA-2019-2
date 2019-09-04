//
//	[radix.c]
//	Created by Micael Levi on 09/04/2016
//	Copyright (c) 2016 mllc@icomp.ufam.edu.br; All rights reserved.
//
//	https://www.youtube.com/watch?v=YXFI4osELGU
//

// TODO: continuar implementação.

#include "radix.h"


void imprimirVetorGenerico(void** v, unsigned tam, TImpressao imprimir){
	if(!v) printf("NULL\n");
	else{
		int i;
		for(i=0; i < tam; i++) imprimir(v[i]);
	}
	printf("\n");
}


TComparacao comparar; // função que compara chaves associada aos valores passados
TGetKey chave;        // função que retorna a chave associada a um elemento neutro

static unsigned qtdDigitos(unsigned numero){
	unsigned i;
	for(i=1; numero >= pow(10,i); ++i);
}

static unsigned maiorChave(void** v, unsigned n){
  if(n > 0){
    unsigned i;
    void* maior = v[0];
    for(i=1; i < n; ++i)
      if(comparar(v[i], maior) > 0) maior = v[i];
    return chave(maior);
  }
  return 0;
}


void radixSort(void** v, unsigned n, TComparacao cmp, TGetKey chv){
	cmp = comparar;
	chave = chv;

	// contar quantidade de dígitos das chaves (encontrar maior chave e contar os dígitos)
	unsigned nDigitos = qtdDigitos(maiorChave(v, n));


}

int main(int argc, char** argv){
	unsigned n =  atoi(argv[1]);


	printf("n  = %u\ni = %u\n", n, i);

}
