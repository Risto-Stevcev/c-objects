CC  = gcc

CFLAGS   = -g -Wall
LDFLAGS = -g 

.PHONY: default
default: main

main: main.o animal.o dog.o cat.o duck.o

animal.o: animal.h

dog.o: dog.c dog.h animal.h

cat.o: cat.c cat.h animal.h

duck.o: duck.c duck.h animal.h

.PHONY: clean
clean:
	rm -f *.o *~ *.swp *.swo a.out core main

.PHONY: all
all: clean main
