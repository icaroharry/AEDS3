# Making test files #
test: ../treap.o test.o
	gcc ../treap.o test.o -o test -lm
test.o: test.c ../treap.h
	gcc -g3 -c test.c -lm
../treap.o: ../treap.h ../treap.c
	gcc -g3 -c ../treap.c -lm