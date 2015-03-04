operations: operations.o main.o
	gcc operations.o main.o -o operations
main.o: main.c operations.h
	gcc -g -c main.c
operations.o: operations.h operations.c
	gcc -g -c operations.c