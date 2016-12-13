
problem102c:     file format elf64-powerpcle


Disassembly of section .text:

0000000000000000 <f>:
   0:	00 00 4c 3c 	addis   r2,r12,0
   4:	00 00 42 38 	addi    r2,r2,0
   8:	a6 02 08 7c 	mflr    r0
   c:	10 00 01 f8 	std     r0,16(r1)
  10:	f8 ff e1 fb 	std     r31,-8(r1)
  14:	d1 ff 21 f8 	stdu    r1,-48(r1)
  18:	78 0b 3f 7c 	mr      r31,r1
  1c:	00 00 42 3d 	addis   r10,r2,0
  20:	00 00 2a e9 	ld      r9,0(r10)
  24:	00 00 29 e9 	ld      r9,0(r9)
  28:	78 4b 26 7d 	mr      r6,r9
  2c:	0d 00 a0 38 	li      r5,13
  30:	01 00 80 38 	li      r4,1
  34:	00 00 62 3c 	addis   r3,r2,0
  38:	00 00 63 38 	addi    r3,r3,0
  3c:	01 00 00 48 	bl      3c <f+0x3c>
  40:	00 00 00 60 	nop
  44:	00 00 42 3d 	addis   r10,r2,0
  48:	00 00 2a e9 	ld      r9,0(r10)
  4c:	00 00 29 e9 	ld      r9,0(r9)
  50:	78 4b 23 7d 	mr      r3,r9
  54:	01 00 00 48 	bl      54 <f+0x54>
  58:	00 00 00 60 	nop
  5c:	00 00 00 60 	nop
  60:	30 00 3f 38 	addi    r1,r31,48
  64:	10 00 01 e8 	ld      r0,16(r1)
  68:	a6 03 08 7c 	mtlr    r0
  6c:	f8 ff e1 eb 	ld      r31,-8(r1)
  70:	20 00 80 4e 	blr
  74:	00 00 00 00 	.long 0x0
  78:	00 00 00 01 	.long 0x1000000
  7c:	80 01 00 01 	.long 0x1000180
