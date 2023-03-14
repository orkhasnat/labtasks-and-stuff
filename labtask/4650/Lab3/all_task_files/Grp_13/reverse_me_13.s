generate_hash:
	pushq	%rbx
	movq	%rdi, %rbx
	movzbl	%bh, %ecx
	movabsq	$4176097094566005295, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	sarq	$19, %rdx
	movq	%rdi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	imulq	$2315896, %rdx, %rax
	subq	%rax, %rbx
	movq	%rbx, %rdx
	imulq	%rbx, %rcx
	xorq	$31, %rdx
	imulq	%rdx, %rcx
	movabsq	$-4661332621992428921, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	leaq	(%rdx,%rcx), %rax
	sarq	$24, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$22450183, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	popq	%rbx
	ret
