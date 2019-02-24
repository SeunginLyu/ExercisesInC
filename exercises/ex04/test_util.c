/*
To run the test, type in your command line 
"make test_util && ./test_util.out" 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    char* res = icmpcode_v4(0);
    char *message = "test1 failed: message should be network unreachable";
    mu_assert(message, res == "network unreachable");
    return NULL;
}

static char *test2() {
    char* res = icmpcode_v4(3);
    char *message = "test1 failed: message should be port unreachable";
    mu_assert(message, res == "port unreachable");
    return NULL;
}

static char *test3() {
    char* res = icmpcode_v4(16);
    char *message = "test1 failed: message should [unknown code]";
    mu_assert(message, res == "[unknown code]");
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
