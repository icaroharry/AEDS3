#include "util.h"

typedef struct graph_struct {
    double **m;
} graph;

void create_graph(graph *g, int n, int reset);

void destroy_graph(graph *g, int n);

void new_edge(graph *g, int v1, int v2, double value, int is_directed);

void verify_cycle(graph *g, int v, int n, int *marked, int *on_stack, int *has_cycle);

int is_restricted(int a, int b, graph *restrictions, int n, int *visited);

void dfs(graph *g, int v, int *discovered, int n, int c, double *min, graph *restrictions, double current);

void tsp(graph *g, int n, graph *restrictions);