generate_hash:
	movabsq	$6892602702244265115, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	sarq	$27, %rdx
	movq	%rdi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	imulq	$359208297, %rdx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rcx
	shrq	$63, %rcx
	addq	%rdi, %rcx
	sarq	%rcx
	movabsq	$6892707567992561233, %rdx
	movq	%rsi, %rax
	imulq	%rdx
	sarq	$23, %rdx
	movq	%rsi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	imulq	$22450177, %rdx, %rax
	subq	%rax, %rsi
	imulq	%rsi, %rcx
	movabsq	$-7246881003775555887, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	leaq	(%rdx,%rcx), %rax
	sarq	$22, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$6908232, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	ret
