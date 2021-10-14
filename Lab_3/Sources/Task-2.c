#include <stdio.h>

int main() {

    int x = 0, y = 1, z = 0, w = 0;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    // p = &x
    // q = &y

    // z = (x + 79) / y
    asm
    (
        "movl    (%[p]), %%eax\n"
        "addl    $79, %%eax\n"
        "movl    (%[q]), %%ecx\n"
        "cltd\n"
        "idivl   %%ecx\n"
        "movl    %%eax, %[z]\n"
        :[z]"=rm"(z)
        :[p]"r"(&x), [q]"r"(&y), "[z]"(z)
        : "cc", "%eax", "%ecx"
    );

    // w = (x + 79) % y
    asm
    (
        "movl   (%[p]), %%eax\n"
        "addl   $79, %%eax\n"
        "cltd\n"
        "idivl  (%[q])\n"
        "movl   %%edx, %[w]\n"
        :[w]"=rm"(w)
        :[p]"r"(&x), [q]"r"(&y), "[w]"(w)
        : "cc", "%eax", "%ecx"
    );

    printf("z = %d\n", z);
    printf("w = %d", w);

    return 0;
}
