panzers: automaton.o coordinates.o main.o
	gcc -Wall automaton.o coordinates.o main.o -o panzers -lm
main.o: main.c automaton.h coordinates.h
	gcc -Wall -g3 -c main.c
automaton.o: automaton.h automaton.c coordinates.h
	gcc -Wall -g3 -c automaton.c
coordinates.o: coordinates.h coordinates.c
	gcc -Wall -g3 -c coordinates.c