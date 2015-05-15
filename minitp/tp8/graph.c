#include <stdio.h>
#include <stdlib.h>

#define V 26

int count;

int char_to_index(char a) {
    return a - 97;
}

char index_to_char(int a) {
    return a + 97;
}

int dfs(char g[V][V], char visited[V], int nv, int v) {
    int i, j;
    printf("%c,", index_to_char(v));
    visited[v] = 1;
    count++;
    for(i = 0, i != v; i < nv; i++) {
        printf("%d %d ",v, i); 
        if(g[v][i] && !visited[i]) {
            return dfs(g, visited, nv, i);   
        }
    }
}

int main() {
    int n, v, e, i, j, k, number = 0;   
    char v1, v2;
    int v1_int, v2_int;

    scanf("%d\n", &n);
    for(i = 0; i < n; i++) {
        char graph[V][V] = { 0 };
        scanf("%d %d\n", &v, &e);
        for(j = 0; j < e; j++) {
            scanf("%c %c\n", &v1, &v2);
            v1_int = char_to_index(v1); 
            v2_int = char_to_index(v2);
            printf("%d %d\n", v1_int, v2_int);
            graph[v1_int][v2_int] = 1;
            graph[v2_int][v1_int] = 1;
        }
        for(j = 0; j < v; j++) {
            for(k = 0; k < v; k++) {
                printf("%d ", graph[j][k]);
            }
            printf("\n");
        }
        printf("Case #%d\n", i+1);
        k = 0;
        count = 0;
        number = 0;
        char visited[V] = { 0 }; 
        while(count < v) {
            if(!visited[k]) {
                number++;
                dfs(graph, visited, v, k);
                printf("\n");
            }
            k++;
        }
        printf("%d connected components\n\n", number);

    }
    return 0;
}
