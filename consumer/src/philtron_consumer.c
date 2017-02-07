
#include <stdio.h>

#include "jemalloc/jemalloc.h"


int main(int argc, char *argv[]) {
  int *ptr = NULL;

  ptr = jemalloc_malloc(sizeof(int));
  jemalloc_free(ptr);

  return 0;
}

