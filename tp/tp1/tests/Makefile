# Making test files #
test: ../treap.o treap.test.o
	gcc ../treap.o treap.test.o -o test
treap.test.o: treap.test.c ../treap.h
	gcc -g -c treap.test.c
../treap.o: ../treap.h ../treap.c
	gcc -g -c ../treap.c