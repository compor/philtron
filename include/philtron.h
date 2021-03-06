
#ifndef PHILTRON_H
#define PHILTRON_H


// required definition for RTLD_NEXT
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif // _GNU_SOURCE


// c includes

#include <stdlib.h>
// using size_t


// external function wrappers

#define EXTERNAL_MALLOC jemalloc_malloc
#define EXTERNAL_FREE jemalloc_free

typedef void *(*external_malloc_t)(size_t);
typedef void (*external_free_t)(void *);

extern "C" {
  void *EXTERNAL_MALLOC(size_t);
  void EXTERNAL_FREE(void *);
}


#endif // PHILTRON_H

