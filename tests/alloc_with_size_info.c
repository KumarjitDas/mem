#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "mem.h"

int main(int argc, char **argv)
{
  int32_t *arr;
  uint32_t size;
  int res;

  (void)argc, (void)argv;
  
  res = mem_alloc_with_size_info(&arr, sizeof(*arr) * 4);

  if (res == MEM_ALLOC_FAILURE)
  {
    (void)printf("Could not allocate memory.\n");
    return 1;
  }

  *arr = 42;
  res = mem_get_size(&size, arr);
  
  if (res == MEM_FAILURE)
  {
    (void)printf("Could not get size of memory.\n");
    (void)mem_free_with_size_info(&arr);

    return 1;
  }

  (void)printf("Location: %p, Size: %d, Value: %d\n", (void *)arr, size, *arr);
  (void)mem_free_with_size_info(&arr);
  (void)printf("Location: %p\n", (void *)arr);

  return 0;
}
