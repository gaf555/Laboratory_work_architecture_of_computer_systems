#include <stdio.h>

int main() {

    int x = 0, y = 1, z = 0, w = 0;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    // z = (x + 79) / y
    asm
    (
        "movq       -24(%rbp), %rax"
        "movl       (%rax), %eax"
        "addl    $79, %%eax\n"
        "pxor       %xmm0, %xmm0"
        "cvtsi2sdl  %eax, %xmm0"
        "movsd      %xmm0, -16(%rbp)"
        "movq       -32(%rbp), %rax"
        "movl       (%rax), %eax"
        "pxor       %xmm1, %xmm1"
        "cvtsi2sdl  %eax, %xmm1"
        "movsd      -16(%rbp), %xmm0"
        "divsd      %xmm1, %xmm0"
        "movsd      %xmm0, -16(%rbp)"
       
    );

    // w = (x + 79) % y
    asm
    (
         "movq       -24(%rbp), %rax"
        "movl       (%rax), %eax"
        "addl       $79, %eax"
        "pxor       %xmm0, %xmm0"
        "cvtsi2sdl  %eax, %xmm0"
        "movsd      %xmm0, -16(%rbp)"
        "movq       -32(%rbp), %rax"
        "movl       (%rax), %ecx"
        "movl       -4(%rbp), %eax"
        "cltd"
        "idivl      %ecx"
        "movl       %edx, -4(%rbp)"
       
    );


   
    printf("z = %d\n", z);
    printf("w = %d\n", w);

    printf("Press <Enter> to continue...");

    return 0;
}
