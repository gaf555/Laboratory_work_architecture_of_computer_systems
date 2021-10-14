#include <stdio.h>

int main()
{
    int x, y, w, z;

    scanf("%d", &x);
    scanf("%d", &y);

    asm(
     "movl $79,%%eax\n"
     "addl %2,%%eax\n"
     "cdq\n"
     "idiv %3\n"
     "movl %%eax , %0\n"
     "movl %%edx , %1"
     :"+r"(w), "+r"(z)
     : "r"(x), "r"(y)
     : "cc","%eax" ,"%edx"
   );

    return 0;
}
