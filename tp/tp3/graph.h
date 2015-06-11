#include "util.h"

typedef struct graph_struct {
    double **m;
} graph;

typedef struct restriction_struct {
    int a, b;
} restriction;

void create_graph(graph *g, int n, int reset);

void destroy_graph(graph *g, int n);

void new_edge(graph *g, int v1, int v2, double value, int is_directed);

double get_cicle_size(graph *g, int *cicle, int n);

int is_restricted(int a, int b, graph *restrictions, int n, int *visited);

void dfs(graph *g, int v, int *discovered, int n, int *cicle, int c, double *min, graph *restrictions, double current);

void tsp(graph *g, int n, graph *restrictions);