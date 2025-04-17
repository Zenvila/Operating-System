# Makefile

CC=gcc
CFLAGS=-Wall -g
TARGET=my_strace

all: $(TARGET)

$(TARGET): my_strace.c
	$(CC) $(CFLAGS) -o $(TARGET) my_strace.c

clean:
	rm -f $(TARGET)