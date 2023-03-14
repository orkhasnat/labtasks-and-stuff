generate_hash:
	movabsq	$2361183241434822607, %rcx
	movq	%rdi, %rax
	imulq	%rcx
	movq	%rdx, %rcx
	sarq	$7, %rcx
	movq	%rdi, %rdx
	sarq	$63, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	imulq	$1000, %rax, %rsi
	movq	%rdi, %rax
	subq	%rsi, %rax
	subq	%rdx, %rcx
	imulq	%rcx, %rax
	sarq	$2, %rax
	addq	%rax, %rdi
	movq	%rdi, %rax
	cqto
	idivq	%rcx
	subq	%rax, %rdi
	movabsq	$-8030200504361374457, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	leaq	(%rdx,%rdi), %rax
	sarq	$30, %rax
	movq	%rdi, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$1901498371, %rax, %rdx
	movq	%rdi, %rax
	subq	%rdx, %rax
	ret
