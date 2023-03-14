generate_hash:
	movq	%rdi, %rax
	sarq	$10, %rdi
	salq	$6, %rax
	imulq	%rax, %rdi
	movabsq	$-8925843906633654007, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	addq	%rdi, %rdx
	sarq	$4, %rdx
	movq	%rdi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	xorq	%rdx, %rdi
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
