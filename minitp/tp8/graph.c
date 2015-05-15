#include <stdio.h>
#include <stdlib.h>

#define V 26

int char_to_index(char a) {
    return a - 97;
}

char index_to_char(int a) {
    return a + 97;
}

void dfs(char g[V][V], char visited[V], int visited_size, int nv, int v) {
    int i, j;
    if(!visited[v]) {
        visited[v] = 1;
        visited_size++;
        for(i = 0, i != v; i < nv; i++) {
            if(g[v][i] && !visited[i]) {
                printf("%d %d %c \n",v,i, index_to_char(i));
                dfs(g, visited, visited_size, nv, i);
            }
        }
    } else {
        for(j = 0; j < nv; j++) {
            if(!visited[j]) {
                dfs(g, visited, visited_size, nv, j);
            }
        }
    }
}

int main() {
    int n, v, e, i, j, k;   
    char graph[V][V] = { 0 };
    char visited[V] = { 0 };
    char v1, v2;

    scanf("%d\n", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %d\n", &v, &e);
        for(j = 0; j < e; j++) {
            scanf("%c %c\n", &v1, &v2);
            graph[char_to_index(v1)][char_to_index(v2)] = 1;
            graph[char_to_index(v2)][char_to_index(v1)] = 1;
        }
        dfs(graph, visited, 0, v, 0);
    }
    return 0;
}