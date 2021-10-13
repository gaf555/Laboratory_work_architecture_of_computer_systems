#include <stdio.h>

int main() {

    int x = 0, y = 1, w = 0;
    double z = 0;

    int* p = &x;
    int* q = &y;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    // z = *p + 79
    asm("movq       -24(%rbp), %rax");
    asm("movl       (%rax), %eax");
    asm("addl       $79, %eax");
    asm("pxor       %xmm0, %xmm0");
    asm("cvtsi2sdl  %eax, %xmm0");
    asm("movsd      %xmm0, -16(%rbp)");

    // w = z
    asm("movsd   -16(%rbp), %xmm0");
    asm("cvttsd2sil      %xmm0, %eax");
    asm("movl    %eax, -4(%rbp)");

    // z = z / *q
    asm("movq       -32(%rbp), %rax");
    asm("movl       (%rax), %eax");
    asm("pxor       %xmm1, %xmm1");
    asm("cvtsi2sdl  %eax, %xmm1");
    asm("movsd      -16(%rbp), %xmm0");
    asm("divsd      %xmm1, %xmm0");
    asm("movsd      %xmm0, -16(%rbp)");

    // w = w % *q;
    asm("movq       -32(%rbp), %rax");
    asm("movl       (%rax), %ecx");
    asm("movl       -4(%rbp), %eax");
    asm("cltd");
    asm("idivl      %ecx");
    asm("movl       %edx, -4(%rbp)");

    printf("w = %d\n", w);
    printf("z = %.2lf", z);

    return 0;
}
