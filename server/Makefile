CC = gcc
CFLAGS =
LIBS = -lbluetooth -lpthread

default: program
.PHONY: program

bimbambom.o: bimbambom.c
	$(CC) $(CFLAGS) -c bimbambom.c -o bimbambom.o

program.o: program.c bimbambom.h
	$(CC) $(CFLAGS) -c program.c -o program.o

program: program.o bimbambom.o
	$(CC) $(LIBS) program.o bimbambom.o -o program

clean:
	-rm -f *.o
	-rm -f program
