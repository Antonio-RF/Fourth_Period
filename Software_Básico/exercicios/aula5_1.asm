section .data
v dq 10, 20, 30, 40, 50

section .text
	global _start
_start:
	mov rdi, [v+8]
	mov rax, 60
	syscall
