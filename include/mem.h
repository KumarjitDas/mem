#ifndef _MEM_H_
#define _MEM_H_

#include <stdint.h>
#include <stddef.h>

#define MEM_ALLOCATE_SUCCESS    0
#define MEM_ALLOCATE_FAILURE    1
#define MEM_REALLOCATE_SUCCESS  0
#define MEM_REALLOCATE_FAILURE  1
#define MEM_FREE_SUCCESS        0
#define MEM_FREE_FAILURE        1

#ifdef MEM_INTERNAL_DEFS

  #define MEM_SIZE_INFO_SIZE (sizeof(uint32_t))

#endif  /* MEM_INTERNAL_DEFS */

int mem_allocate(void *ref, uint32_t size);
int mem_allocate_with_size_info(void *ref, uint32_t size);
uint32_t mem_get_size(void *ref);
int mem_reallocate(void *new_ref, uint32_t new_size, void *old_ref);
int mem_reallocate_with_size_info(void *new_ref, uint32_t new_size, void *old_ref);
int mem_free(void *ref);
int mem_free_with_size_info(void *ref);

#endif  /* _MEM_H_ */
