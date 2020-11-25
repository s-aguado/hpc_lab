# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.6)

# Project's name
project(hpc_lab)

# Executable and list of sources
add_executable(myexe matmul_kernels_avx.c matmul_kernels.c matmul.c stuff.c)

# Compiler flags
set(CMAKE_C_FLAGS "-Wall -Wextra -march=native -Ofast")
