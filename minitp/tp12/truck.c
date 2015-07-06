#include <stdio.h>
#include <stdlib.h>

typedef struct tr {
    int weight;
    int first;
} truck;

int fill_trucks(truck trucks[11], int weight[101], int t, int n) {
    int i, j, k = 0, small = 999999, small_index;
    for(i = 0, k = 0; i <= t; i++) {
        trucks[i].weight = weight[i];
        trucks[i].first = i;
        k++;
    }
    while(k <= n) {
        small = 999999;
        for(j = 0; j < t; j++) {
            if(trucks[j].weight + weight[trucks[j+1].first] < small) {
                small = trucks[j].weight + weight[trucks[j+1].first];
                small_index = j;
            }
        }

        trucks[small_index].weight += weight[trucks[small_index+1].first];
        trucks[small_index+1].weight -= weight[trucks[small_index+1].first];
        if(trucks[small_index+1].weight == 0) {
            for(i = small_index + 1; i < t; i++) {
                trucks[i].weight = trucks[i+1].weight;
                trucks[i].first = trucks[i+1].first;
            }
            trucks[t].weight = weight[k];
            trucks[t].first = k;
            k++;
        } else {
            trucks[small_index+1].first++;
        }
    }
    int bigger = 0;
    for (i = 0; i <= t; i++) {
        if(trucks[i].weight >= bigger) {
            bigger = trucks[i].weight;
        }
    }
    return bigger;
}

int main() {
    int n, weight[2000], painels, t, freight, i, j, k, result;
    truck trucks[2000];
    scanf("%d\n", &n);

    for(i = 0; i < n; i++) {
        scanf("%d %d %d\n", &painels, &t, &freight);
        for(j = 0; j <= t; j++) {
            trucks[j].weight = 0;
            trucks[j].first = 0;
        }
        for(j = 0; j <= painels; j++) {
            weight[j] = 0;
        }
        for(j = 0; j < painels; j++) {
            scanf("%d ", &weight[j]);
        }
        result = fill_trucks(trucks, weight, t, painels);
        printf("%d $%d\n", result, result*freight*t);
    }
    return 0;
}
