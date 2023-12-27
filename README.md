# MEM (Memory Management Library)

A lightweight, portable C library for dynamic memory allocation, reallocation, and deallocation with additional utilities for managing memory sizes. Designed with compatibility for C89/90 standards and integrating seamlessly with systems requiring precise memory control.

## Features

- Simple and straightforward API for memory operations.
- Functions for memory allocation, reallocation, and deallocation.
- Additional functions to handle memory with size information for better management.
- Error handling through return codes.

## Installation

Include the `mem.h` header file in your project directory and ensure your compiler settings are compatible with C89/90 standards.

## API Reference

### `int mem_alloc(void *_Dst, uint32_t _Size)`

Allocates memory of a specified size and updates the pointer.

- **_Dst**: A pointer to the pointer variable that will point to the allocated memory.
- **_Size**: The size of the memory block to allocate, in bytes.
- **Returns**: `MEM_SUCCESS` or `MEM_FAILURE`.

### `int mem_alloc_with_size_info(void *_Dst, uint32_t _Size)`

Allocates memory of a specified size and stores the size information.

- **_Dst**: A pointer to the pointer variable that will point to the start of the usable allocated memory.
- **_Size**: The size of the memory block to allocate, in bytes.
- **Returns**: `MEM_SUCCESS` or `MEM_FAILURE`.

### `int mem_get_size(uint32_t *_Size, void *_Ptr)`

Retrieves the size of an allocated memory block.

- **_Size**: A pointer to the variable where the size information will be stored.
- **_Ptr**: A pointer to the allocated memory block.
- **Returns**: `MEM_SUCCESS` or `MEM_FAILURE`.

### `int mem_get_alloc_size(uint32_t *_Size, void *_Ptr)`

Retrieves the total allocated size of a memory block, including space for size information.

- **_Size**: A pointer to the variable where the total allocated size will be stored.
- **_Ptr**: A pointer to the allocated memory block.
- **Returns**: The total allocated size in bytes.

### `int mem_realloc(void *_New, uint32_t _Size, void *_Old)`

Reallocates memory to a new size and updates pointers.

- **_New**: A pointer to the pointer variable that will point to the newly allocated memory block.
- **_Size**: The new size of the memory block, in bytes.
- **_Old**: A pointer to the pointer variable that currently points to the memory block to be reallocated.
- **Returns**: `MEM_SUCCESS` or `MEM_FAILURE`.

### `int mem_realloc_with_size_info(void *_New, uint32_t _Size, void *_Old)`

Reallocates memory with size information to a new size and updates pointers.

- **_New**: A pointer to the pointer variable that will point to the start of the usable area of the newly allocated memory block.
- **_Size**: The new size of the memory block, in bytes.
- **_Old**: A pointer to the pointer variable that currently points to the memory block to be reallocated.
- **Returns**: `MEM_SUCCESS` or `MEM_FAILURE`.

### `int mem_free(void *_Ptr)`

Frees previously allocated memory and nullifies the pointer.

- **_Ptr**: A pointer to the pointer variable that points to the memory block to be freed.
- **Returns**: `MEM_SUCCESS` or `MEM_FAILURE`.

### `int mem_free_with_size_info(void *_Ptr)`

Frees previously allocated memory with size information and nullifies the pointer.

- **_Ptr**: A pointer to the pointer variable that points to the memory block to be freed.
- **Returns**: `MEM_SUCCESS` or `MEM_FAILURE`.

## Usage Example

```c
#include "mem.h"

int main() {
    char *buffer = NULL;
    if (mem_alloc(&buffer, 128) == MEM_SUCCESS) {
        // Use the buffer
    }

    // Free the buffer
    mem_free(&buffer);

    return 0;
}
