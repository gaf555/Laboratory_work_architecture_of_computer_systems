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
        "movl    %[x], %%eax\n"
        "addl    $79, %%eax\n"
        "movl    %[y], %%ecx\n"
        "cltd\n"
        "idivl   %%ecx\n"
        "movl    %%eax, %[z]\n"
        :[z]"=rm"(z)
        :[x]"g"(x), [y]"g"(y), "[z]"(z)
    );

    // w = (x + 79) % y
    asm
    (
        "movl   %[x], %%eax\n"
        "addl   $79, %%eax\n"
        "cltd\n"
        "idivl  %[y]\n"
        "movl   %%edx, %[w]\n"
        :[w]"=rm"(w)
        :[x]"g"(x), [y]"g"(y), "[w]"(w)
    );


    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    printf("w = %d\n", w);

    printf("Press <Enter> to continue...");

    return 0;
}
