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

    printf("Enter index: ");
    scanf("%d", &k);

    printf("Enter value: ");
    scanf("%d", &x);

    if((k >= 0) && (k < N)){

        // mas[k] = x
        asm
        (
            "movl	%[x], (%[mas], %q[k], 4)\n"
            :
            :[x]"g"(x), [k]"g"(k), [mas]"r"(mas)
            : "cc", "memory"
        );
    }

    for(int i=0;i<N;i++){

        printf("%d ", mas[i]);
    }
    printf("\n");

    printf("Press <Enter> to continue...");

    return 0;
}
