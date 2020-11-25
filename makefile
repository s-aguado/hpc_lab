all: release
release: matmul matmulO1 matmulO2 matmulO3 matmulOfast

CFLAGS = -Wall -Wextra -march=native -lm
PROFLAGS = -pg
DBGFLAGS = -O0 -g
O1FLAGS = -O1
O2FLAGS = -O2
O3FLAGS = -O3
OfastFLAGS = -Ofast

SRCS = matmul_kernels.c matmul_kernels_avx.c stuff.c matmul.c
OBJS = $(SRCS:.c=.o)
OBJS_DBG = $(SRCS:.c=_dbg.o)
OBJS_O1 = $(SRCS:.c=_O1.o)
OBJS_O2 = $(SRCS:.c=_O2.o)
OBJS_O3 = $(SRCS:.c=_O3.o)
OBJS_Ofast = $(SRCS:.c=_Ofast.o)
OBJS_DBG_prof = $(SRCS:.c=_dbg_prof.o)
OBJS_O1_prof = $(SRCS:.c=_O1_prof.o)
OBJS_O2_prof = $(SRCS:.c=_O2_prof.o)
OBJS_O3_prof = $(SRCS:.c=_O3_prof.o)
OBJS_Ofast_prof = $(SRCS:.c=_Ofast_prof.o)

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

%_dbg.o: %.c
	$(CC) ${CFLAGS} ${DBGFLAGS} -o $@ -c $<

%_O1.o: %.c
	$(CC) ${CFLAGS} ${O1FLAGS} -o $@ -c $<

%_O2.o: %.c
	$(CC) ${CFLAGS} ${O2FLAGS} -o $@ -c $<

%_O3.o: %.c
	$(CC) ${CFLAGS} ${O3FLAGS} -o $@ -c $<

%_Ofast.o: %.c
	$(CC) ${CFLAGS} ${OfastFLAGS} -o $@ -c $<

prof: dbg_prof O1_prof O2_prof O3_prof Ofast_prof

dbg_prof: ${OBJS_DBG_prof}
	${CC} -o $@ $^

O1_prof: ${OBJS_O1_prof}
	${CC} -o $@ $^

O2_prof: ${OBJS_O2_prof}
	${CC} -o $@ $^

O3_prof: ${OBJS_O3_prof}
	${CC} -o $@ $^

Ofast_prof: ${OBJS_Ofast_prof}
	${CC} -o $@ $^

%_dbg_prof.o: %.c
	$(CC) ${CFLAGS} ${DBGFLAGS} ${PROFLAGS} -o $@ -c $<

%_O1_prof.o: %.c
	$(CC) ${CFLAGS} ${O1FLAGS} ${PROFLAGS} -o $@ -c $<

%_O2_prof.o: %.c
	$(CC) ${CFLAGS} ${O2FLAGS} ${PROFLAGS} -o $@ -c $<

%_O3_prof.o: %.c
	$(CC) ${CFLAGS} ${O3FLAGS} ${PROFLAGS} -o $@ -c $<

%_Ofast_prof.o: %.c
	$(CC) ${CFLAGS} ${OfastFLAGS} ${PROFLAGS} -o $@ -c $<

tidyup:
	rm -f $(OBJS) ${OBJS_DBG} ${OBJS_O1} ${OBJS_O2} ${OBJS_O3} ${OBJS_Ofast} ${OBJS_DBG_prof} ${OBJS_O1_prof} ${OBJS_O2_prof} ${OBJS_O3_prof} ${OBJS_Ofast_prof}

clean: tidyup
	rm -f matmul matmulO1 matmulO2 matmulO3 matmulOfast dbg dbg_prof O1_prof O2_prof O3_prof Ofast_prof
