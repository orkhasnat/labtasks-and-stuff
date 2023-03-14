generate_hash:
	movq	%rdi, %rsi
	movabsq	$-6640827866535438581, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	leaq	(%rdx,%rdi), %rcx
	sarq	$6, %rcx
	movq	%rdi, %rax
	sarq	$63, %rax
	subq	%rax, %rcx
	leaq	(%rcx,%rcx,4), %rax
	leaq	(%rax,%rax,4), %rax
	salq	$2, %rax
	subq	%rax, %rdi
	imulq	%rdi, %rcx
	subq	%rsi, %rcx
	movq	%rcx, %rax
	cqto
	idivq	%rdi
	imulq	%rax, %rcx
	movabsq	$6892602702244265115, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	movq	%rdx, %rax
	sarq	$27, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$359208297, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	ret
