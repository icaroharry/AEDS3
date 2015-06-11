#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
#define size 505
#define infinity 20000
  
 
int dijkstra(int o, int d, int n, int graph[size][size]) {
    int i, j, aux_i, aux = -1, vis = 0, smallest, cur;
    int visited[size], distance[size], prev[size], currents[size];
      
    for(i = 0; i < n; i++) {
        visited[i] = 0;
        distance[i] = infinity;
        prev[i] = -1;
        currents[i] = -1;
    }
 
    cur = o;
    distance[cur] = 0;
    visited[cur] = 1;
     
    while(1) {
        visited[cur] = 1;
        smallest = infinity;
        aux = aux_i;
        aux_i = -1;
        for(i = 0, cur != i; i < n; i++) {
            if(visited[i] == 0 && graph[cur][i] != -1) {
                if((graph[cur][i] + distance[cur]) < distance[i]) {
                    distance[i] = graph[cur][i] + distance[cur];
                    prev[i] = cur;
                    visited[cur] = 0;
                }
                if(distance[i] < smallest) {    
                    smallest = distance[i];
                    aux_i = i;
                }
            }
        }
        if(aux_i == -1) {
            //visited[currents[cur]] = 0;
            aux_i = prev[cur];
            //visited[prev[aux_i]] = 0;
            if(aux_i == -1) {
                break;
            }
        }
        cur = aux_i;
    }
 
    return distance[d];
}
  
int main() {
    int n, e, x, y, h, k, o, d, i, j, l, m;
    int dij;
  
    while(1) {
        int graph[size][size];
        scanf("%d %d\n", &n, &e);
        if(n == 0 && e == 0) {
            break;
        }
  
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) { 
                graph[i][j] = -1;
            }
        }
  
          
        for(l = 0; l < e; l++) {
            scanf("%d %d %d\n", &x, &y, &h);
            graph[x-1][y-1] = h;
            if(graph[y-1][x-1] != -1) {
                graph[x-1][y-1] = 0;
                graph[y-1][x-1] = 0;
            }
        }

        scanf("%d\n", &k);
        for(j = 0; j < k; j++) {
            scanf("%d %d\n", &o, &d);
            dij = dijkstra(o-1, d-1, n, graph);
            if(dij == infinity) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", dij);
            }
        }
        printf("\n");
    }

    return 0;
}