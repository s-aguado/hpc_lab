all: release dbg
release: matmul matmulO1 matmulO2 matmulO3 matmulOfast

CFLAGS = -Wall -Wextra
AVXFLAGS = -march=core-avx2
DBGFLAGS = -Og -g
O1FLAGS = -O1
O2FLAGS = -O2
O3FLAGS = -O3
OfastFLAGS = -Ofast -ffast-math

SRCS = matmul_kernels.c matmul_kernels_avx.c stuff.c matmul.c
OBJS = $(SRCS:.c=.o)
OBJS_DBG = $(SRCS:.c=_dbg.o)
OBJS_O1 = $(SRCS:.c=_O1.o)
OBJS_O2 = $(SRCS:.c=_O2.o)
OBJS_O3 = $(SRCS:.c=_O3.o)
OBJS_Ofast = $(SRCS:.c=_Ofast.o)

matmul: ${OBJS}
	${CC} -o $@ $^

matmulO1: ${OBJS_O1}
	${CC} -o $@ $^

matmulO2: ${OBJS_O2}
	${CC} -o $@ $^

matmulO3: ${OBJS_O3}
	${CC} -o $@ $^

matmulOfast: ${OBJS_Ofast}
	${CC} -o $@ $^

dbg: ${OBJS_DBG}
	${CC} -o $@ $^

%_avx.o: CFLAGS += ${AVXFLAGS}
%_avx.o: %_avx.c

%_dbg.o: %.c
	$(CC) ${CFLAGS} ${DBGFLAGS} -o $@ -c $<

%_avx_dbg.o: CFLAGS += ${AVXFLAGS} ${DBGFLAGS}
%_avx_dbg.o: %.c

%_O1.o: %.c
	$(CC) ${CFLAGS} ${O1FLAGS} -o $@ -c $<

%_avx_O1.o: CFLAGS += ${AVXFLAGS}
%_avx_O1.o: %.c

%_O2.o: %.c
	$(CC) ${CFLAGS} ${O2FLAGS} -o $@ -c $<

%_avx_O2.o: CFLAGS += ${AVXFLAGS}
%_avx_O2.o: %.c

%_O3.o: %.c
	$(CC) ${CFLAGS} ${O3FLAGS} -o $@ -c $<

%_avx_O3.o: CFLAGS += ${AVXFLAGS}
%_avx_O3.o: %.c

%_Ofast.o: %.c
	$(CC) ${CFLAGS} ${OfastFLAGS} -o $@ -c $<

%_avx_Ofast.o: CFLAGS += ${AVXFLAGS}
%_avx_Ofast.o: %.c

tidyup:
	rm -f $(OBJS) ${OBJS_DBG} ${OBJS_O1} ${OBJS_O2} ${OBJS_O3} ${OBJS_Ofast}

clean: tidyup
	rm -f matmul matmulO1 matmulO2 matmulO3 matmulOfast dbg
