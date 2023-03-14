generate_hash:
	movabsq	$6892602702244265115, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	sarq	$27, %rdx
	movq	%rdi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	imulq	$359208297, %rdx, %rax
	movq	%rdi, %rdx
	subq	%rax, %rdx
	addq	%rdx, %rdi
	movq	%rdi, %rsi
	shrq	$63, %rsi
	addq	%rdi, %rsi
	movq	%rsi, %rcx
	sarq	%rcx
	movabsq	$838450567299412615, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	sarq	$20, %rdx
	sarq	$63, %rsi
	subq	%rsi, %rdx
	imulq	$23069712, %rdx, %rax
	movq	%rcx, %rdx
	subq	%rax, %rdx
	imulq	%rdx, %rcx
	movabsq	$861544275413644431, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	movq	%rdx, %rax
	sarq	$16, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$1403208, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	ret
