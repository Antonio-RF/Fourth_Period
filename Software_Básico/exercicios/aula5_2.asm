section .data
 i dq 0
 m dq 0
 v dq 10, 30, 5, 10, 50

section .text
global _start
_start:
  mov rax, [i]
  mov rdi, [m]

_loop_i:
  cmp rax, 5
  je _loop_e
  cmp [v + rax*8], rdi
  jle _if_e
  mov rdi, [v + rax*8]
_if_e:
  add rax, 1
  jmp _loop_i

_loop_e:
  mov rax, 60
  syscall
