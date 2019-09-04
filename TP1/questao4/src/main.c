#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define int64 long long // `int64_t` é {long int}


int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("ARGS: <amount> <path/to/input/file>");
    exit(1);
  }

  unsigned long amount = atol(argv[1]);
  char* filename = argv[2];
  FILE* fd = fopen(filename, "r");

  if (!fd) {
    fprintf(stderr, "Unable to open file '%s'!\n", filename);
    return 1;
  }

  int64 *numArray = (int64*) malloc(sizeof(*numArray) * amount);

  // for (unsigned long i=0; !feof(fd); ++i) {
  for (unsigned long i=0; i < amount; ++i) {
    fscanf(fd, "%lld", &numArray[i]);
    printf("%lld\n", numArray[i]);
  }

  lseek(fd, 0L, SEEK_END);
  long int size = ftell(fd);
  printf("------\n%llu bytes read\n", size);

  fclose(fd);
}
