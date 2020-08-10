CFLAGS=-Wall -g

all:
	gcc -o output main.c matrix.c

clean:
	rm -f output
