project(hpc_lab_lib)
add_library(library stuff.c matmul_kernels_avx.c matmul_kernels.c)

include_directories(inc)
set(CMAKE_C_FLAGS "-Wall -Wextra -march=native -Ofast")
