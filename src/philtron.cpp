
/* project includes */

#include "philtron.h"

/* std includes */

#include <stdlib.h>
// size_t
// NULL

#include <dlfcn.h>


static long long int gPeakAllocationSize = 0ull;


/* external calls to be filtered */

extern "C" void *EXTERNAL_MALLOC(size_t s) {

  return NULL;
}

extern "C" void EXTERNAL_FREE(void *ptr) {

  return;
}


/* internal calls */

extern "C" {

static void *
philtron_malloc(size_t s) {

  return NULL;
}


static void
philtron_free(void *ptr) {

  return;
}

} /* extern "C" */


