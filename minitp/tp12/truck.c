#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, weight[101], painels, trucks, freight i, j, k;

    scanf("%d\n", &n);

    for(i = 0; i < n; i++) {
        scanf("%d %d %d", &painels, &trucks, &freight);
        for(j = 0; j < painels; j++) {
            /* code */
        }
    }

    getchar();

    for(j = 0; j < n; j++) {
        scanf("%d %f\n", &k, &p);
        product[j] = k;
        product_price[j] = p;
    }

    for(i = 0; i <= m; i++) {
        M[i][0] = 0;
        M[0][i] = INFINITY;
    }

    result = mr_jones_sucks(n, m);
    if(result == INFINITY) {
        printf("Impossible\n");
    } else {
        printf("%.2f\n", result);
    }


    return 0;
}
