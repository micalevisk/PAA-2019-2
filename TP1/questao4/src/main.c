// cd questao4
// pipenv run scripts/generate_input.py 10000 B "__input.10000"
// cc src/**/*.c -I./src/headers -D DEBUG -D VERBOSE -o main.exe && ./main.exe h 10000 "__input.10000"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "algorithms.h"

#ifdef VERBOSE
  #define __log__(fmt,...) fprintf(stdout, "L%d\t" fmt "\n", __LINE__, ##__VA_ARGS__);
#else
  #define __log__(...) ; // do nothing
#endif

/*
#ifdef DEBUG
  #define __debug__(fmt,...) fprintf(stdout, fmt "\n", ##__VA_ARGS__);
#else
  #define __debug__(...) ; // do nothing
#endif
*/

#define err(fmt,...) fprintf(stderr, fmt "!\n", ##__VA_ARGS__);


#define GET_MS(ini, fim) ((fim.tv_sec * 1000000 + fim.tv_usec) - (ini.tv_sec * 100000 + ini.tv_usec))

void runSorter(Sorter sort, int64* data, uint64 nitems) {
  clock_t start = clock(); // (c) https://stackoverflow.com/questions/5248915
  sort(data, nitems);
  clock_t stop = clock();
  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  //                                        ^ in milliseconds
  fprintf(stdout, "%.2f\n", elapsed);
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("ARGS: [heap|quick|radix] <amount> <path/to/input/file>\n");
    exit(1);
  }

  srand(time(NULL));

  char* algorithm = argv[1];
  uint64 amount = atol(argv[2]);
  char* filename = argv[3];

  __log__("will open file: '%s'", filename)
  FILE* fd = fopen(filename, "r");

  if (!fd) {
    __log__("can't open file")
    err("Unable to open file '%s'", filename);
    return 1;
  }

  __log__("will alloc array with %lu int64-elements ", amount)
  int64* numArray = (int64*) malloc(sizeof(*numArray) * amount);

  /* Lendo para do arquivo para a estrutura de dados em memória */
  for (uint64 i=0; (i < amount) && !feof(fd); ++i) {
    fscanf(fd, "%ld", &numArray[i]);
  }

  // fseek(fd, 0L, SEEK_END);
  long int size = ftell(fd);
  __log__("%ld bytes read", size)
  __log__("will close the file")
  fclose(fd);

  char algorithmId = algorithm[0];
  switch(algorithmId) {
    case 'h':
      __log__("will run heapsort")
      runSorter(heapsort, numArray, amount);
      break;
    case 'q':
      break;
    case 'r':
      break;
    default:
      err("Unknown algorithm: '%c'", algorithmId);
  }

  #ifdef DEBUG
  printAll(numArray, amount);
  #endif
  free(numArray);

  return 0;
}
