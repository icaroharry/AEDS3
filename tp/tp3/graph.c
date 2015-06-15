#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Creates a new graph
 * 
 * @param g     Graph pointer
 * @param n     Number of vertex
 * @param reset If true, must initialize with 0
 */
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

/**
 * Destroy a given graph
 * 
 * @param g Graph to destroy
 * @param n Number of vertex
 */
void destroy_graph(graph *g, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(g->m[i]);
    }
    free(g->m);
}

/**
 * Inserts a new edge in the given graph.
 * 
 * @param g           Given graph
 * @param v1          Vertex 1
 * @param v2          Vertex 2
 * @param value       Weight
 * @param is_directed If the graph is undirected must ab and ba must have the same weight
 */
void new_edge(graph *g, int v1, int v2, double value, int is_directed) {
    g->m[v1][v2] = value;
    if(!is_directed) {
        g->m[v2][v1] = g->m[v1][v2];
    }
}

/**
 * Modified DFS to check if exists a cycle on a given directed graph, starting from vertex V.
 * It's used to check if a Deadlock occurs.
 *
 * O(v + e)
 * 
 * @param g         Restrictions graph
 * @param v         Starting vertex
 * @param n         Number of cities
 * @param marked    Flag of already visited vertex
 * @param on_stack  Flag of vertex that are on the recursion stack
 * @param has_cycle True if there's a cycle
 */
void verify_cycle(graph *g, int v, int n, int *marked, int *on_stack, int *has_cycle) {
    int i;
    marked[v] = 1;
    on_stack[v] = 1;

    for (i = 0; i < n; i++) {
        if(g->m[v][i]) {
            if(!marked[i]) {
                verify_cycle(g, i, n, marked, on_stack, has_cycle);
            } else if (on_stack[i]) {
                *has_cycle = 1;
                return;
            }
        }
    }

    on_stack[v] = 0;
}

/**
 * Function that verifies if there's a restriction to a given vertex.
 * First the algorithm look directly to the neighbor vertex, which is the next
 * vertex to visit. If there's a restriction between then, return FALSE.
 * If this restriction is not founded, the algorithm
 * checks every adjacent edges of the given vertex and checks if the restrictions
 * were already visited, returning FALSE if not.
 *
 * @complexity O(n)
 * 
 * @param  a            Vertex a (next visited)
 * @param  b            Vertex b
 * @param  restrictions Restrictions graph
 * @param  n            Number of cities
 * @param  discovered   Already visited cities
 * @return              Boolean
 */
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

/**
 * Modified Depth First Search to check every possible path of the graph.
 * The function does it unsetting the discovered flag after the recursion.
 *
 * @complexity O(n!)
 * 
 * @param g            Cities graph
 * @param v            Current vertex
 * @param discovered   Flag of already visited cities
 * @param n            Number of cities
 * @param c            Cycle control (counts the cycle "level")
 * @param min          Current minimun path value
 * @param restrictions Restrictions graph
 * @param current      Current path weight
 */
void dfs(graph *g, int v, int *discovered, int n, int c, double *min, graph *restrictions, double current) {
    int i;
    
    discovered[v] = 1;
    
    if(c == (n - 1)) {
        if((current + g->m[v][0]) < (*min)) {
            (*min) = (current + g->m[v][0]);
        }
    }

    for(i = 0; i < n; i++) {
        if(!discovered[i]) { 
            if((current + g->m[v][i] < (*min)) && !is_restricted(i, v, restrictions, n, discovered)) {
                dfs(g, i, discovered, n, (c + 1), min, restrictions, current + g->m[v][i]);
                discovered[i] = 0;
            }
        }
    }

}

/**
 * Function that prepares the Travelling Salesman Problem
 * 
 * @param g            Cities graph
 * @param n            Number of cities
 * @param restrictions Restrictions graph
 */
void tsp(graph *g, int n, graph *restrictions) {
    int i, k, has_cycle = 0;
    int *discovered = (int *)malloc(n * sizeof(int));
    int *marked = (int *)malloc(n * sizeof(int));
    int *on_stack = (int *)malloc(n * sizeof(int));
    
    for(k = 0; k < n; k++) {
        discovered[k] = 0;
        marked[k] = 0;
        on_stack[k] = 0;
    }

    double min = 2000000000;

    /** If exists a cycle on the restrictions graph, there's a deadlock */
    for(i = 0; i < n; i++) {
        for(k = 0; k < n; k++) {
            discovered[k] = 0;
            marked[k] = 0;
            on_stack[k] = 0;
        }
        verify_cycle(restrictions, i, n, marked, on_stack, &has_cycle);
        if(has_cycle)
            break;
    }

    if(!has_cycle) {
        dfs(g, 0, discovered, n, 0, &min, restrictions, 0);
    }

    if(min != 2000000000) {
        printf("%.2f\n", min);
    } else {
        printf("Deadlock\n");
    }

    free(discovered);
    free(on_stack);
    free(marked);
}