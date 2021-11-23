	.file	"main.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d < %d -> %d\n"
.LC1:
	.string	"%d + %d = %d\n"
.LC2:
	.string	"%d - %d = %d\n"
.LC3:
	.string	"%d * %d = %d\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC4:
	.string	"Must supply 2 integers arguments."
	.text
	.globl	main
	.type	main, @function
main:
.LFB38:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	cmpl	$3, %edi
	jne	.L2
	movq	%rsi, %rbp
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movq	%rax, %rbx
	movq	16(%rbp), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movq	%rax, %rbp
	movl	%eax, %esi
	movl	%ebx, %edi
	call	lt
	movl	%eax, %r8d
	movl	%ebp, %ecx
	movl	%ebx, %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	%ebp, %esi
	movl	%ebx, %edi
	call	plus
	movl	%eax, %r8d
	movl	%ebp, %ecx
	movl	%ebx, %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	%ebp, %esi
	movl	%ebx, %edi
	call	minus
	movl	%eax, %r8d
	movl	%ebp, %ecx
	movl	%ebx, %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	%ebp, %esi
	movl	%ebx, %edi
	call	mul
	movl	%eax, %r8d
	movl	%ebp, %ecx
	movl	%ebx, %edx
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %eax
	jmp	.L3
.L2:
	movl	$.LC4, %edi
	call	puts
	movl	$1, %eax
.L3:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE38:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
