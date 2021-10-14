#include <stdio.h>

int main(){

    const int N = 10;
    int mas[N];

    int k = 0;

    for(int i = 0; i < N; i++){

        mas[i] = 0;
        printf("%d ", mas[i]);
    }
    printf("\n");

    printf("Enter index: ");
    scanf("%d", &k);

    // mas[k] = x
    asm
    (
        "movl	$0xFF, 3(%[mas], %q[k], 4)\n"
        :
        : [k]"g"(k), [mas]"r"(mas)
        : "cc", "memory"
    );

    for(int i = 0; i < N; i++){

        printf("%d ", mas[i]);
    }
    printf("\n");

    return 0;
}
