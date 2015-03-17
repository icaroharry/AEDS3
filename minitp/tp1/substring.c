#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 52
#define END_OF_INPUT '\n'

int find_substring(char* a, char* b) {
    int size_of_a = strlen(a) - 1;
    int size_of_b = strlen(b) - 1;
    int bigger_size;
    if(size_of_a < size_of_b) {
        bigger_size = brute_force(b, a, size_of_b, size_of_a);
    } else {
        bigger_size = brute_force(a, b, size_of_a, size_of_b);        
    }
    printf("%d\n", bigger_size);
}

int brute_force(char* a, char* b, int size_of_a, int size_of_b) {
    int bigger_size = 0, size = 0;
    int i, j, k;
    for(i = 0; i < size_of_a; i++) {
        for (j = 0; j < size_of_b; j++) {
            size = 0;
            k = 0;
            while(a[i + k] == b[j + k] && (i+k) < size_of_a && (j + k) < size_of_b) {
                size++;
                k++;
            }
            if(size > bigger_size) {
                bigger_size = size;
            } else {
                size = 0;
                k = 0;
            }
        }
    }
    return bigger_size; 
}

int main() {
    char *word_one = malloc(MAX_SIZE * sizeof(char));
    char *word_two = malloc(MAX_SIZE * sizeof(char));

    while(!feof(stdin)) {
        fgets(word_one, MAX_SIZE, stdin);
        if(feof(stdin)) {
            break;
        } else {    
            fgets(word_two, MAX_SIZE, stdin);
            find_substring(word_one, word_two);
        }
    }

    free(word_one);
    free(word_two);
    return 0;
}