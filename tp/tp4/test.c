#include <stdio.h>
#include <stdlib.h>
#include "casinoPD.h"
#include <time.h>

#define limit 50

int main () {
    int bigger, i, j;
    int *sequence = NULL;
    clock_t begin, end;
    double time_spent;

        for(i = 1; i <= limit; i++) {
            sequence = (int *)malloc((i + 1) * sizeof(int));
            for(j = 0; j < i; j++) {
                sequence[j] = 1;
            }
            sequence[i] = 0;
            bigger = -1;
            begin = clock();
            play_game(i, 0, limit, 30, sequence);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("[%d, %f],\n",i, time_spent);
        }

    return 0;
}
