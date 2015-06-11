#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define MAX 23

int main() {
    int n, r, i, j, k, ra, rb, u, t;
    restriction *R;
    int restricted = 0;
    long int x[23], y[23];
    graph g;
    graph restrictions;
    create_graph(&g, MAX, 0);
    create_graph(&restrictions, MAX, 1);
    int control = 1;
    while(control) {
        scanf("%d\n", &n);
        if(n == 0) {
            break;
        }
        for(i = 0; i < n; i++) {
            scanf("%ld %ld\n", &x[i], &y[i]);
            for(k = 0; k < i; k++) {
                new_edge(&g, i, k, distance(x[i], y[i], x[k], y[k]), 0); 
            }
        }

        scanf("%d\n", &r);
        if(r == 0) {
            control = 0;
        } else {
            R = (restriction *)malloc(r * sizeof(restriction));
            for(j = 0; j < r; j++) {
                scanf("%d %d\n", &ra, &rb);
                if(restrictions.m[rb][ra]) {
                    restricted = 1;
                }
                new_edge(&restrictions, ra, rb, 1, 1);
            }      
        }

        if(!restricted) {
            tsp(&g, n, &restrictions);
        } else {
            printf("Deadlock\n");
            restricted = 0;
        }
        if(r) {
            for(u = 0; u < n; u++) {
                for(t = 0; t < n; t++) {
                    restrictions.m[u][t] = 0;
                }
            }
            free(R);
        }
    }

    destroy_graph(&g, MAX);
    destroy_graph(&restrictions, MAX);
    return 0;
}