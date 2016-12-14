SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
TARGET = libmy.a

$(TARGET)(*.o) : $(OBJS)
	ar cr $(TARGET) $(OBJS)
.PHONY:clean
clean:
	rm *.o *.a
