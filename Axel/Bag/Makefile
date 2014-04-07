CC  = gcc

CFLAGS   = -g -Wall
LDFLAGS = -g 

.PHONY: default
default: main

main: main.o Set.o

main.o: main.c Set.h Object.h new.h

Set.o: Set.h Object.h new.h

.PHONY: clean
clean:
	rm -f *.o *~ *.swp *.swo a.out core main

.PHONY: all
all: clean main
