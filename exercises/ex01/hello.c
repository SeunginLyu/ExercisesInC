#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("Y: %i\n", y);
    return 0;    
}
/*
 1. Assemply output
 movl	$5, -8(%rbp)
 movl	%eax, -12(%rbp)         ## 4-byte Spill
These two lines seem to be different,
I assume this is some sort of memory allocation?

 2. Optimization with -O2
 subq	$16, %rsp
 movl	$0, -4(%rbp)
 movl	$5, -8(%rbp)
 movb	$0, %al
 movl	%eax, -12(%rbp)         ## 4-byte Spill
 movl	%ecx, %eax
 addq	$16, %rsp
 The above lines were omitted in the optimized file,
 I would guess its because the variable was never used 
 and the optimizer chose not to allocate any memory stack for that variable.
 _printf also got replaced with _puts 
 (or does printf require some of the above lines?)

3. Printing value x with and without -O2
subq	$16, %rsp
movl	$0, -4(%rbp)
movl	$5, -8(%rbp)
movl	-8(%rbp), %esi
movb	$0, %al
movl	%eax, -12(%rbp)         ## 4-byte Spill
movl	%esi, %eax
addq	$16, %rsp

These were the lines that were removed after optmization.
It looked like, with the optimization, the complier only
assigned the value 5 to a temporary memory location?

4. Adding int y = x + 1
subq	$16, %rsp
leaq	L_.str(%rip), %rdi
movl	$0, -4(%rbp)
movl	$5, -8(%rbp)
movl	-8(%rbp), %eax
addl	$1, %eax
movl	%eax, -12(%rbp)
movl	-12(%rbp), %esi
movb	$0, %al
These lines of allocating memory for each variable got
simplified to one line of code which is
movl	$6, %esi
I conclude that this the optimization works by minimizing
memory allocation for variables, and by handling arithmetic operations
beforehand at the assembly level.
*/ 