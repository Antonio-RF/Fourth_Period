section .data
    msg db "Hello, world!", 0xA
    len equ $ - msg

section .text
    global _start

_start:
    mov rax, 1        ; syscall: write
    mov rdi, 1        ; stdout
    mov rsi, msg      ; endereço da string
    mov rdx, len      ; tamanho
    syscall

    mov rax, 60       ; syscall: exit
    xor rdi, rdi      ; código de saída = 0
    syscall

