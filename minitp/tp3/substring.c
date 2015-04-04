#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 52

char * filter(char vet[], int size) {
    int aux_index = 0;
    int i;
    char *aux = malloc(size * sizeof(char));
    aux[0] = vet[0];
    for (i = 1; i < size; i++) {
        if(vet[i] != aux[aux_index] && (int)vet[i] >= 97) {
            aux[aux_index+1] = vet[i];
            aux_index++;
        }
    }
    aux[aux_index] == '\0';
    return aux;
}

void insertion_sort(char vet[], int size) {
    int i, j, selected;
    for (i = 1; i < size; i++) {
        selected = vet[i];
        j = i - 1;
        while ((j>=0) && ((int)selected < (int)vet[j])) {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = selected;
    }
}

void find_string_lane(char* a) {
    int size_of_a = strlen(a);
    int i, j;
    if((int)a[size_of_a-1] == 10 && size_of_a > 0) {
        size_of_a--;
    }
    insertion_sort(a, size_of_a);
    a = filter(a, size_of_a);
    size_of_a = strlen(a);
    i = 0;
    while(i < size_of_a) {
        j = i;
        while((int)a[j] == (int)a[j+1] - 1 && j < size_of_a) {
            j++;
        }
        if((int)a[i] >= 97) {
            printf("%c:%c", a[i], a[j]);
            if(j < size_of_a - 1) {
                printf(", ");    
            }
        }
        i += (j-i) + 1;
    }
}

int main() {
    char *str = malloc(MAX_SIZE * sizeof(char));
    str[0] = 0;
    while(1) {
        strcpy(str, "\0");
        fgets(str, MAX_SIZE, stdin);
        if(strlen(str) > 0) {
            find_string_lane(str);
        }
        if(feof(stdin)) {
            break;
        } else {
            printf("\n");
        }
    }

    free(str);
    return 0;
}