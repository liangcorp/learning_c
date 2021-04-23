#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUGMESSAGE(level, fmt, ...) \
  if (level == 1) \
  { \
    fprintf(stderr, fmt, __VA_ARGS__); \
  }

int debug = 0;

int sum(int x, int y, int z) {
  char c = 2;

  #ifdef DEBUG
    DEBUGMESSAGE(2, "c = %d\n", c);
  #endif

  int *a;

  *a = 5;

  #ifdef DEBUG
    DEBUGMESSAGE(2, "*a = %d\n", (int)*a);
  #endif

  return (c + x + y + z + *a) / 3;
}

int main(int argc, char *argv[]) {
  int i, j, k;
  int result;

  #ifdef DEBUG
    DEBUGMESSAGE(1,"i = %d\n", i);
    DEBUGMESSAGE(1, "j = %d\n", j);
    DEBUGMESSAGE(1, "k = %d\n", k);
  #endif


  if (argc < 4) {
     printf("Please specify three numbers as parameters.\n");
     exit(1);
  }

  debug = atoi(argv[1]);
  i = atoi(argv[2]);
  j = atoi(argv[3]);
  k = atoi(argv[4]);

  #ifdef DEBUG
    DEBUGMESSAGE(1, "i = %d\n", i);
    DEBUGMESSAGE(1, "j = %d\n", j);
    DEBUGMESSAGE(1, "k = %d\n", k);
  #endif

  result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);

  #ifdef DEBUG
    DEBUGMESSAGE(1, "result = %d\n", result);
  #endif

  printf("%d\n", result);

  return 0;
}
