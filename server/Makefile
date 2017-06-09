HEADERS =
OBJECTS = program.o
CC = gcc
CFLAGS = -lbluetooth -lpthread

default: program

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f program
