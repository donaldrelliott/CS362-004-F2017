all: run

default: testme.o
	gcc testme.o -o testme

testme.o: testme.c
	gcc -c testme.c -o testme.o

run: testme
	./testme

.PHONY: all run
