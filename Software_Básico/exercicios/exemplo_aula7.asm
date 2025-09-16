section .data
  a dq 10
  b dq 20

section .text
global _start

_troca_var:
    push rbp
    mov rbp, rsp
    sub rsp, 4             ; variável local (sentinela)

    mov rax, [rbp+8]      ; pega endereço de x
    mov rbx, [rax]         ; carrega *x
    mov [rbp-4], rbx       ; sentinela = *x

    mov rax, [rbp+8]      ; endereço de x
    mov rbx, [rbp+12]      ; endereço de y
    mov rcx, [rbx]         ; rcx = *y
    mov [rax], rcx         ; *x = *y

    mov rax, [rbp+12]      ; endereço de y
    mov rcx, [rbp-4]       ; sentinela
    mov [rax], rcx         ; *y = sentinela

    add rsp, 4
    pop rbp
    ret

_start:
    lea rax, [a]           ; endereço de a
    push rax
    lea rax, [b]           ; endereço de b
    push rax
    call _troca_var
    add rsp, 16            ; limpa parâmetros da pilha

    mov rax, [a]
    sub rax, [b]           ; retorna (a - b)
    mov rdi, rax
    mov rax, 60
    syscall

