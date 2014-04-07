CC  = gcc

CFLAGS   = -g -Wall
LDFLAGS = -g 

.PHONY: default
default: blah

blah: blah.o FooOBJ.o

FooOBJ.o: FooOBJ.c FooOBJ.h

.PHONY: clean
clean:
	rm -f *.o *~ *.swp *.swo a.out core blah

.PHONY: all
all: clean blah
