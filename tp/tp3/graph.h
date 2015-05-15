typedef struct graph_struct {
    double **m;
} graph;

typedef struct restriction_struct {
    int a, b;
} restriction;

void create_graph(graph *g, int n);

void new_edge(graph *g, int v1, int v2, double value);