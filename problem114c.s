	.global mygetpid
	.section ".text"
	.align 2
mygetpid:
	# 関数プロローグ
	mflr %r0
	std %r0, 16(%r1)
	stdu %r1, -32(%r1)

	# システムコール番号 __NR_getpid 20
	li %r0, 20
	sc

	# 関数エピローグ
	addi %r1, %r1, 32
	ld %r0, 16(%r1)
	mtlr %r0
	blr
