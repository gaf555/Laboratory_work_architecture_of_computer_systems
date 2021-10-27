.ENTER_X_STR:
	.ascii "Enter x: \0"

.ENTER_Y_STR:
	.ascii "Enter y: \0"

.INT_FORMAT_STR:
	.ascii "%d\0"

.RESULT_STR:
	.ascii "Z = %d\12\0"

.globl  main

main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
    
    # int x = 0;
	movl	$0, -8(%rbp)
    
    # int y = 0
	movl	$0, -12(%rbp)
    
    # int z = 0;
	movl	$0, -4(%rbp)
    
    # printf("Enter x: ");
	leaq	.ENTER_X_STR(%rip), %rcx
	call	printf
    
    # scanf("%d", &x);
	leaq	-8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.INT_FORMAT_STR(%rip), %rcx
	call	scanf
    
    # printf("Enter y: ");
	leaq	.ENTER_Y_STR(%rip), %rcx
	call	printf
    
    # scanf("%d", &y);
	leaq	-12(%rbp), %rax
	movq	%rax, %rdx
	leaq	.INT_FORMAT_STR(%rip), %rcx
	call	scanf
    
    # z = 1234;
	movl	$1234, -4(%rbp)
    
    # z = z + x;
	movl	-8(%rbp), %eax
	addl	%eax, -4(%rbp)
    
    # z = z - 5 * y;
	movl	-12(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	negl	%eax
	addl	%eax, -4(%rbp)
    
    # printf("Z = %d\n", z);
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.RESULT_STR(%rip), %rcx
	call	printf
    
    # movl    $0, %eax
	movl	$0, %eax
    
	addq	$48, %rsp
	popq	%rbp
	ret
