
#include <stdio.h>

#include "jemalloc/jemalloc.h"


int main(int argc, char *argv[]) {
  int *ptr1 = NULL;
  int *ptr2 = NULL;
  int i = 0;

  for(i = 0; i < 10; i++) {
    ptr1 = jemalloc_malloc(sizeof(int));
    jemalloc_free(ptr1);
  }

  ptr2 = jemalloc_malloc(100 * sizeof(int));

  for(i = 0; i < 10; i++) {
    ptr1 = jemalloc_malloc(sizeof(int));
    jemalloc_free(ptr1);
  }

  jemalloc_free(ptr2);

  return 0;
}

