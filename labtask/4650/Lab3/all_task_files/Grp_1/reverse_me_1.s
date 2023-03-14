generate_hash:
	endbr64
	movq	%rdi, %rsi
	shrq	$63, %rsi
	addq	%rdi, %rsi
	movq	%rsi, %r8
	sarq	%r8
	subq	%r8, %rdi
	movabsq	$6892602702244265115, %rdx
	movq	%r8, %rax
	imulq	%rdx
	movq	%rdx, %rcx
	sarq	$27, %rcx
	sarq	$63, %rsi
	subq	%rsi, %rcx
	imulq	$359208297, %rcx, %rax
	movq	%r8, %rcx
	subq	%rax, %rcx
	movabsq	$-4661332621992428921, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	addq	%rdi, %rdx
	sarq	$24, %rdx
	movq	%rdi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	imulq	$22450183, %rdx, %rax
	subq	%rax, %rdi
	imulq	%rdi, %rcx
	movabsq	$5599904784727877925, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	movq	%rdx, %rax
	sarq	$21, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$6908265, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	ret
