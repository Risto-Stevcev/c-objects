CC  = gcc

CFLAGS   = -g -Wall
LDFLAGS = -g 

.PHONY: default
default: main

main: main.o mystring.o

mystring.o: mystring.c mystring.h

.PHONY: clean
clean:
	rm -f *.o *~ *.swp *.swo a.out core main

.PHONY: all
all: clean main
