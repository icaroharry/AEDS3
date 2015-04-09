#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int park_car(int car_number, int car_size, int* park, int park_size, int* map) {
    int i, j, k, empty, payment = 0;
    for(i = 0; i < park_size; i++) {
        empty = 0;
        k = i;
        while(park[k] == 0 && empty < car_size && k < park_size) { empty++; k++; }
        if(empty >= car_size) {
            for(j = i; j < k; j++) {
                park[j] = car_number;
            }
            map[car_number] = i;
            payment = 10;
            break;
        }
        i += (k-i);
    }
    return payment;
}

void free_car(int car_number, int* park, int park_size, int* map) {
    int i, j;
    i = map[car_number];
    while(park[i] == car_number && i < park_size) {
        park[i] = 0;
        i++;
    }
    map[car_number] = 0;
}

int main() {
    int park_size, n, i, aux_space;
    int car_number, car_size;
    int money;
    char op;
    int j;

    while(scanf("%d %d\n", &park_size, &n) != EOF) {
        money = 0;
        int park[park_size];
        int m;
        for(m = 0; m < park_size; m++) {
            park[m] = 0;
        }
        int map[10000];
        for(m = 0; m < 10000; m++) {
            map[m] = 0;
        }

        for(i = 0; i < n; i++) {   
            op = getchar();
            if(op == 'C') {
                scanf("%d %d", &car_number, &car_size);
                money += park_car(car_number, car_size, &park[0], park_size, &map[0]);
            } else if(op == 'S') {   
                scanf("%d", &car_number);
                free_car(car_number, &park[0], park_size, &map[0]);
            }
            getchar();
        }
        printf("%d\n", money);
    }
    return 0;
}