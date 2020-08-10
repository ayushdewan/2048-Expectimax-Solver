CFLAGS=-Wall -g

all:
	gcc -o output main.c matrix.c expectimax.c

clean:
	rm -f output
