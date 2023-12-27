#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "mem.h"

int main(int argc, char **argv)
{
  int32_t *arr;
  int res;

  (void)argc, (void)argv;

  res = mem_alloc(&arr, sizeof(*arr));

  if (res == MEM_ALLOC_FAILURE)
  {
    (void)printf("Could not allocate memory.\n");
    return 1;
  }

  *arr = 42;

  (void)printf("Location: %p, Value: %d\n", (void *)arr, *arr);
  (void)mem_free(&arr);
  (void)printf("Location: %p\n", (void *)arr);

  return 0;
}
