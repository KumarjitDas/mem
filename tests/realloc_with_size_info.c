#include <stdio.h>
#include "mem.h"

int main(int argc, char **argv)
{
  int32_t *arr, *new_arr;
  uint32_t size, new_size, alloc_size, new_alloc_size;
  int res;

  (void)argc, (void)argv;

  res = mem_alloc_with_size_info(&arr, sizeof(*arr));

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

  res = mem_get_alloc_size(&alloc_size, arr);

  if (res == MEM_FAILURE)
  {
    (void)printf("Could not get allocated size of memory.\n");
    (void)mem_free_with_size_info(&arr);

    return 1;
  }

  (void)printf("Location: %p, Size: %d, Allocated Size: %d, Value: %d\n", (void *)arr, size, alloc_size, *arr);

  res = mem_realloc_with_size_info(&new_arr, sizeof(*new_arr) * 2, &arr);

  if (res == MEM_ALLOC_FAILURE)
  {
    (void)printf("Could not reallocate memory.\n");
    return 1;
  }

  *new_arr = 69;
  res = mem_get_size(&new_size, new_arr);

  if (res == MEM_FAILURE)
  {
    (void)printf("Could not get size of memory.\n");
    (void)mem_free_with_size_info(&new_arr);

    return 1;
  }

  res = mem_get_alloc_size(&new_alloc_size, new_arr);

  if (res == MEM_FAILURE)
  {
    (void)printf("Could not get allocated size of memory.\n");
    (void)mem_free_with_size_info(&new_arr);

    return 1;
  }

  (void)printf("Old Location: %p\n", (void *)arr);
  (void)printf("Location: %p, Size: %d, Allocated Size: %d, Value: %d\n", (void *)new_arr, new_size, new_alloc_size, *new_arr);
  (void)mem_free_with_size_info(&new_arr);
  (void)printf("New Location: %p\n", (void *)new_arr);

  return 0;
}
