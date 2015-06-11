graph: graph.o main.o util.o
	gcc -Wall graph.o main.o util.o -o tsp -lm
main.o: main.c graph.h
	gcc -Wall -g3 -c main.c -lm
graph.o: graph.h util.h graph.c
	gcc -Wall -g3 -c graph.c util.h -lm
util.o: util.h util.c
	gcc -Wall -g3 -c util.c -lm

