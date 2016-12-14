VPATH = ../lib
PROGS = tcpcli01 tcpserv01
CFLAGS = -c -Wall -I../lib/
LDFLAGS = -L../lib
LIBS = -lmy
SRC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
all: ${PROGS}

tcpcli01: tcpcli01.o str_cli08.o
	${CC} ${LDFLAGS} -o $@ tcpcli01.o str_cli08.o $(LIBS)

tcpserv01: tcpserv01.o str_echo08.o
	${CC} ${LDFLAGS} -o $@ tcpserv01.o str_echo08.o $(LIBS)

OBJS: unp.h str_cli08.c str_echo08.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LIBS)
.PHONY:clean
clean:
	rm -f ${PROGS} ${CLEANFILES} ${OBJS}
