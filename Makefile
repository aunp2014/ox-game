all: ox

ox: main.c
	gcc -Wall -ansi -pedantic -o ox main.c

clean:
	rm -f ox
