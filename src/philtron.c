
/* project includes */

#include "philtron.h"

/* std includes */

#include <stdlib.h>
// size_t
// NULL

#include <dlfcn.h>


static long long int gPeakAllocationSize = 0ull;


/* external calls to be filtered */

void *EXTERNAL_MALLOC(size_t s) {

  return NULL;
}

void EXTERNAL_FREE(void *ptr) {

  return;
}


/* internal calls */

static void *
philtron_malloc(size_t s) {

  return NULL;
}


static void
philtron_free(void *ptr) {

  return;
}


