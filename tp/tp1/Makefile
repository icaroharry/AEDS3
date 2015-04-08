treap: treap.o main.o
	gcc -Wall treap.o main.o -o treap
main.o: main.c treap.h
	gcc -Wall -g3 -c main.c
treap.o: treap.h treap.c
	gcc -Wall -g3 -c treap.c

