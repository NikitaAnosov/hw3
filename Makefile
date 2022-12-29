CC = gcc
CFLAGS = -Wall -g

all: isort txtfind

isort: isort.o
	$(CC) $(CFLAGS) -o isort isort.o
isort.o: isort.c
	$(CC) $(CFLAGS) -c isort.c

txtfind: txtfind.o
	$(CC) $(CFLAGS) -o txtfind txtfind.o
txtfind.o: txtfind.c
	$(CC) $(CFLAGS) -c txtfind.c

.PHONY: clean all
clean:
	rm -f *.o isort txtfind