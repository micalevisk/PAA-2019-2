/*
cd questao4
pipenv run scripts/generate_input.py 10000 B "input"
cc src/main.c src/algoritmos/*.c -I./src/algoritmos -o main && ./main h 10000 "input"
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "algorithms.h"

#define GET_MS(ini, fim) ((fim.tv_sec * 1000000 + fim.tv_usec) - (ini.tv_sec * 100000 + ini.tv_usec))


int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("ARGS: [heap|quick|radix] <amount> <path/to/input/file>\n");
    exit(1);
  }

  char* algorithm = argv[1];
  unsigned long amount = atol(argv[2]);
  char* filename = argv[3];
  FILE* fd = fopen(filename, "r");

  if (!fd) {
    fprintf(stderr, "Unable to open file '%s'!\n", filename);
    return 1;
  }

  int64 *numArray = (int64*) malloc(sizeof(*numArray) * amount);

  // for (unsigned long i=0; !feof(fd); ++i) {
  for (unsigned long i=0; i < amount; ++i) {
    fscanf(fd, "%lld", &numArray[i]);
    #ifdef DEBUG
    printf("%lld\n", numArray[i]);
    #endif
  }

  fseek(fd, 0L, SEEK_END);
  long int size = ftell(fd);
  printf("------\n%ld bytes read\n", size);
  fclose(fd);

  switch (algorithm[0])  {
    case 'h':
      heapsort(numArray, amount);
      break;
    case 'q':
      break;
    case 'r':
      break;
    default:  
      printf("Unknown algorithm: '%c'\n", algorithm[0]);
  }

  free(numArray);

  // struct timeval start, stop;
  // gettimeofday(&start, NULL);
  // gettimeofday(&start, NULL);
  // GET_MS(start, stop)
}
