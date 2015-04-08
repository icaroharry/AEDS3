#include <stdio.h>
#include "../treap.h"

int main() {
    struct node *a = NULL;
    int i, x;
    for(i = 10000, x = 0; i >= 0; i--) {
        x++;
        printf("INSERT %d\n", i);
        insert_node(i, x, &a);
    }
    for(i = 10000, x = 0; i >= 0; i--) {
        x++;
        printf("REMOVE %d\n", i);
        remove_node(i, &a);
    }
    locate_node(1, &a);
    return 0;
}