#include <stdlib.h>

#define MEM_INTERNAL_DEFS
#include "mem.h"

int MEM_API mem_alloc(void *_Dst, uint32_t _Size)
{
  uint8_t *new = (uint8_t *)malloc((size_t)_Size);

  if (new == NULL)
  {
    return MEM_ALLOC_FAILURE;
  }

  *(uint8_t **)_Dst = new;

  return MEM_ALLOC_SUCCESS;
}

int MEM_API mem_alloc_with_size_info(void *_Dst, uint32_t _Size)
{
  uint32_t *new = (uint32_t *)malloc((size_t)(MEM_SIZE_INFO_SIZE + _Size));

  if (new == NULL)
  {
    return MEM_ALLOC_FAILURE;
  }

 *new = _Size;
 *((uint32_t **)_Dst) = ++new;

 return MEM_ALLOC_SUCCESS;
}

int MEM_API mem_get_size(uint32_t *_Size, void *_Ptr)
{
    uint32_t *ptr = (uint32_t *)_Ptr;
    *_Size = *(--ptr);

    return MEM_SUCCESS;
}

int MEM_API mem_get_alloc_size(uint32_t *_Size, void *_Ptr)
{
    uint32_t *ptr = (uint32_t *)_Ptr;
    *_Size = *(--ptr) + MEM_SIZE_INFO_SIZE;

    return MEM_SUCCESS;
}

int MEM_API mem_realloc(void *_New, uint32_t _Size, void *_Old)
{
  uint8_t *new = (uint8_t *)realloc(*(uint8_t **)_Old, (size_t)_Size);

  if (new == NULL)
  {
    return MEM_REALLOC_FAILURE;
  }

  *(uint8_t **)_Old = NULL;
  *(uint8_t **)_New = new;

  return MEM_REALLOC_SUCCESS;
}

int MEM_API mem_realloc_with_size_info(void *_New, uint32_t _Size, void *_Old)
{
  uint32_t *new = (uint32_t *)realloc(*(uint8_t **)_Old - MEM_SIZE_INFO_SIZE, (size_t)(MEM_SIZE_INFO_SIZE + _Size));

  if (new == NULL)
  {
    return MEM_REALLOC_FAILURE;
  }

  *new = _Size;
  *(uint8_t **)_Old = NULL;
  *(uint32_t **)_New = ++new;

  return MEM_REALLOC_SUCCESS;
}

int MEM_API mem_free(void *_Ptr)
{
  free(*(uint8_t **)_Ptr);

  *(uint8_t **)_Ptr = NULL;

  return MEM_FREE_SUCCESS;
}

int MEM_API mem_free_with_size_info(void *_Ptr)
{
  free(*(uint8_t **)_Ptr - MEM_SIZE_INFO_SIZE);

  *(uint8_t **)_Ptr = NULL;

  return MEM_FREE_SUCCESS;
}
