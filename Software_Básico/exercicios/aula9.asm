section .data
	v dq 1,2,3,4,5
	tam dq 5
section .text
global _start
_soma:
	push rbp
	mov rbp, rsp

	mov rbx, rdi
	mov rcx, rsi

	mov rdx, 0
	mov rax, 0
	_for:
		cmp rax, rcx
		je _forafor
		add rdx, [rbx + 8*rax]
		add rax, 1
		jmp _for
	_forafor:
		mov rax, rdx
		pop rbp
		ret
_start:
	mov rdi, v
	mov rsi, [tam]
	call _soma
	mov rdi, rax
	mov rax, 60
	syscall
