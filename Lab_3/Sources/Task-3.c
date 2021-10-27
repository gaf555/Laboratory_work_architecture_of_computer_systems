#include <stdio.h>

int main()
{
    int x, y, w, z;

    scanf("%d", &x);
    scanf("%d", &y);

    asm(
     "addl $79,%2\n"
     "cdq\n"
     "idiv %3\n"
     "movl %2 , %0\n"
     "movl %3 , %1"
     :"+r"(w), "+r"(z)
     : "a"(x), "d"(y)
     : "cc", "%ecx" , "%esi"
   );
    
    printf("w = %d\n", w);
    printf("z = %d\n", z);

    return 0;
}
