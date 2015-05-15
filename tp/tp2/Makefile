panzers: automaton.o coordinates.o sort.o main.o
	gcc -Wall automaton.o coordinates.o sort.o main.o -o panzers -lm
main.o: main.c automaton.h coordinates.h
	gcc -Wall -g3 -c main.c
automaton.o: automaton.h automaton.c coordinates.h
	gcc -Wall -g3 -c automaton.c
coordinates.o: coordinates.h coordinates.c sort.h
	gcc -Wall -g3 -c coordinates.c
sort.o: sort.h sort.c
	gcc -Wall -g3 -c sort.c