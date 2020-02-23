# I don't know what I'm doing...

LIBRARY_PATH = /lib
CC = gcc

get:
	${CC} -o get get.c -lncurses
get.o:
	${CC} -c get.c -lncurses
all:
	${CC} -o get get.c -lncurses
clean:
	rm -f get get.o
