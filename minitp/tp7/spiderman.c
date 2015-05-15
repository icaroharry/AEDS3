#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define V 500
#define infinity 100000.0

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double prim(double graph[V][V], int n) {
    int i, j, k, l, min_index;
    
    int mstSet[V] = { 0 };
    
    double weights[V] = { [1 ... V-1] = infinity };
    double path = 0.0;
    double min;

    weights[0] = 0.0;

    for(i = 0; i < n; i++) {
        min = infinity;
        for (j = 0; j < n; j++) {
            if (mstSet[j] == 0 && weights[j] < min) {
                min = weights[j];
                min_index = j;
            }
        }
        
        mstSet[min_index] = 1;
        for (k = 0, k != min_index; k < n; k++) {
            if(mstSet[k] == 0 && graph[min_index][k] < weights[k]) {
                weights[k] = graph[min_index][k];
            }
        }
    }
    for(l = 1; l < n; l++) {
        path += weights[l];
    }
    return path * 0.01;
}

int main() {
    int c, n, i, j, k;   
    double graph[V][V];
    int x[V], y[V];

    scanf("%d\n", &c);
    for(i = 0; i < c; i++) {
        scanf("%d\n", &n);
        for(j = 0; j < n; j++) {
            scanf("%d %d\n", &x[j], &y[j]);
            for(k = 0, k != j; k < j; k++) {
                graph[j][k] = distance((double)x[j], (double)y[j], (double)x[k], (double)y[k]);
                graph[k][j] = graph[j][k]; 
            }
        }
        printf("%.2lf\n", prim(graph, n));
    }
    return 0;
}