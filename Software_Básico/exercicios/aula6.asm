section .data
	A dq 10
	B dq 5
section .text
global _start

_soma:
	push rbp
	mov rbp, rsp
	mov rax, [A]
	add rax, [B]
	pop rbp
	ret
_subtrai:
	push rbp
	mov rbp, rsp
	mov rax, [A]
	sub rax, [B]
	pop rbp
	ret
_start:
	call _soma
	mov [A], rax
	call _subtrai
	mov [B], rax
	call _soma
	mov rdi, rax
	mov rax, 60
	syscall
