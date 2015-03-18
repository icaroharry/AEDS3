#include <stdio.h>
#include "treap.h"

int main() {
    struct node *a;
    insert_node(3, &a);
    insert_node(1, &a);
    insert_node(4, &a);
    int value = (*a).value;
    printf("%d", value);
    return 0;
}