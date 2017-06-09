CC = gcc
CFLAGS = -lbluetooth -lpthread
LIBS =

default: program

program.o: program.c
	$(CC) $(CFLAGS) -c program.c -o program.o

program: program.o
	$(CC) $(LIBS) program.o -o program

clean:
	-rm -f program.o
	-rm -f program
