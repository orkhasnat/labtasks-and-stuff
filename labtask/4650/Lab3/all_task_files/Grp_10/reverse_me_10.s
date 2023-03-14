generate_hash:
	movq	%rdi, %rcx
	xorq	$1000, %rcx
	movabsq	$-6640827866535438581, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	leaq	(%rdx,%rdi), %rax
	sarq	$6, %rax
	movq	%rdi, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	addq	%rcx, %rax
	movq	%rax, %rcx
	salq	$30, %rcx
	imulq	%rax, %rdi
	movq	%rdi, %rax
	cqto
	idivq	%rcx
	imulq	%rax, %rdi
	movabsq	$3446094983535943863, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	movq	%rdx, %rax
	sarq	$22, %rax
	movq	%rdi, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$22451863, %rax, %rdx
	movq	%rdi, %rax
	subq	%rdx, %rax
	ret
