SHELL=/bin/sh

CC = clang
CFLAGS = -Wall -Wextra -std=c89 -D_GNU_SOURCE -O2

SRC = main.c run.c interpret.c console.c check.c
OBJS = $(SRC:%.c=%.o)

.PHONY: all clean

all: bf

bf: $(OBJS)
	$(CC) $^ -o $@

check.o: check.c main.h
console.o: console.c main.h
interpret.o: interpret.c main.h
main.o: main.c main.h
run.o: run.c main.h

clean:
	-rm $(OBJS)
	-rm bf
