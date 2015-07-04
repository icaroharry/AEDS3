#include "casinoPD.h"

char** create_matrix(int i, int j) {
    int k, l;
    char **m;
    m = (char **)malloc(i * sizeof(char *));

    for (k = 0; k < i; k++) {
        m[k] = (char *)malloc(j * sizeof(char));
    }

    for(l = 0; l < i; l++) {
        for(k = 0; k < j; k++) {
            m[l][k] = 0;
        }
    }
    return m;
}

void destroy_matrix(int n, char **m) {
    int i;
    for (i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}


int play_game(int S, int sum, int X, int M, int *sequence) {
    char **m;
    int i, j;
    m = create_matrix(S + 1, X + 1);
    m[0][sum] = 1;
    for(i = 0; i < S; i++) {
        for(j = 0; j <= X; j++) {
            if(m[i][j]) {
                if(j + sequence[i] <= X) {
                    m[i+1][j + sequence[i]] = 1;
                }
                if(j - sequence[i] >= 0) {
                    m[i+1][j - sequence[i]] = 1;
                }
            }
        }
    }
    for(i = X; i > 0; i--) {
        if(m[S][i]) {
            destroy_matrix(S + 1, m);
            return i;
        }
    }
    destroy_matrix(S + 1, m);
    return -1;
}
