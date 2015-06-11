#include <math.h>
#include <stdlib.h>

typedef struct stack_struct {
    int size;
    int head;
    int *positions;
} stack;

void create_stack(stack *s, int si);

void destroy_stack(stack *s);

void stack_push(stack *s, int x);

int stack_pop(stack *s);

int is_empty(stack *s);

double distance(long int x1, long int y1, long int x2, long int y2);