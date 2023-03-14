generate_hash:
	leaq	-32(%rdi), %rcx
	xorq	$31, %rdi
	imulq	%rdi, %rcx
	movabsq	$1907424770613173201, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	sarq	$13, %rdx
	movq	%rdi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	imulq	$79225, %rdx, %rax
	subq	%rax, %rdi
	addq	%rdi, %rcx
	movabsq	$3446094983535943863, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	movq	%rdx, %rax
	sarq	$22, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$22451863, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	ret
