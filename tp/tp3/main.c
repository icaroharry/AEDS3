#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int n, r, i, j, k;
    restriction *R;
    long int x, y;
    graph g;


    scanf("%d\n", &n);
    create_graph(&g, n);
    for(i = 0; i < n; i++) {
        scanf("%ld %ld", &x, &y);
        for(k = 0; k < i; k++) {
            new_edge(&g, j, k, distance(x[j], y[j], x[k], y[k])); 
        }
    }

    scanf("%d\n", &r);
    R = (restriction *)malloc(r * sizeof(restriction));
    for(j = 0; j < r; j++) {
        scanf("%d %d", &(R[j].a), &(R[j].b));
    }
    return 0;
}