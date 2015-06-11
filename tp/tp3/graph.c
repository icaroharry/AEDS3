#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void create_graph(graph *g, int n, int reset) {
    int i, j, k;
    g->m = (double **)malloc(n * sizeof(double *));
    
    for (i = 0; i < n; i++) {
        g->m[i] = (double *)malloc(n * sizeof(double));
    }
    if(reset) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                g->m[j][k] = 0;
            }
        }
    }
}

void destroy_graph(graph *g, int n) {
    int i;

    for (i = 0; i < n; i++) {
        free(g->m[i]);
    }

    free(g->m);
}

void new_edge(graph *g, int v1, int v2, double value, int is_directed) {
    g->m[v1][v2] = value;
    if(!is_directed) {
        g->m[v2][v1] = g->m[v1][v2];
    }
}

int verify_cicle(graph *g, int v, int n, int *discovered) {
    int i;
    discovered[v] = 1;
    printf("Vzin%d\n", v);
    for(i = 0; i < n; i++) {
        if(g->m[v][i]) {
            if(discovered[i]) {
                printf("testão\n");
                return 1;
            }  else {
                verify_cicle(g, i, n, discovered);
            }
        } 
    }
    return 0;
}

double get_cicle_size(graph *g, int *cicle, int n) {
    int i;
    double dist = 0;
    for(i = 0; i < (n - 1); i++) {
        dist += g->m[cicle[i]][cicle[i+1]];
    }
    dist += g->m[cicle[n - 1]][cicle[0]];
    return dist;
}

int is_restricted(int a, int b, graph *restrictions, int n, int *discovered) {
    int i;
    if(restrictions->m[a][b]) {
        return 1;
    } else {
        for(i = 0; i < n; i++) {
            if(restrictions->m[i][a] && !discovered[i]) {
                return 1;
            }
        }
    }
    return 0;
}

void dfs(graph *g, int v, int *discovered, int n, int *cicle, int c, double *min, graph *restrictions, double current) {
    int i;
    double dist;
    discovered[v] = 1;
    cicle[c] = v;
    if(c == (n - 1)) {
        dist = current + g->m[v][0];
        if(dist < *min) {
            *min = dist;
        }
    }
    for(i = 0; i < n; i++) {
        if(!discovered[i]) { 
            if((current + g->m[v][i] < (*min)) && !is_restricted(i, v, restrictions, n, discovered)) {
                dfs(g, i, discovered, n, cicle, (c + 1), min, restrictions, current + g->m[v][i]);
                discovered[i] = 0;
            }
        }
    }

}

void tsp(graph *g, int n, graph *restrictions) {
    int k;
    int *discovered = (int *)malloc(n * sizeof(int));
    //int *discovered_cicle = (int *)malloc(n * sizeof(int));
    int *cicle = (int *)malloc(n * sizeof(int));
    for(k = 0; k < n; k++) {
        discovered[k] = 0;
        //discovered_cicle[k] = 0;
        cicle[k] = 0;
    }
    double min = 2000000000;
    //printf("%d\n", verify_cicle(g, 0, n, discovered_cicle));
    dfs(g, 0, discovered, n, cicle, 0, &min, restrictions, 0);
    if(min != 2000000000) {
        printf("%.2f\n", min);
    } else {
        printf("Deadlock\n");
    }
    free(discovered);
    free(cicle);
}