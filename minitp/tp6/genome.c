#include <stdio.h>
#include <stdlib.h>

int genome[50002];

void swap_gens(int g1, int g2) {
    int aux;
    while(g1 < g2) {
        aux = genome[g2];
        genome[g2] = genome[g1];
        genome[g1] = aux;
        g2--;
        g1++;
    }
}

int find_gen(g1, n) {
    int i;
    for(i = 0; i < n; i++) {
        if(genome[i] == g1) {
            return i + 1;
        }
    }
}

int main() {
    int n = -1, r, q, i;
    int g1, g2;
    int count = 1;
    
    while(1) {
        scanf("%d\n", &n);
        if(n == 0) {
            break;
        }

        for(i = 1; i <= n; i++) {
            genome[i-1] = i;
        }

        scanf("%d\n", &r);
        for(i = 0; i < r; i++) {
            scanf("%d %d\n", &g1, &g2);
            swap_gens(g1 - 1, g2 - 1);
        }

        printf("Genome %d\n", count);
        scanf("%d\n", &q);
        for(i = 0; i < q; i++) {
            scanf("%d\n", &g1);
            printf("%d\n", find_gen(g1, n));
        }
        count++;
    }

    return 0;
}