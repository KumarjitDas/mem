/**
 * @file mem.h
 * @author Kumarjit Das
 * @date 2024-07-07
 * @version @KDAPI_VERSION_MAJOR@.@KDAPI_VERSION_MINOR@.@KDAPI_VERSION_PATCH@
 * @brief Main header file of the MEM library.
 */
/**
 * LICENSE:
 *
 * Copyright (c) 2024, Kumarjit Das
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef MEM_H_
#define MEM_H_


#include "kdapi.h"

KD_EXTERN_BEGIN


#include "types.h"
#include "mem_version.h"


#define MEMAPI(T) KDAPI(T)

#if defined TYPES_64BIT_INTEGER && defined TYPES_PRETEND_64BIT_INTEGER
#define USE_64BIT 1
#endif  /* TYPES_64BIT_INTEGER */

#define MEM_SUCCESS true
#define MEM_FAILURE false


#if defined MEM_DEBUG_MODE

#if !defined MEM_DEBUG_OUTFILE
#include <stdio.h>
#define MEM_DEBUG_OUTFILE stdout
#endif  /* MEM_DEBUG_OUTFILE */

#define memAlloc(dst, sz) kd_mem__func_memAlloc_(dst, sz, __FILE__, __LINE__, MEM_DEBUG_OUTFILE)

#define memRealloc(dst, src, sz) kd_mem__func_memRealloc_(dst, src, sz, __FILE__, __LINE__, MEM_DEBUG_OUTFILE)

#define memFree(dst) kd_mem__func_memFree_(dst, __FILE__, __LINE__, MEM_DEBUG_OUTFILE)

#define memAllocWithSizeInfo(dst, sz) kd_mem__func_memAllocWithSizeInfo_(dst, sz, __FILE__, __LINE__, MEM_DEBUG_OUTFILE)

#define memReallocWithSizeInfo(dst, src, sz) \
 kd_mem__func_memReallocWithSizeInfo_(dst, src, sz, __FILE__, __LINE__, MEM_DEBUG_OUTFILE)

#define memFreeWithSizeInfo(dst) kd_mem__func_memFreeWithSizeInfo_(dst, __FILE__, __LINE__, MEM_DEBUG_OUTFILE)

#undef MEM_DEBUG_MODE

#else

MEMAPI(bool) memAlloc(void* dst, i32 sz);

MEMAPI(bool) memRealloc(void* dst, void* src, i32 sz);

MEMAPI(bool) memFree(void* dst);

MEMAPI(bool) memAllocWithSizeInfo(void* dst, i32 sz);

MEMAPI(bool) memReallocWithSizeInfo(void* dst, void* src, i32 sz);

MEMAPI(bool) memFreeWithSizeInfo(void* dst);

#endif  /* MEM_DEBUG_MODE */


KD_EXTERN_END

#endif  /* MEM_H_ */
