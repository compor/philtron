
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

  void deallocate(ptr_t ptr) {
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

  return NULL;
}

extern "C" void EXTERNAL_FREE(void *ptr) {

  return;
}


/* internal calls */




