CFLAGS=-Wall -g

all:
	gcc -o output -O2 main.c matrix.c expectimax.c

clean:
	rm -f output
