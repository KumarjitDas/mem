#include <stdlib.h>
#include <stddef.h>

#define MEM_INTERNAL_DEFS
#include "mem.h"

int mem_allocate(void *ref, uint32_t size) {
  uint8_t *new_mem = (uint8_t *) malloc((size_t) size);

  if (new_mem == NULL) {
    return MEM_ALLOCATE_FAILURE;
  }

  *((uint8_t **) ref) = new_mem;
  return MEM_ALLOCATE_SUCCESS;
}

int mem_allocate_with_size_info(void *ref, uint32_t size) {
  uint32_t *new_mem;
  int stat = mem_allocate(&new_mem, MEM_SIZE_INFO_SIZE + size);

  if (stat == MEM_ALLOCATE_FAILURE) {
    return MEM_ALLOCATE_FAILURE;
  }

 *new_mem = size;
 *((uint32_t **) ref) = ++new_mem;

 return MEM_ALLOCATE_SUCCESS;
}

uint32_t mem_get_size(void *ref) {
  uint32_t *this_ref = *(uint32_t **) ref; 
  return *(--this_ref);
}

int mem_reallocate(void *new_ref, uint32_t new_size, void *old_ref) {
  uint8_t *old_ref_ptr = *(uint8_t **) old_ref;
  uint8_t *new_mem = (uint8_t *) realloc(old_ref_ptr, (size_t) new_size);

  if (new_mem == NULL) {
    return MEM_REALLOCATE_FAILURE;
  }

  old_ref_ptr = NULL;
  *(uint8_t **) new_ref = new_mem;

  return MEM_REALLOCATE_SUCCESS;
}

int mem_reallocate_with_size_info(void *new_ref, uint32_t new_size, void *old_ref) {
  uint32_t *new_mem;
  int stat = mem_reallocate(&new_mem, new_size, old_ref);

  if (stat == MEM_REALLOCATE_FAILURE) {
    return MEM_REALLOCATE_FAILURE;
  }

  *new_mem = new_size;
  *(uint32_t **) old_ref = NULL;
  *(uint32_t **) new_ref = ++new_mem;

  return MEM_REALLOCATE_SUCCESS;
}

int mem_free(void *ref) {
  uint8_t *ptr = *(uint8_t **) ref;
  free(ptr);
  ptr = NULL;
  return MEM_FREE_SUCCESS;
}

int mem_free_with_size_info(void *ref) {
  uint8_t *ptr = *(uint8_t **) ref - MEM_SIZE_INFO_SIZE;
  int stat = mem_free(&ptr);

  if (stat == MEM_FREE_FAILURE) {
    return MEM_FREE_FAILURE;
  }

  *(uint8_t **) ref = NULL;
  return MEM_FREE_SUCCESS;
}
