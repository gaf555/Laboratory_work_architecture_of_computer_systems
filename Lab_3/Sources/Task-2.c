#include <stdio.h>

int main() {

    int x = 0, y = 1, z = 0, w = 0;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    int* p = &x;
    int* q = &y;

    // z = (x + 79) / y
    asm
    (
        "movq       (%rbp-24), %rax\n"
        "movl       (%rax), %eax\n"
        "addl       $79, %%eax\n"
        "pxor       %xmm0, %xmm0\n"
        "cvtsi2sdl  %eax, %xmm0\n"
        "movsd      %xmm0, -16(%rbp)\n"
        "movq       -32(%rbp), %rax\n"
        "movl       (%rax), %eax\n"
        "pxor       %xmm1, %xmm1\n"
        "cvtsi2sdl  %eax, %xmm1\n"
        "movsd      -16(%rbp), %xmm0\n"
        "divsd      %xmm1, %xmm0\n"
        "movsd      %xmm0, -16(%rbp)\n"

    );

    // w = (x + 79) % y
    asm
    (
        "movq       -24(%rbp), %rax\n"
        "movl       (%rax), %eax\n"
        "addl       $79, %eax\n"
        "pxor       %xmm0, %xmm0\n"
        "cvtsi2sdl  %eax, %xmm0\n"
        "movsd      %xmm0, -16(%rbp)\n"
        "movq       -32(%rbp), %rax\n"
        "movl       (%rax), %ecx\n"
        "movl       -4(%rbp), %eax\n"
        "cltd\n"
        "idivl      %ecx\n"
        "movl       %edx, -4(%rbp)\n"

    );



    printf("z = %d\n", z);
    printf("w = %d\n", w);

    printf("Press <Enter> to continue...");

    return 0;
}

