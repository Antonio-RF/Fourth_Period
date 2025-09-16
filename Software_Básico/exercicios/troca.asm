section .data
	x dq 8
	y dq 10

section .text
global _start

_troca:
	push rbp
	mov rbp, rsp

	mov rax, [rbp + 16]
	sub rsp, 8
	mov rcx, [rax]
	mov [rbp-8], rcx

	mov rbx, [rbp + 24]
	mov rcx, [rbx]

	mov [rax], rcx

	mov rcx, [rbp - 8]
	mov rbx, [rbp + 24]
	mov [rbx], rcx

	add rsp, 8

	pop rbp
	ret

_start:
	lea rax, [x]
	push rax
	lea rax, [y]
	push rax

	call _troca

	mov rdi, [y]
	mov rax, 60
	syscall
