
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

#include <iostream>
// using std::cerr
// using std::endl

#include <map>
// using std::map

// utility macros

#define STRINGIFY(str) #str
#define XSTRINGIFY(str) STRINGIFY(str)


class AllocationTracker {
public:
  using ptr_t = long long unsigned int;
  using alloc_size_t = long long unsigned int;

  AllocationTracker() = default;
  AllocationTracker(const AllocationTracker &) = default;
  ~AllocationTracker() {
    this->report();

    return;
  }

  void allocate(void *ptr, alloc_size_t size) {
    auto ptr_key = reinterpret_cast<ptr_t>(ptr);

    allocations[ptr_key] = size;
    current_total_memory += size;

    if(current_total_memory > peak_total_memory)
      peak_total_memory = current_total_memory;

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

  void report(void) {
    std::cerr << "memory peak total: " << peak_total_memory << std::endl;

    return;
  }

private:
  std::map<ptr_t, alloc_size_t> allocations;
  alloc_size_t current_total_memory;
  alloc_size_t peak_total_memory;
};


// global objects and functions

static AllocationTracker gAllocationTracker;


// external function wrappers

void *EXTERNAL_MALLOC(size_t s) {
  void *malloc_sym = dlsym(RTLD_NEXT, XSTRINGIFY(EXTERNAL_MALLOC));
  external_malloc_t malloc_cb = reinterpret_cast<external_malloc_t>(malloc_sym);

  assert(malloc_cb != NULL);

  void *ptr = malloc_cb(s);

  if(ptr)
    gAllocationTracker.allocate(ptr, s);

  return ptr;
}

void EXTERNAL_FREE(void *ptr) {
  void *free_sym = dlsym(RTLD_NEXT, XSTRINGIFY(EXTERNAL_FREE));
  external_free_t free_cb = reinterpret_cast<external_free_t>(free_sym);

  assert(free_cb != NULL);

  gAllocationTracker.deallocate(ptr);

  free_cb(ptr);

  return;
}


