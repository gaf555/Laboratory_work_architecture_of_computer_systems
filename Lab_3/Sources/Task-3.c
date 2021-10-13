#include <stdio.h>

int main()
{
	int x, y, w, z, trash;

	scanf("%d", &x);
	scanf("%d", &y);


	asm(
		"movl $79,%%eax\n"
		"addl %2,%%eax\n"
		"idiv %3\n"
		"movl %%al , %0\n"
		"movl %%ah , %1"
		:"+r"(w), "+r"(z)
		: "r"(x), "r"(y)
		: "cc"
	);

	return 0;
}
