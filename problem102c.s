	.file	"problem102c.c"
	.abiversion 2
	.section	".toc","aw"
	.section	".text"
	.section	.rodata
	.align 3
.LC1:
	.string	"Hello, world!"
	.section	".toc","aw"
.LC0:
	.quad	stderr
	.section	".text"
	.align 2
	.globl f
	.type	f, @function
f:
0:	addis 2,12,.TOC.-0b@ha
	addi 2,2,.TOC.-0b@l
	.localentry	f,.-f
	mflr 0
	std 0,16(1)
	std 31,-8(1)
	stdu 1,-48(1)
	mr 31,1
	addis 10,2,.LC0@toc@ha
	ld 9,.LC0@toc@l(10)
	ld 9,0(9)
	mr 6,9
	li 5,13
	li 4,1
	addis 3,2,.LC1@toc@ha
	addi 3,3,.LC1@toc@l
	bl fwrite
	nop
	addis 10,2,.LC0@toc@ha
	ld 9,.LC0@toc@l(10)
	ld 9,0(9)
	mr 3,9
	bl fflush
	nop
	nop
	addi 1,31,48
	ld 0,16(1)
	mtlr 0
	ld 31,-8(1)
	blr
	.long 0
	.byte 0,0,0,1,128,1,0,1
	.size	f,.-f
	.ident	"GCC: (Ubuntu/IBM 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
