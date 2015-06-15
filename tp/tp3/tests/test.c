#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include "../graph.h"

int main() {
    struct node *a = NULL;
    struct node *b = NULL;
    struct node *c = NULL;
    struct node *d = NULL;
    int i, x, j;
    clock_t begin, end;
    double time_spent;
    double media = 0;

    srand (time(NULL));
    for(j = 7; j < 22; j++) {
        
        int p = pow(2, (int)j);

        for(x = 0; x < 10; x++) {
            for(i = 0; i <= p; i++) {
                insert_node((int)rand()%p + 1, i, &a);
            }
            //for(i = 1; i <= p; i++) {
                split_treap(i, &a, &b, &c);
            //}
            begin = clock();
            merge_treaps(&b, &c, 'R');
            end = clock();
            a = b;
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            media += time_spent;
        }

        printf("[%d, %f],\n",j, media/10);
    }

    return 0;
}