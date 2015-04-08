#include <stdio.h>
#include "../treap.h"
#include "../../../lib/minunit.h"
   
int tests_run = 0;
 
struct node *a = NULL, *b = NULL, *c = NULL;



static char * test_treap() {
    
    return 0;
}

static char * test_search() {  

    return 0;
}

static char * test_split() {

    return 0;
}

static char * all_tests() {
    mu_run_test(test_insert);
    mu_run_test(test_search);
    mu_run_test(test_split);
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