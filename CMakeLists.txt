cmake_minimum_required(VERSION 3.10)

# Set the project name
project(mem)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(include)

# Add library
add_library(mem STATIC src/mem.c)

# Add tests
add_executable(alloc tests/alloc.c)
target_link_libraries(alloc mem)

add_executable(alloc_with_size_info tests/alloc_with_size_info.c)
target_link_libraries(alloc_with_size_info mem)

add_executable(realloc tests/realloc.c)
target_link_libraries(realloc mem)

add_executable(realloc_with_size_info tests/realloc_with_size_info.c)
target_link_libraries(realloc_with_size_info mem)

# Enable testing and add tests
enable_testing()
add_test(NAME Test_alloc                    COMMAND alloc)
add_test(NAME Test_alloc_with_size_info     COMMAND alloc_with_size_info)
add_test(NAME Test_realloc                  COMMAND realloc)
add_test(NAME Test_realloc_with_size_info   COMMAND realloc_with_size_info)
