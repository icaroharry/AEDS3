#include <stdio.h>
#include <stdlib.h>
#include "casinoPD.h"

int main () {
    int I, S, begin, X, M, i, j, bigger;
    int *sequence = NULL;
    while(!feof(stdin)) {
        scanf("%d\n", &I);
        for(i = 0; i < I; i++) {
            scanf("%d %d %d %d\n", &S, &begin, &X, &M);
            sequence = (int *)malloc((S + 1) * sizeof(int));
            for(j = 0; j < S; j++) {
                scanf("%d ", &sequence[j]);
            }
            sequence[S] = 0;
            bigger = play_game(S, begin, X, M, sequence);

            char c = bigger < M ? 'N' : 'S';
            printf("%c,%d\n", c, bigger);
            free(sequence);
        }
    }
    return 0;
}
