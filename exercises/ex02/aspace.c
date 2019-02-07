/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void printLocal(){
    int a = 32;
    printf("Address of local variable a is %p\n", &a);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(128);
    void *m = malloc(1);
    void *n = malloc(1);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of printLocal is %p\n", printLocal);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("q points to %p\n", q);
    printf ("s points to %p\n", s);
    printf ("m points to %p\n", m);
    printf ("n points to %p\n", n);
    printLocal();
    return 0;
}
/*
1. Compile and run `aspace.c` in this directory.

Result:
Address of main is 0x104cf7e60
Address of var1 is 0x104cf8020
Address of var2 is 0x7ffeeaf08a48
p points to 0x7f90ac402730
s points to 0x104cf7f40

2. Read the code.  You might want to [read about malloc here](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm).

So it dynamically allocates memory in heap of the given type and of the given size in bytes.

3. Based on the output, draw a sketch of the virtual address space (see page 80 of HFC).  Show the relative locations of the stack, heap, globals, constants, and code.
-------------
(stack)
var1
*s
main
-------------
(heap)
*p
-------------
(globals)
var2
-------------
(constants)
-------------
(code)

4. Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses). 
Result: 
Address of main is 0x104763e30
Address of var1 is 0x104764020
Address of var2 is 0x7ffeeb49ca48
p points to 0x7fef96402730
q points to 0x7fef964027b0
s points to 0x104763f34

so the heap grew up by (11 - 3) * 16 = 128 bytes, which is expected!

5. Add a function that prints the address of a local variable, and check whether the stack grows down.  
Address of main is 0x10c986dd0
Address of printLocal is 0x10c986da0
(so the stack grows down)
Address of var1 is 0x10c987020
Address of var2 is 0x7ffee3279a48
p points to 0x7fb647402730
q points to 0x7fb6474027b0
s points to 0x10c986f13
Address of local variable a is 0x7ffee32799fc

6. Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.
I allocated 1 byte each,
m points to 0x7f94eec02830
n points to 0x7f94eec02840
*/