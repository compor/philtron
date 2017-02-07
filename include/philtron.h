
#ifndef PHILTRON_H
#define PHILTRON_H

#include <stdlib.h>


/* external calls to be filtered */

#define EXTERNAL_MALLOC jemalloc_malloc
#define EXTERNAL_FREE jemalloc_free

typedef void *(*external_malloc_t)(size_t);
typedef void (*external_free_t)(void *);


#endif /* PHILTRON_H */

