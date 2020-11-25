add_executable(executable matmul.c stuff.c)
target_link_libraries(executable m library)

include_directories(inc)
include_directories(../library/inc)
set(CMAKE_C_FLAGS "-march=native -O2")
