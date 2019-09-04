#include "radix.h"
#include <stdio.h>
#include <stdlib.h>


// ======================================================= //

short cmp(void* a, void* b){
  if(!a || !b) return 0;
  int* A = a;
  int* B = b;
  return (*A > *B ? 1 : (*A < *B ? -1 : 0));
}

void imprimirElemento(void* a){
  if(!a) return;
  printf("%d ", *((int*)a));
}



// int main(int argc, char *argv[]) {
// 	if(argc < 1) return 1;
//
//   unsigned tam = argc-1;
// 	int* v = calloc(tam, sizeof(int));
// 	int i;
// 	for(i=0; i < tam; i++) v[i] = atoi(argv[i+1]); // ler argumentos da linha de comando.
// 	void** vetor = malloc(sizeof(void*)*tam); // armazena os endereços dos elementos lidos.
// 	for(i=0; i < tam; i++) vetor[i] = &v[i];
//
//   printf("\nANTES DA ORDENAÇÃO: ");
//   imprimirVetorGenerico(vetor, tam, imprimirElemento);
//
//   printf("\nDEPOIS DA ORDENAÇÃO: ");
//   insertionSort(vetor, tam, cmp);
//   imprimirVetorGenerico(vetor, tam, imprimirElemento);
//
//   return 0;
// }
