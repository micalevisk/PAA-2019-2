// clear;gcc -o t radixLSD2.c && ./t 6 1 5 4 7 2 30 0 8 9;rm t*
#include <stdio.h>
#include <stdlib.h>

int largest(int v[], int n){
  int maior = v[0], i;
  for(i=1; i<n; i++)
    if(v[i] > maior) maior = v[i];
  return maior;
}

void RadixSort(int v[], int n){
  int bucket[10][10], bucket_count[10];
  int i,j,k, rmd, NOP=0, divisor=1, large, pass;

  large = largest(v,n);
  // printf("The large element %d\n", large);

  while(large > 0){
    NOP++;
    large /= 10;
  }

  for(pass=0; pass < NOP; ++pass){
    for(i=0; i < 10; ++i) bucket_count[i] = 0;
    for(i=0; i < n; ++i){
      rmd = (v[i]/divisor) % 10;
      bucket[rmd][bucket_count[rmd]] = v[i];
      bucket_count[rmd]++;
    }

    i=0;
    for(k=0; k < 10; ++k){
      for(j=0; j < bucket_count[k]; ++j){
        v[i] = bucket[k][j];
        ++i;
      }
    }
    divisor *= 10;

    // for(i=0; i < n; ++i) printf("%d ", v[i]);
    // printf("\n");
  }

}

int main(int argc, char** argv){
  if(argc < 1) return 1;

  unsigned tam = argc-1;
  int* v = calloc(tam, sizeof(int));
  int i;
  for(i=0; i < tam; i++) v[i] = atoi(argv[i+1]); // ler argumentos da linha de comando.

  printf("\nANTES DA ORDENAÇÃO: ");
  for(i=0; i < tam; ++i) printf("%d, ", v[i]);

  printf("\nDEPOIS DA ORDENAÇÃO: ");
  RadixSort(v, tam);
  for(i=0; i < tam; ++i) printf("%d, ", v[i]);

  return 0;
}
