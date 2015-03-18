#include <stdio.h>
#include "../treap.h"
#include "../../../lib/minunit.h"
   
int tests_run = 0;
 
struct node *a;

static char * test_insert() {
    insert_node(3, &a);
    insert_node(1, &a);
    insert_node(4, &a);
    mu_assert("error, value of node a must be 3", (*a).value == 3);
    mu_assert("error, value of node left a must be 1", (*a).left->value == 1);
    mu_assert("error, value of node right a must be 4", (*a).right->value == 4);
    return 0;
}

static char * test_search() {
    mu_assert("error, search of 3 must return 3", search_node(3, a) == 3);
    mu_assert("error, search of 1 must return 1", search_node(1, a) == 1);
    mu_assert("error, search of 4 must return 4", search_node(4, a) == 4);
    mu_assert("error, search of 5 must return -1", search_node(5, a) == -1);
    return 0;
}
 
static char * all_tests() {
    mu_run_test(test_insert);
    mu_run_test(test_search);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}