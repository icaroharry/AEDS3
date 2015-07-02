#include <stdio.h>
#include <stdlib.h>

#define INFINITY 200000

float M[100002][102];
int list[102];
int product[100002];
float product_price[100002];

float mr_jones_sucks(int n, int m) {
    int i, j, k, l;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(product[i-1] == list[j-1]) {
                if(M[i-1][j-1] + product_price[i-1] < M[i-1][j]) {
                    M[i][j] = M[i-1][j-1] + product_price[i-1];
                } else {
                    M[i][j] = M[i-1][j];
                }
            } else {
                M[i][j] = M[i-1][j];
            }
        }
    }
    return M[n][m];
}

int main() {
    int m, n, i, j, k;
    float p, result;
    char c;

    while(1) {

        scanf("%d %d\n", &m, &n);
        if(m == 0 && n == 0) {
            break;
        }

        for(i = 0; i < m; i++) {
            scanf("%d ", &list[i]);
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
    }


    return 0;
}
