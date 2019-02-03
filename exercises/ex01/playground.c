#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[10];
    int *p = array;
    int* q = &array;
    int *r = array + 1;
    int *s = &array[1];
    printf("%p\n", p);
    printf("%p\n", q);
    printf("%p\n", r);
    printf("%p\n", s);
    printf("%i\n", sizeof(p));
    return 0;
}