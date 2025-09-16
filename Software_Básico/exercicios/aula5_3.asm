section .data
	v dq 1,2,3,4,5,6,7,8,9,10

section .text
global _start
_start:
	mov rbx, 0
	mov rcx, 10
	mov rax, 0
_for:
	cmp rbx, rcx
	je _forafor
	mov rdi, [v + rbx*8]
	and rdi, 1
	cmp rdi, 0
	je _par
	add rbx, 1
	jmp _for
_par:
	add rax, 1
	add rbx, 1
	jmp _for
_forafor:
	mov rdi, rax
	mov rax, 60
	syscall
