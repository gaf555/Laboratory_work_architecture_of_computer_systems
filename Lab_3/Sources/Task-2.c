#include <stdio.h>

int main() {

    const int N = 10;

    int mas[N];
    int k = 0, x = 0;

    for(int i=0;i<N;i++){

        mas[i] = 0;
        printf("%d ", mas[i]);
    }
    printf("\n");

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter x: ");
    scanf("%d", &x);

    // mas[k] = x
    asm
    (
        "movl	-84(%rbp), %edx\n"
        "movl	-88(%rbp), %ecx\n"
        "movq	-80(%rbp), %rax\n"
        "movslq	%edx, %rdx\n"
        "movl	%ecx, (%rax,%rdx,4)\n"
    );

    for(int i=0;i<N;i++){

        printf("%d ", mas[i]);
    }
    printf("\n");

    printf("Press <Enter> to continue...");

    return 0;
}
