generate_hash:
	movq	%rdi, %rax
	leaq	0(,%rdi,4), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, %rsi
	addq	%rdx, %rcx
	movabsq	$-7243027625620239127, %rdx
	movq	%rsi, %rax
	imulq	%rdx
	addq	%rsi, %rdx
	sarq	$10, %rdx
	movq	%rsi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	imulq	$1686, %rdx, %rax
	subq	%rax, %rsi
	imulq	%rsi, %rcx
	movabsq	$1723047525343506057, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	movq	%rdx, %rax
	sarq	$25, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$359229801, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	ret
