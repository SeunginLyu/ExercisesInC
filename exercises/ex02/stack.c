/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
/*
1.  Read `stack.c`, which should be in this directory.  What is it
intended to do?  What would the output be if the program worked as
expected?

It will print out 42 five times.

2.  Compile it.  Do you get a warning?  What does it mean?

warning: address of stack memory associated with local variable 'array' returned
      [-Wreturn-stack-address]
    return array;

It means that an adress of local variable is being returned (which is not allowed because the local variable 
array will be soon gone! What is the address going to point at then??)

3.  Run it.  What happens?  You might get a segmentation fault, or you might get
some strange output.  Can you explain it?  You might find it
helpful to draw a stack diagram.
0x7ffee0e57a00
0x7ffee0e57a00
0
446543434
0
0
0
It surprisingly ran without an error, but of course did not behave as we intended to do
because array is gone after we call foo().

4.  Comment out the `print` statements in `foo()` and `bar()` and run
it again.  What happens now?

0
-1814367428
0
0
0

5.  Add comments to the code to explain these experiments and the results,
then check the code in to the repo.

Moral: Don't return pointers to stack allocated data!
*/