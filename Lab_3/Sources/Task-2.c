#include <stdio.h>

int main() {

    int x = 0, y = 1, z = 0, w = 0;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    // z = (x + 79) / y;
    // w = (x + 79) % y;

    asm
    (
        "addl   (%[p]), %[z]\n"
        "addl   $79, %[z]\n"
        "addl   %[z], %[w]\n"
        "movl   %[z], %%eax\n"
        "cltd\n"
        "idivl  (%[q])\n"
        "movl   %%eax, %[z]\n"
        "movl   %%edx, %[w]\n"
        :[z]"=rm"(z), [w]"=rm"(w)
        :[p]"g"(&x), [q]"g"(&y), "[z]"(z), "[w]"(w)
        : "cc", "%eax", "%ecx", "%edx"
    );

    printf("z = %d\n", z);
    printf("w = %d\n", w);

    printf("Press <Enter> to continue...");

    return 0;
}
