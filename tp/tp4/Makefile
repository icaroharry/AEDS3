tp: casinoPD.o mainPD.o
	gcc -Wall casinoPD.o mainPD.o -o tp
mainPD.o: mainPD.c casinoPD.h
	gcc -Wall -g3 -c mainPD.c
casinoPD.o: casinoPD.h casinoPD.c
	gcc -Wall -g3 -c casinoPD.c
