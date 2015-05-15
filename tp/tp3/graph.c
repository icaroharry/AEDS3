#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void create_graph(graph *g, int n) {
    int i;
    g->m = (double **)malloc(n * sizeof(double *));
    
    for (i = 0; i < n; i++) {
        g->m[i] = (double *)malloc(n * sizeof(double));
    }
}

void new_edge(graph *g, int v1, int v2, double value) {
    g->m[v1][v2] = value;
    g->m[v2][v1] = g->m[v1][v2];
}