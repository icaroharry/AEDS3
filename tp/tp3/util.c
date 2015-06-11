#include "util.h"

void create_stack(stack *s, int si) {
    s->size = si;
    s->head = 0;
    s->positions = (int *)malloc(si * sizeof(int));
}

void destroy_stack(stack *s) {
    free(s->positions);
    free(s);
}

void stack_push(stack *s, int x) {
    s->positions[s->head] = x;
    s->head++;
}

int stack_pop(stack *s) {
    int item = s->positions[s->head - 1];
    s->head--;
    return item;
}

int is_empty(stack *s) {
    if(s->head) {
        return 0;
    } else {
        return 1;
    }
}

double distance(long int x1, long int y1, long int x2, long int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}