/**
 * @file memAlloc.cpp
 * @author Kumarjit Das
 * @date 2024-07-07
 * @version @KDAPI_VERSION_MAJOR@.@KDAPI_VERSION_MINOR@.@KDAPI_VERSION_PATCH@
 * @brief A test source file of the MEM library.
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


#include "mem.h"
#include "gtest/gtest.h"


TEST(MemoryDeallocationTest, BasicArguments)
{
  EXPECT_EQ(memFree(null), MEM_FAILURE);
}

TEST(MemoryDeallocationTest, BasicDeallocationBytes)
{
  u8* ptr;

  EXPECT_EQ(memAlloc(&ptr, 1), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 64), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 128), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 256), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 512), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  
}

TEST(MemoryDeallocationTest, BasicDeallocationKiloBytes)
{
  u8* ptr;

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 64), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 128), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 256), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 512), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  
}

TEST(MemoryDeallocationTest, BasicDeallocationMegaBytes)
{
  u8* ptr;

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 1), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 64), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 128), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 256), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 512), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 1024), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  EXPECT_EQ(memFree(&ptr), MEM_SUCCESS);
  EXPECT_EQ(ptr, null);
  
}

TEST(MemoryDeallocationTest, BasicMultipleSequentialDeallocationsBytes)
{
  u8 *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6, *ptr7, *ptr8, *ptr9, *ptr10, *ptr11;

  EXPECT_EQ(memAlloc(&ptr1, 1), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr2, 64), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr3, 128), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr4, 256), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr5, 512), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr6, 1024), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr7, 512), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr8, 256), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr9, 128), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr10, 64), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr11, 1), MEM_SUCCESS);

  ASSERT_NE(ptr1, null);
  EXPECT_EQ(memFree(&ptr1), MEM_SUCCESS);
  EXPECT_EQ(ptr1, null);
  
  ASSERT_NE(ptr2, null);
  EXPECT_EQ(memFree(&ptr2), MEM_SUCCESS);
  EXPECT_EQ(ptr2, null);
  
  ASSERT_NE(ptr3, null);
  EXPECT_EQ(memFree(&ptr3), MEM_SUCCESS);
  EXPECT_EQ(ptr3, null);
  
  ASSERT_NE(ptr4, null);
  EXPECT_EQ(memFree(&ptr4), MEM_SUCCESS);
  EXPECT_EQ(ptr4, null);
  
  ASSERT_NE(ptr5, null);
  EXPECT_EQ(memFree(&ptr5), MEM_SUCCESS);
  EXPECT_EQ(ptr5, null);
  
  ASSERT_NE(ptr6, null);
  EXPECT_EQ(memFree(&ptr6), MEM_SUCCESS);
  EXPECT_EQ(ptr6, null);
  
  ASSERT_NE(ptr7, null);
  EXPECT_EQ(memFree(&ptr7), MEM_SUCCESS);
  EXPECT_EQ(ptr7, null);
  
  ASSERT_NE(ptr8, null);
  EXPECT_EQ(memFree(&ptr8), MEM_SUCCESS);
  EXPECT_EQ(ptr8, null);
  
  ASSERT_NE(ptr9, null);
  EXPECT_EQ(memFree(&ptr9), MEM_SUCCESS);
  EXPECT_EQ(ptr9, null);
  
  ASSERT_NE(ptr10, null);
  EXPECT_EQ(memFree(&ptr10), MEM_SUCCESS);
  EXPECT_EQ(ptr10, null);
  
  ASSERT_NE(ptr11, null);
  EXPECT_EQ(memFree(&ptr11), MEM_SUCCESS);
  EXPECT_EQ(ptr11, null);
  
}

TEST(MemoryDeallocationTest, BasicMultipleSequentialDeallocationsKiloBytes)
{
  u8 *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6, *ptr7, *ptr8, *ptr9, *ptr10, *ptr11;

  EXPECT_EQ(memAlloc(&ptr1, 1024 * 1), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr2, 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr3, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr4, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr5, 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr6, 1024 * 1024), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr7, 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr8, 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr9, 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr10, 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr11, 1024 * 1), MEM_SUCCESS);

  ASSERT_NE(ptr1, null);
  EXPECT_EQ(memFree(&ptr1), MEM_SUCCESS);
  EXPECT_EQ(ptr1, null);
  
  ASSERT_NE(ptr2, null);
  EXPECT_EQ(memFree(&ptr2), MEM_SUCCESS);
  EXPECT_EQ(ptr2, null);
  
  ASSERT_NE(ptr3, null);
  EXPECT_EQ(memFree(&ptr3), MEM_SUCCESS);
  EXPECT_EQ(ptr3, null);
  
  ASSERT_NE(ptr4, null);
  EXPECT_EQ(memFree(&ptr4), MEM_SUCCESS);
  EXPECT_EQ(ptr4, null);
  
  ASSERT_NE(ptr5, null);
  EXPECT_EQ(memFree(&ptr5), MEM_SUCCESS);
  EXPECT_EQ(ptr5, null);
  
  ASSERT_NE(ptr6, null);
  EXPECT_EQ(memFree(&ptr6), MEM_SUCCESS);
  EXPECT_EQ(ptr6, null);
  
  ASSERT_NE(ptr7, null);
  EXPECT_EQ(memFree(&ptr7), MEM_SUCCESS);
  EXPECT_EQ(ptr7, null);
  
  ASSERT_NE(ptr8, null);
  EXPECT_EQ(memFree(&ptr8), MEM_SUCCESS);
  EXPECT_EQ(ptr8, null);
  
  ASSERT_NE(ptr9, null);
  EXPECT_EQ(memFree(&ptr9), MEM_SUCCESS);
  EXPECT_EQ(ptr9, null);
  
  ASSERT_NE(ptr10, null);
  EXPECT_EQ(memFree(&ptr10), MEM_SUCCESS);
  EXPECT_EQ(ptr10, null);
  
  ASSERT_NE(ptr11, null);
  EXPECT_EQ(memFree(&ptr11), MEM_SUCCESS);
  EXPECT_EQ(ptr11, null);
  
}

TEST(MemoryDeallocationTest, BasicMultipleSequentialDeallocationsMegaBytes)
{
  u8 *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6, *ptr7, *ptr8, *ptr9, *ptr10, *ptr11;

  EXPECT_EQ(memAlloc(&ptr1, 1024 * 1024 * 1), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr2, 1024 * 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr3, 1024 * 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr4, 1024 * 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr5, 1024 * 1024 * 32), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr6, 1024 * 1024 * 512), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr7, 1024 * 1024 * 32), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr8, 1024 * 1024 * 256), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr9, 1024 * 1024 * 128), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr10, 1024 * 1024 * 64), MEM_SUCCESS);
  EXPECT_EQ(memAlloc(&ptr11, 1024 * 1024 * 1), MEM_SUCCESS);

  ASSERT_NE(ptr1, null);
  EXPECT_EQ(memFree(&ptr1), MEM_SUCCESS);
  EXPECT_EQ(ptr1, null);
  
  ASSERT_NE(ptr2, null);
  EXPECT_EQ(memFree(&ptr2), MEM_SUCCESS);
  EXPECT_EQ(ptr2, null);
  
  ASSERT_NE(ptr3, null);
  EXPECT_EQ(memFree(&ptr3), MEM_SUCCESS);
  EXPECT_EQ(ptr3, null);
  
  ASSERT_NE(ptr4, null);
  EXPECT_EQ(memFree(&ptr4), MEM_SUCCESS);
  EXPECT_EQ(ptr4, null);
  
  ASSERT_NE(ptr5, null);
  EXPECT_EQ(memFree(&ptr5), MEM_SUCCESS);
  EXPECT_EQ(ptr5, null);
  
  ASSERT_NE(ptr6, null);
  EXPECT_EQ(memFree(&ptr6), MEM_SUCCESS);
  EXPECT_EQ(ptr6, null);
  
  ASSERT_NE(ptr7, null);
  EXPECT_EQ(memFree(&ptr7), MEM_SUCCESS);
  EXPECT_EQ(ptr7, null);
  
  ASSERT_NE(ptr8, null);
  EXPECT_EQ(memFree(&ptr8), MEM_SUCCESS);
  EXPECT_EQ(ptr8, null);
  
  ASSERT_NE(ptr9, null);
  EXPECT_EQ(memFree(&ptr9), MEM_SUCCESS);
  EXPECT_EQ(ptr9, null);
  
  ASSERT_NE(ptr10, null);
  EXPECT_EQ(memFree(&ptr10), MEM_SUCCESS);
  EXPECT_EQ(ptr10, null);
  
  ASSERT_NE(ptr11, null);
  EXPECT_EQ(memFree(&ptr11), MEM_SUCCESS);
  EXPECT_EQ(ptr11, null);
  
}
