graph: graph.o main.o
	gcc -Wall graph.o main.o -o main
main.o: main.c graph.h
	gcc -Wall -g3 -c main.c
graph.o: graph.h graph.c
	gcc -Wall -g3 -c graph.c

