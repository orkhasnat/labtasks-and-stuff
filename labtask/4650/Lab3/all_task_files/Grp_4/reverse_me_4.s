generate_hash:
	movq	%rdi, %rcx
	sarq	$2, %rcx
	imulq	%rcx, %rdi
	imulq	%rdi, %rcx
	movabsq	$-7243027625620239127, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	addq	%rdi, %rdx
	sarq	$10, %rdx
	movq	%rdi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	imulq	$1686, %rdx, %rax
	subq	%rax, %rdi
	imulq	%rdi, %rcx
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
