CFLAGS=-Wall -g

all:
	gcc -o output -O2 main.c matrix.c expectimax.c -lpthread

clean:
	rm -f output
