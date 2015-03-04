#include <stdio.h>
#include "../../../lib/minunit.h"
   
int tests_run = 0;
 
int a = 7;
int b = 4;

int sum(int a, int b) {
    return a + b;
}
 
static char * test_sum() {
    mu_assert("error, sum 4 + 7 != 11", sum(a, b) == 11);
    return 0;
}
 
static char * all_tests() {
    mu_run_test(test_sum);
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