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


TEST(MemoryAllocationTest, BasicArguments)
{
  u8* ptr;

  EXPECT_EQ(memAlloc(null, 0), MEM_FAILURE);
  EXPECT_EQ(memAlloc(null, -420), MEM_FAILURE);
  EXPECT_EQ(memAlloc(null, 69), MEM_FAILURE);

  EXPECT_EQ(memAlloc(&ptr, 0), MEM_FAILURE);
  EXPECT_EQ(ptr, null);

  EXPECT_EQ(memAlloc(&ptr, -69), MEM_FAILURE);
  EXPECT_EQ(ptr, null);
}

TEST(MemoryAllocationTest, BasicAllocationBytes)
{
  u8* ptr;

  EXPECT_EQ(memAlloc(&ptr, 1), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 64), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 128), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 256), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 512), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);
}

TEST(MemoryAllocationTest, BasicAllocationKiloBytes)
{
  u8* ptr;

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 64), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 128), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 256), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 512), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);
}

TEST(MemoryAllocationTest, BasicAllocationMegaBytes)
{
  u8* ptr;

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 1), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 64), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 128), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 256), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 512), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);

  EXPECT_EQ(memAlloc(&ptr, 1024 * 1024 * 1024), MEM_SUCCESS);
  ASSERT_NE(ptr, null);
  if (ptr != null) free(ptr);
}

TEST(MemoryAllocationTest, BasicMultipleSequentialAllocationsBytes)
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
  if (ptr1 != null) free(ptr1);
  ASSERT_NE(ptr2, null);
  if (ptr2 != null) free(ptr2);
  ASSERT_NE(ptr3, null);
  if (ptr3 != null) free(ptr3);
  ASSERT_NE(ptr4, null);
  if (ptr4 != null) free(ptr4);
  ASSERT_NE(ptr5, null);
  if (ptr5 != null) free(ptr5);
  ASSERT_NE(ptr6, null);
  if (ptr6 != null) free(ptr6);
  ASSERT_NE(ptr7, null);
  if (ptr7 != null) free(ptr7);
  ASSERT_NE(ptr8, null);
  if (ptr8 != null) free(ptr8);
  ASSERT_NE(ptr9, null);
  if (ptr9 != null) free(ptr9);
  ASSERT_NE(ptr10, null);
  if (ptr10 != null) free(ptr10);
  ASSERT_NE(ptr11, null);
  if (ptr11 != null) free(ptr11);
}

TEST(MemoryAllocationTest, BasicMultipleSequentialAllocationsKiloBytes)
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
  if (ptr1 != null) free(ptr1);
  ASSERT_NE(ptr2, null);
  if (ptr2 != null) free(ptr2);
  ASSERT_NE(ptr3, null);
  if (ptr3 != null) free(ptr3);
  ASSERT_NE(ptr4, null);
  if (ptr4 != null) free(ptr4);
  ASSERT_NE(ptr5, null);
  if (ptr5 != null) free(ptr5);
  ASSERT_NE(ptr6, null);
  if (ptr6 != null) free(ptr6);
  ASSERT_NE(ptr7, null);
  if (ptr7 != null) free(ptr7);
  ASSERT_NE(ptr8, null);
  if (ptr8 != null) free(ptr8);
  ASSERT_NE(ptr9, null);
  if (ptr9 != null) free(ptr9);
  ASSERT_NE(ptr10, null);
  if (ptr10 != null) free(ptr10);
  ASSERT_NE(ptr11, null);
  if (ptr11 != null) free(ptr11);
}

TEST(MemoryAllocationTest, BasicMultipleSequentialAllocationsMegaBytes)
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
  if (ptr1 != null) free(ptr1);
  ASSERT_NE(ptr2, null);
  if (ptr2 != null) free(ptr2);
  ASSERT_NE(ptr3, null);
  if (ptr3 != null) free(ptr3);
  ASSERT_NE(ptr4, null);
  if (ptr4 != null) free(ptr4);
  ASSERT_NE(ptr5, null);
  if (ptr5 != null) free(ptr5);
  ASSERT_NE(ptr6, null);
  if (ptr6 != null) free(ptr6);
  ASSERT_NE(ptr7, null);
  if (ptr7 != null) free(ptr7);
  ASSERT_NE(ptr8, null);
  if (ptr8 != null) free(ptr8);
  ASSERT_NE(ptr9, null);
  if (ptr9 != null) free(ptr9);
  ASSERT_NE(ptr10, null);
  if (ptr10 != null) free(ptr10);
  ASSERT_NE(ptr11, null);
  if (ptr11 != null) free(ptr11);
}
