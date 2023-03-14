generate_hash:
	leaq	(%rdi,%rdi,2), %rsi
	movabsq	$5863562294421412651, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	sarq	$12, %rdx
	movq	%rdi, %rax
	sarq	$63, %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	imulq	$12886, %rcx, %rax
	subq	%rax, %rdi
	movq	%rdi, %rcx
	subq	%rdi, %rsi
	movabsq	$5270498306774157605, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	sarq	%rdx
	sarq	$63, %rcx
	subq	%rcx, %rdx
	leaq	(%rsi,%rdx), %rcx
	movabsq	$-5380300369029205545, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	leaq	(%rdx,%rcx), %rax
	sarq	$28, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$378967703, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	ret
