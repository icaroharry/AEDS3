#include <stdio.h>
#include <stdlib.h>

int fill_trucks(int truck[11], int weight[101], int t, int n) {
    int i, j, max = 0, k = 0;
    int aux[11] = { 0 };
    truck[0] += weight[0];
    for(i = 1; i < n; i++) {
        //printf("%d\n", weight[i]);
        if(truck[k] + aux[k] <= weight[i] + (truck[k+1] - aux[k])) {
            truck[k+1] += weight[i];
            if(k < t) {
                k++;
            }
        } else {
            truck[k] += weight[i];
        }
    }

    for(j = 0; j < t; j++) {
        printf("%d\n", truck[j]);
        if(truck[j] > max) {
            max = truck[j];
        }
    }
    return max;
}

int main() {
    int n, weight[101], painels, trucks, freight, i, j, k;
    int t[11] = { 0 };
    scanf("%d\n", &n);

    for(i = 0; i < n; i++) {
        scanf("%d %d %d\n", &painels, &trucks, &freight);
        for(j = 0; j < painels; j++) {
            scanf("%d ", &weight[j]);
        }
        printf("ss%d\n", fill_trucks(t, weight, trucks, painels));
    }
    return 0;
}
