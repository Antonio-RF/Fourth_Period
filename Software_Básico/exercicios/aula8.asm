section .data
	pi dq 3
section .text
global _start
_area:
	push rbp
	mov rbp, rsp

	mov rax, rdi
	mul rax
	mov rbx, [pi]
	mul rbx

	pop rbp
	ret

_start:
	mov rdi, 10
	call _area
	mov rdi, rax
	mov rax, 60
	syscall
