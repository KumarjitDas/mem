#ifndef MEM_H
#define MEM_H

#include <stdint.h>

#define MEM_API

#define MEM_SUCCESS (0)
#define MEM_FAILURE (1)
#define MEM_ALLOC_SUCCESS MEM_SUCCESS
#define MEM_ALLOC_FAILURE MEM_FAILURE
#define MEM_REALLOC_SUCCESS MEM_SUCCESS
#define MEM_REALLOC_FAILURE MEM_FAILURE
#define MEM_FREE_SUCCESS MEM_SUCCESS
#define MEM_FREE_FAILURE MEM_FAILURE

#ifdef MEM_INTERNAL_DEFS

#define MEM_SIZE_INFO_SIZE (sizeof(uint32_t))

#endif /* MEM_INTERNAL_DEFS */

/**
 * @brief Allocates memory of a specified size and updates the pointer.
 *
 * This function attempts to allocate a block of memory of the specified size.
 * If successful, it updates the pointer at the address provided by _Dst to
 * point to this new memory block. The intended use is to modify an existing
 * pointer variable to point to newly allocated memory.
 *
 * @param _Dst A pointer to the pointer variable that will point to the
 *             allocated memory. This double indirection allows the function
 *             to modify the caller's pointer variable to point to the allocated memory.
 * @param _Size The size of the memory block to allocate, in bytes.
 * @return An integer indicating the success or failure of the operation.
 *         Typically, returns 1 for success and 0 for failure. If memory allocation
 *         fails, the pointer pointed to by _Dst should not be used.
 */
int MEM_API mem_alloc(void *_Dst, uint32_t _Size);

/**
 * @brief Allocates memory of a specified size and stores the size information.
 *
 * This function attempts to allocate a block of memory of the specified size
 * and then stores the size of the allocated block at the beginning of the memory
 * itself. It updates the pointer at the address provided by _Dst to point to the
 * beginning of the usable memory area, just after the size information. This is useful
 * for keeping track of the memory block's size for future reference, such as for
 * deallocation or memory resizing operations.
 *
 * @param _Dst A pointer to the pointer variable that will point to the start of the
 *             usable allocated memory, not the actual start of the block where the
 *             size information is stored. This ensures the user of the function
 *             doesn't accidentally overwrite the size data.
 * @param _Size The size of the memory block to allocate, in bytes. The actual allocated
 *              size may be slightly larger to accommodate the size information.
 * @return An integer indicating the success or failure of the operation.
 *         Typically, returns 1 for success and 0 for failure. On success, _Dst is updated
 *         to point to the usable memory area. On failure, _Dst should not be used.
 */
int MEM_API mem_alloc_with_size_info(void *_Dst, uint32_t _Size);

/**
 * @brief Retrieves the size of an allocated memory block.
 *
 * This function accesses the size information stored in or associated with a memory block
 * allocated by functions like mem_alloc_with_size_info. It reads the size information
 * and stores it in the variable pointed to by _Size. This is typically used to retrieve
 * the size of a memory block when only a pointer to the block is available, for purposes
 * such as validation, deallocation, or memory resizing operations.
 *
 * @param _Size A pointer to the variable where the size information of the memory block will be stored.
 *              After the function call, this will contain the size of the allocated block, in bytes.
 * @param _Ptr A pointer to the allocated memory block whose size information is to be retrieved.
 *             This should be the pointer to the usable memory area, just like the one
 *             provided by mem_alloc_with_size_info or similar functions.
 * @return An integer indicating the success or failure of the operation.
 *         Typically, returns 1 for success and 0 for failure. If the retrieval is successful,
 *         _Size will be updated with the size of the memory block. If it fails, the value
 *         pointed to by _Size should not be considered valid.
 */
int MEM_API mem_get_size(uint32_t *_Size, void *_Ptr);

/**
 * @brief Retrieves the total allocated size of a memory block, including the space for size information.
 *
 * This function is used to determine the total size of a memory block that was allocated
 * with functions like mem_alloc_with_size_info, which store additional size information
 * with the allocated memory. It accesses this size information and returns the total
 * allocated size, which includes both the usable memory size and the additional space
 * used to store the size. This size is also stored in the variable pointed to by _Size,
 * providing two ways to retrieve the information.
 *
 * @param _Size A pointer to the variable where the total allocated size of the memory block
 *              will be stored. After the function call, this will contain the total size
 *              of the allocated block, in bytes, including the space used to store the size.
 * @param _Ptr A pointer to the allocated memory block whose total size information is to be retrieved.
 *             This should be the same pointer provided by memory allocation functions that store
 *             size information.
 * @return The total allocated size of the memory block, in bytes, including the space used
 *         to store the size information. This return value provides an immediate way to use
 *         the size information, while the _Size parameter offers a way to keep the information
 *         for later use.
 */
