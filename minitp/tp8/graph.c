#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 27

int count;
char result[V];

int char_to_index(char a) {
    return a - 97;
}

char index_to_char(int a) {
    return a + 97;
}

void insertionSort(char res[], int size) {
    int i, j;
    char selected;
    for (i = 1; i < size; i++) {
        selected = res[i];
        j = i - 1;
        while ((j>=0) && (selected < res[j])) {
            res[j+1] = res[j];
            j--;
        }
        res[j+1] = selected;
    }
}

void dfs(char g[V][V], char visited[V], int nv, int v) {
    int i, j;
    visited[v] = 1;
    result[count] = index_to_char(v);
    count++;

    for(i = 0, i != v; i < nv; i++) {

        if(g[v][i] && !visited[i]) {
            dfs(g, visited, nv, i);
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
            graph[v1_int][v2_int] = 1;
            graph[v2_int][v1_int] = 1;
        }
        printf("Case #%d:\n", i+1);
        k = 0;
        count = 0;
        number = 0;
        int aux_cont = 0;
        char visited[V] = { 0 }; 
        while(count < v) {
            if(!visited[k]) {
                number++;
                aux_cont = count;
                memset(result, '\0', V);
                dfs(graph, visited, v, k);
                if(count > 0) {
                    insertionSort(result, count);
                    for(j = aux_cont; j < count; j++) {
                        printf("%c,", result[j]);
                    }
                    printf("\n");
                }
            }
            k++;
        }
        printf("%d connected components\n\n", number);

    }
    return 0;
}
