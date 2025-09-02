## Resolução:;
Para a resolução desse trabalho eu observei a função Main, que chama funções de leituras, escrita e a função Validate(). Com isso, fui ver o que continha na função Validate() e consegui concluir que ela chama 3 funções, as quais eu já considerei que provavelmente iriam tratar da minha senha, são elas: Dec(), Sub() e Check(). Ao estudar as três funções, eu consegui observar que a função Dec() usa e modifica o ***input0***, algo que não importa, pois as outras duas funções (principalmente a Check()) usam somente o ***input1*** como parâmetro de comparação. Com isso, na função Sub() eu consegui ver que ele estava pegando cada byte do ***input1***, isso é, cada caracter do ***input1*** e somando certos valores. Depois, eu observei que, antes dele chamar a função Check(), ele coloca em edi o valor de 0x77, que seria ***"w"***. Nesse contexto, dentro da última função (Check()) ele compara os novos valores de ***input1*** (que é a senha que você digitou modificada na função Sub()) com o valor de ***"w"***. Então, eu observei que deveria fazer a conta do valor de "w" na tabela ascii menos os valores somados na função Sub(), o que resulta na frase "caiunobait?".

## Código Assembly usado para a resolução:

#----------------------------------------------------------------------#
00000000000012bd <main>:
    12bd:	55                   	push   %rbp
    12be:	48 89 e5             	mov    %rsp,%rbp
    12c1:	48 8d 05 3c 0d 00 00 	lea    0xd3c(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    12c8:	48 89 c7             	mov    %rax,%rdi
    12cb:	b8 00 00 00 00       	mov    $0x0,%eax
    12d0:	e8 6b fd ff ff       	call   1040 <printf@plt>	(FUNÇÃO DE PRINTF PEDINDO A SENHA).
    12d5:	bf 00 00 00 00       	mov    $0x0,%edi
    12da:	e8 81 fd ff ff       	call   1060 <fflush@plt>	(FUNÇÃO QUE FAZ O BUFFER DE SAÍDA A IMPRIMIR A MSG NA TELA ANTES DE LER A SENHA).
    12df:	48 8d 05 52 2d 00 00 	lea    0x2d52(%rip),%rax        # 4038 <input1>
    12e6:	ba 0b 00 00 00       	mov    $0xb,%edx
    12eb:	48 89 c6             	mov    %rax,%rsi
    12ee:	bf 00 00 00 00       	mov    $0x0,%edi
    12f3:	e8 58 fd ff ff       	call   1050 <read@plt>		(FUNÇÃO QUE LÊ A SENHA).
    12f8:	e8 a6 ff ff ff       	call   12a3 <validate>		(FUNÇÃO VALIDATE()).
    12fd:	85 c0                	test   %eax,%eax
    12ff:	74 11                	je     1312 <main+0x55>
    1301:	48 8d 05 07 0d 00 00 	lea    0xd07(%rip),%rax        # 200f <_IO_stdin_used+0xf>
    1308:	48 89 c7             	mov    %rax,%rdi
    130b:	e8 20 fd ff ff       	call   1030 <puts@plt>		(FUNÇÃO DE PRINT QUE FALA QUE DEU ERRADO).
    1310:	eb 0f                	jmp    1321 <main+0x64>
    1312:	48 8d 05 05 0d 00 00 	lea    0xd05(%rip),%rax        # 201e <_IO_stdin_used+0x1e>
    1319:	48 89 c7             	mov    %rax,%rdi
    131c:	e8 0f fd ff ff       	call   1030 <puts@plt>		(FUNÇÃO DE PRINT QUE DEU CERTO).
    1321:	b8 00 00 00 00       	mov    $0x0,%eax
    1326:	5d                   	pop    %rbp
    1327:	c3                   	ret
#----------------------------------------------------------------------#
00000000000012a3 <validate>:
    12a3:|--55                   |--push   %rbp
    12a4:|--48 89 e5             |--mov    %rsp,%rbp
    12a7:|--e8 bd fe ff ff       |--call   1169 <dec>	(CHAMANDO FUNÇÃO DEC()).
    12ac:|--e8 fb fe ff ff       |--call   11ac <sub>	(CHAMANDO FUNÇÃO SUB()).
    12b1:|--bf 77 00 00 00       |--mov    $0x77,%edi	(COLOCANDO "W" EM EDI).
    12b6:|--e8 a8 ff ff ff       |--call   1263 <check>	(CHAMANDO FUNÇÃO CHECK()).
    12bb:|--5d                   |--pop    %rbp
    12bc:|--c3                   |--ret
#----------------------------------------------------------------------#
0000000000001169 <dec>:
    1169:	55                   	push   %rbp
    116a:	48 89 e5             	mov    %rsp,%rbp
    116d:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    1174:	eb 2c                	jmp    11a2 <dec+0x39>
    1176:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1179:	48 98                	cltq
    117b:	48 8d 15 c6 2e 00 00 	lea    0x2ec6(%rip),%rdx        # 4048 <input0>
    1182:	0f b6 04 10          	movzbl (%rax,%rdx,1),%eax
    1186:	89 c2                	mov    %eax,%edx
    1188:	8b 45 d8             	mov    -0x28(%rbp),%eax
    118b:	01 d0                	add    %edx,%eax
    118d:	89 c1                	mov    %eax,%ecx
    118f:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1192:	48 98                	cltq
    1194:	48 8d 15 ad 2e 00 00 	lea    0x2ead(%rip),%rdx        # 4048 <input0>
    119b:	88 0c 10             	mov    %cl,(%rax,%rdx,1)
    119e:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    11a2:	83 7d fc 0a          	cmpl   $0xa,-0x4(%rbp)
    11a6:	7e ce                	jle    1176 <dec+0xd>
    11a8:	90                   	nop
    11a9:	90                   	nop
    11aa:	5d                   	pop    %rbp
    11ab:	c3                   	ret
#----------------------------------------------------------------------#
00000000000011ac <sub>:
    11ac:	55                   	push   %rbp
    11ad:	48 89 e5             	mov    %rsp,%rbp
    11b0:	0f b6 05 81 2e 00 00 	movzbl 0x2e81(%rip),%eax        # 4038 <input1>	(EAX = INPUT1[0])
    11b7:	83 c0 14             	add    $0x14,%eax								(EAX += 20)
    11ba:	88 05 78 2e 00 00    	mov    %al,0x2e78(%rip)        # 4038 <input1>	(INPUT1[0] = AL(PRIMEIROS 8 BITS DE EAX))
    11c0:	0f b6 05 72 2e 00 00 	movzbl 0x2e72(%rip),%eax        # 4039 <input1+0x1>	(EAX = INPUT1[1])
    11c7:	83 c0 16             	add    $0x16,%eax									(EAX += 22)
    11ca:	88 05 69 2e 00 00    	mov    %al,0x2e69(%rip)        # 4039 <input1+0x1>	(INPUT1[1] = AL(PRIMEIROS 8 BITS DE EAX))
    11d0:	0f b6 05 63 2e 00 00 	movzbl 0x2e63(%rip),%eax        # 403a <input1+0x2>	(EAX = INPUT1[2])
    11d7:	83 c0 0e             	add    $0xe,%eax1									(EAX += 14)
    11da:	88 05 5a 2e 00 00    	mov    %al,0x2e5a(%rip)        # 403a <input1+0x2>	(INPUT1[2] = AL(PRIMEIROS 8 BITS DE EAX))
    11e0:	0f b6 05 54 2e 00 00 	movzbl 0x2e54(%rip),%eax        # 403b <input1+0x3>	(EAX = INPUT1[3])
    11e7:	83 c0 02             	add    $0x2,%eax									(EAX += 2)
    11ea:	88 05 4b 2e 00 00    	mov    %al,0x2e4b(%rip)        # 403b <input1+0x3>	(INPUT1[3] = AL(PRIMEIROS 8 BITS DE EAX))
    11f0:	0f b6 05 45 2e 00 00 	movzbl 0x2e45(%rip),%eax        # 403c <input1+0x4> (EAX = INPUT1[4])
    11f7:	83 c0 09             	add    $0x9,%eax									(EAX += 9)
    11fa:	88 05 3c 2e 00 00    	mov    %al,0x2e3c(%rip)        # 403c <input1+0x4>	(INPUT1[4] = AL(PRIMEIROS 8 BITS DE EAX))
    1200:	0f b6 05 36 2e 00 00 	movzbl 0x2e36(%rip),%eax        # 403d <input1+0x5>	(EAX = INPUT1[5])
    1207:	83 c0 08             	add    $0x8,%eax									(EAX += 8)
    120a:	88 05 2d 2e 00 00    	mov    %al,0x2e2d(%rip)        # 403d <input1+0x5>	(INPUT1[5] = AL(PRIMEIROS 8 BITS DE EAX))
    1210:	0f b6 05 28 2e 00 00 	movzbl 0x2e28(%rip),%eax        # 403f <input1+0x7>	(EAX = INPUT1[7])
    1217:	83 c0 16             	add    $0x16,%eax									(EAX += 22)
    121a:	88 05 1f 2e 00 00    	mov    %al,0x2e1f(%rip)        # 403f <input1+0x7>	(INPUT1[7] = AL(PRIMEIROS 8 BITS DE EAX))
    1220:	0f b6 05 17 2e 00 00 	movzbl 0x2e17(%rip),%eax        # 403e <input1+0x6>	(EAX = INPUT1[6])
    1227:	83 c0 15             	add    $0x15,%eax									(EAX += 21)
    122a:	88 05 0e 2e 00 00    	mov    %al,0x2e0e(%rip)        # 403e <input1+0x6>	(INPUT1[6] = AL(PRIMEIROS 8 BITS DE EAX))
    1230:	0f b6 05 09 2e 00 00 	movzbl 0x2e09(%rip),%eax        # 4040 <input1+0x8>	(EAX = INPUT1[8])
    1237:	83 c0 0e             	add    $0xe,%eax									(EAX += 10)
    123a:	88 05 00 2e 00 00    	mov    %al,0x2e00(%rip)        # 4040 <input1+0x8>	(INPUT1[8] = AL(PRIMEIROS 8 BITS DE EAX))
    1240:	0f b6 05 fa 2d 00 00 	movzbl 0x2dfa(%rip),%eax        # 4041 <input1+0x9>	(EAX = INPUT1[9])
    1247:	83 c0 03             	add    $0x3,%eax									(EAX += 3)
    124a:	88 05 f1 2d 00 00    	mov    %al,0x2df1(%rip)        # 4041 <input1+0x9>	(INPUT1[9] = AL(PRIMEIROS 8 BITS DE EAX))
    1250:	0f b6 05 eb 2d 00 00 	movzbl 0x2deb(%rip),%eax        # 4042 <input1+0xa>	(EAX = INPUT1[10])
    1257:	83 c0 38             	add    $0x38,%eax									(EAX += 56)
    125a:	88 05 e2 2d 00 00    	mov    %al,0x2de2(%rip)        # 4042 <input1+0xa>	(INPUT1[10] = AL(PRIMEIROS 8 BITS DE EAX))
    1260:	90                   	nop													(INSTRUÇÃO NOP)
    1261:	5d                   	pop    %rbp											(ENCERRAMENTO DE FUNÇÃO)
    1262:	c3                   	ret													(ENCERRAMENTO DE FUNÇÃO)
#----------------------------------------------------------------------#
0000000000001263 <check>:
    1263:	55                   	push   %rbp											(COMEÇO DE FUNÇÃO: SALVANDO POSIÇÃO NA PILHA)
    1264:	48 89 e5             	mov    %rsp,%rbp									(COMEÇO DE FUNÇÃO: SALVANDO POSIÇÃO NA PILHA)
    1267:	89 7d ec             	mov    %edi,-0x14(%rbp)								
    126a:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    1271:	eb 23                	jmp    1296 <check+0x33>
    1273:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1276:	48 98                	cltq
    1278:	48 8d 15 b9 2d 00 00 	lea    0x2db9(%rip),%rdx        # 4038 <input1>
    127f:	0f b6 04 10          	movzbl (%rax,%rdx,1),%eax
    1283:	0f be c0             	movsbl %al,%eax
    1286:	39 45 ec             	cmp    %eax,-0x14(%rbp)
    1289:	74 07                	je     1292 <check+0x2f>
    128b:	b8 00 00 00 00       	mov    $0x0,%eax
    1290:	eb 0f                	jmp    12a1 <check+0x3e>
    1292:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    1296:	83 7d fc 0a          	cmpl   $0xa,-0x4(%rbp)
    129a:	7e d7                	jle    1273 <check+0x10>
    129c:	b8 01 00 00 00       	mov    $0x1,%eax
    12a1:	5d                   	pop    %rbp
    12a2:	c3                   	ret
#----------------------------------------------------------------------#
