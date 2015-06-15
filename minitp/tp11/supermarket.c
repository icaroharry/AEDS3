#include <stdio.h>
#include <stdlib.h>

#define MAX 101

int main() {
    int m, n, i, j, k;
    double p;
    int products[MAX];
    char c;

    while(1) {
        
        scanf("%d %d\n", &m, &n);
        if(m == 0 && m == 0) {
            break;
        }

        for(i = 0; i < m; i++)
            scanf("%d ", &products[i]);

        for(j = 0; j < m; j++)
            scanf("%d %f\n", &k, &p);
    
    }
    
    
    return 0;
}