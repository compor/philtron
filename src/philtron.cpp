
// project includes

#include "philtron.h"

// c includes

#include <stdlib.h>
// using size_t
// using NULL

#include <dlfcn.h>

// cxx includes

#include <map>
// using std::map


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


