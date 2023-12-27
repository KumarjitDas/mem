#include <stdio.h>
#include "mem.h"

int main(int argc, char **argv)
{
  int32_t *arr, *new_arr;
  int res;

  (void)argc, (void)argv;
  
  res = mem_alloc(&arr, sizeof(*arr));

  if (res == MEM_ALLOC_FAILURE)
  {
    (void)printf("Could not allocate memory.\n");
    return 1;
  }

  *arr = 42;
  (void)printf("Location: %p, Value: %d\n\n", (void *)arr, *arr);

  res = mem_realloc(&new_arr, sizeof(*new_arr) * 2, &arr);
  
  if (res == MEM_ALLOC_FAILURE)
  {
    (void)printf("Could not reallocate memory.\n");
    return 1;
  }
  
  *new_arr = 69;

  (void)printf("Old Location: %p\n", (void *)arr);
  (void)printf("New Location: %p, Value: %d\n", (void *)new_arr, *new_arr);
  (void)mem_free(&new_arr);
  (void)printf("New Location: %p\n", (void *)new_arr);

  return 0;
}
