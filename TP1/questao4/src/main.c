//
//  [main.cc]
//  Created by Micael Levi on 09/03/2019
//  Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "io.h"


#define N_ARGS 2
#define MSG_USO {\
  fprintf(stdout, "USO:\n$ %s <instancia> <caminho/arquivo/saida>\n", argv[0]);\
  return 1;\
  }


/*
int main(int argc, char *argv[]) {
  // alocar um array de inteiros dinamicamente e escrever num arquivo binário
  if (argc < N_ARGS) MSG_USO;

  // Define parameters
  char* ptr;
  unsigned long instance = strtoul(argv[1], &ptr, 10);
  char* outputFilepath = argv[2];

  // FILE *fopen(const char *restrict pathname, const char *restrict mode)
  FILE* outputFile = fopen(outputFilepath, "wb");

  int vParaGravar[] = {5464646,21564,-3,4,5};
  bool wrriten = writeData((void*)vParaGravar, sizeof(int), 5, outputFile);
  if (wrriten) {
    ok_printf("Arquivo '%s' escrito com sucesso :)\n", outputFilepath);
  } else {
    ok_printf("Erro ao escrever no arquivo :('%s'\n", outputFilepath);
  }

  fclose(outputFile);

  #ifdef FOO
  int inputArray[5];
  FILE* inputFile = fopen(outputFilepath, "rb");
  bool read = readDataFromFile(inputFile, (void*)inputArray, sizeof(int), 5);
  fclose(inputFile);

  if (read) {
    ok_printf("%d, %d, %d, %d, %d \n", inputArray[0], inputArray[1], inputArray[2], inputArray[3], inputArray[4]);
  } else {
    ok_printf("Erro ao ler o arquivo '%s'\n", outputFilepath);
  }
  #endif

  return 0;
}
*/


/*
N = 5
rand que será repetido = -4
piso de 90% = 4
-4,-4,-4,-4,a
*/

int main() {
  srand(time(NULL));
  // https://www.thinkage.ca/gcos/expl/c/lib/lrand4.html
  // return non-negative long integers uniformly distributed over the interval [ 0 , 2^31)
  long int f = lrand48();
  printf("%li\n", f);
}
