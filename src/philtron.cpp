
// project includes

#include "philtron.h"

// c includes

#include <stdlib.h>
// using size_t
// using NULL

#include <assert.h>
// using assert

#include <dlfcn.h>

// cxx includes

#include <map>
// using std::map


class AllocationTracker {
public:
  using ptr_t = long long unsigned int;
  using alloc_size_t = long long unsigned int;

  AllocationTracker() = default;
  AllocationTracker(const AllocationTracker &) = default;
  ~AllocationTracker() = default;

  void allocate(void *ptr, alloc_size_t size) {
    auto ptr_key = reinterpret_cast<ptr_t>(ptr);

    allocations[ptr_key] = size;

    return;
  }

  void deallocate(void *ptr) {
    auto ptr_key = reinterpret_cast<ptr_t>(ptr);

    auto found = allocations.find(ptr_key);
    if(found != allocations.end()) {
      allocations.erase(found);
    }

    return;
  }

private:
  std::map<ptr_t, alloc_size_t> allocations;

};


static AllocationTracker gAllocationTracker;


/* external calls to be filtered */

extern "C" void *EXTERNAL_MALLOC(size_t s) {
  void *malloc_sym = dlsym(RTLD_NEXT, STRINGIFY(EXTERNAL_MALLOC));
  external_malloc_t malloc_cb = reinterpret_cast<external_malloc_t>(malloc_sym);

  assert(malloc_cb != NULL);

  void *ptr = malloc_cb(s);

  if(ptr)
    gAllocationTracker.allocate(ptr, s);

  return ptr;
}

extern "C" void EXTERNAL_FREE(void *ptr) {
  void *free_sym = dlsym(RTLD_NEXT, STRINGIFY(EXTERNAL_FREE));
  external_free_t free_cb = reinterpret_cast<external_free_t>(free_sym);

  assert(free_cb != NULL);

  gAllocationTracker.deallocate(ptr);

  free_cb(ptr);

  return;
}


/* internal calls */




