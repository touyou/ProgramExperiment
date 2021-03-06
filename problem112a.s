	.section ".rodata"
	.align 3
	# 返す初期値
fzero:
	.double 0.0
	.section ".text"
	.global dot
	.align 2
dot:
	# %r3にはnが入っているこれが0になるまでループする
	# まずは%f1に初期値をセット
	addis %r6, %r2, fzero@toc@ha
	addi %r6, %r6, fzero@toc@l
	lfd %f1, 0(%r6)
loop:
	# nが0ならば今の値を返す
	cmpwi %r3, 0
	beq ret
	# %f2と%f3に一つ目の値をロードする
	lfd %f2, 0(%r4)
	lfd %f3, 0(%r5)
	# 8バイト分アドレスを進めておく
	addi %r4, %r4, 8
	addi %r5, %r5, 8
	# 掛け算
	fmul %f2, %f2, %f3
	# 掛けたものを返り値に足す
	fadd %f1, %f1, %f2
	# %r3を一つ減らす
	subi %r3, %r3, 1
	b loop
ret:
	blr
