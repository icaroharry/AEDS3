tp: casino.o main.o
	gcc -Wall casino.o main.o -o tp
main.o: main.c casino.h
	gcc -Wall -g3 -c main.c
casino.o: casino.h casino.c
	gcc -Wall -g3 -c casino.c
