treap: treap.o main.o
	gcc treap.o main.o -o treap
main.o: main.c treap.h
	gcc -g -c main.c
treap.o: treap.h treap.c
	gcc -g -c treap.c

