section .data
	A dq 6
	B dq 4
	C dq 8
section .text
global _start
_bhaskara:
	push rbp
	mov rbp, rsp
	sub rsp, 8
	mov rax, [B]
	mov rbx, [B]
	mul rbx
	mov [rbp-8], rax
	mov rax, [A]
	mov rcx, [C]
	mul rcx
	mov rcx, 4
	mul rcx
	mov rdx, [rbp-8]
	sub rdx, rax
	mov [rbp-8], rdx
	cmp qword [rbp-8], 0
	jl _return0
	mov rax, 1
	add rsp, 8
	pop rbp
	ret
	_return0:
		mov rax, 0
		add rsp, 8
		pop rbp
		ret
_start:
	call _bhaskara
	mov rdi, rax
	mov rax, 60
	syscall
