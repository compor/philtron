
#include <stdio.h>

#include "jemalloc/jemalloc.h"


int main(int argc, char *argv[]) {
  int *ptr = NULL;
  int i = 0;

  for(i = 0; i < 10; i++) {
    ptr = jemalloc_malloc(sizeof(int));
    jemalloc_free(ptr);
  }

  return 0;
}

