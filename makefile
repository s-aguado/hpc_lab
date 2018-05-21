CFLAGS = -Wall -Wextra
AVXFLAGS = -march=core-avx2

SRCS = matmul_kernels.c matmul_kernels_avx.c stuff.c matmul.c
OBJS = $(SRCS:.c=.o)

%_avx.o: %_avx.c
	$(CC) ${CFLAGS} ${AVXFLAGS} -c $<

matmul: ${OBJS}
