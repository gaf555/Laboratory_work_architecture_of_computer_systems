#include <stdio.h>

int main() {

    int x = 0, y = 1, z = 0, w = 0;

    int* p = &x;
    int* q = &y;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    // z = (*p + 79) / *q;
    asm
    (
        "movq	-16(%rbp), %rax\n"
        "movl	(%rax), %eax\n"
        "leal	79(%rax), %ecx\n"
        "movq	-24(%rbp), %rax\n"
        "movl	(%rax), %r8d\n"
        "movl	%ecx, %eax\n"
        "cltd\n"
        "idivl	%r8d\n"
        "movl	%eax, -4(%rbp)\n"
    );

    // w = (*p + 79) % *q;
    asm
    (
        "movq	-16(%rbp), %rax\n"
        "movl	(%rax), %eax\n"
        "leal	79(%rax), %edx\n"
        "movq	-24(%rbp), %rax\n"
        "movl	(%rax), %ecx\n"
        "movl	%edx, %eax\n"
        "cltd\n"
        "idivl	%ecx\n"
        "movl	%edx, -8(%rbp)\n"
    );

    printf("w = %d\n", w);
    printf("z = %d", z);

    return 0;
}