int MEM_API mem_get_alloc_size(uint32_t *_Size, void *_Ptr);

/**
 * @brief Reallocates memory to a new size and updates pointers.
 *
 * This function changes the size of the memory block pointed to by the pointer at _Old
 * to the new size specified by _Size. It allocates a new memory block of the specified
 * size, copies the contents of the old block to the new block, frees the old block,
 * and then updates the pointer at _New to point to the new memory block. The pointer
 * at _Old is updated to NULL after the old memory block is freed, preventing dangling
 * pointer issues. This function is useful for dynamically adjusting the size of memory
 * blocks during runtime.
 *
 * @param _New A pointer to the pointer variable that will be updated to point to the
 *             newly allocated memory block. This reflects the double indirection used
 *             to update the caller's pointer.
 * @param _Size The new size of the memory block, in bytes.
 * @param _Old A pointer to the pointer variable that currently points to the memory block
 *             to be reallocated. After reallocating, the pointer pointed to by _Old
 *             will be set to NULL.
 * @return An integer indicating the success or failure of the operation.
 *         Typically, returns 1 for success and 0 for failure. On success, _New is updated
 *         to point to the newly allocated memory, and _Old is set to NULL. On failure,
 *         the state of both pointers (_New and _Old) should not be considered reliable.
 */
int MEM_API mem_realloc(void *_New, uint32_t _Size, void *_Old);

/**
 * @brief Reallocates memory with size information to a new size and updates pointers.
 *
 * This function changes the size of the memory block pointed to by the pointer at _Old
 * to the new size specified by _Size. It allocates a new memory block of the specified
 * size, stores the size information at the beginning of this block, copies the contents
 * of the old block to the new block (up to the minimum of the old and new sizes), frees
 * the old block, and updates the pointer at _New to point to the start of the usable area
 * of the new memory block. The pointer at _Old is updated to NULL after the old memory block
 * is freed, preventing dangling pointer issues. This function is useful for dynamically adjusting
 * the size of memory blocks during runtime, especially when maintaining size information is critical.
 *
 * @param _New A pointer to the pointer variable that will be updated to point to the
 *             start of the usable area of the newly allocated memory block, just after
 *             the size information. This reflects the double indirection used to update
 *             the caller's pointer.
 * @param _Size The new size of the memory block, in bytes. The actual allocated size
 *              may be slightly larger to accommodate the size information.
 * @param _Old A pointer to the pointer variable that currently points to the memory block
 *             to be reallocated. After reallocating, the pointer pointed to by _Old
 *             will be set to NULL.
 * @return An integer indicating the success or failure of the operation.
 *         Typically, returns 1 for success and 0 for failure. On success, _New is updated
 *         to point to the usable area of the newly allocated memory, and _Old is set to NULL.
 *         On failure, the state of both pointers (_New and _Old) should not be considered reliable.
 */
int MEM_API mem_realloc_with_size_info(void *_New, uint32_t _Size, void *_Old);

/**
 * @brief Frees previously allocated memory and nullifies the pointer.
 *
 * This function releases a block of memory pointed to by the pointer at the address
 * provided by _Ptr. It is intended to not only free the allocated memory but also
 * to prevent dangling pointers by setting the original pointer to NULL after
 * freeing the memory. This helps ensure that the pointer cannot be accidentally
 * dereferenced after the memory has been deallocated.
 *
 * @param _Ptr A pointer to the pointer variable that points to the memory block
 *             to be freed. This double indirection allows the function to not only
 *             free the memory but also to update the original pointer to NULL.
 *             If the pointer pointed to by _Ptr is NULL, no action occurs.
 * @return An integer indicating the success or failure of the operation.
 *         Typically, returns 1 for success and 0 for failure.
 */
int MEM_API mem_free(void *_Ptr);

/**
 * @brief Frees previously allocated memory with size information and nullifies the pointer.
 *
 * This function is designed to free memory blocks that were allocated with associated
 * size information, such as those allocated by mem_alloc_with_size_info. It first
 * retrieves the size information from the memory block, then frees the entire block,
 * including the size information. Finally, it sets the pointer at the address provided
 * by _Ptr to NULL, preventing any dangling pointer issues. This ensures that the pointer
 * cannot be accidentally dereferenced after the memory has been deallocated.
 *
 * @param _Ptr A pointer to the pointer variable that points to the memory block
 *             to be freed, including its size information. The double indirection allows
 *             the function to not only free the memory but also to update the original
 *             pointer to NULL, enhancing safety and preventing misuse.
 * @return An integer indicating the success or failure of the operation.
 *         Typically, returns 1 for success and 0 for failure. If the operation is successful,
 *         the pointer pointed to by _Ptr is set to NULL. If the operation fails, the state
 *         of the pointer should not be considered reliable and may require further handling.
 */
int MEM_API mem_free_with_size_info(void *_Ptr);

#endif /* MEM_H */
