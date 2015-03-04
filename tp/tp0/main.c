#include <stdio.h>
#include "operations.h"

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", sum(a, b));
    return 0;
}