section .data
	A dq 1
	B dq 10
section .text
	global _start

_start:
	mov rdi, [A]
	mov rax, [B]
	cmp rdi, rax
	jl _naoretorno
	mov rdi, 0
	mov rax, 60
	syscall
_naoretorno:
	mov rbx, rdi
_iniciofor:
	cmp rdi, rax
	jg _forafor
	add rbx, rdi
	add rdi, 1
	jmp _iniciofor
_forafor:
	mov rcx, 255
	cmp rcx, rbx
	jg _returncount
	mov rdi, 255
	mov rax, 60
	syscall
_returncount:
	mov rdi, rbx
	mov rax, 60
	syscall
