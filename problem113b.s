	.global ntimes
	# int ntimes(int n, int (*f)(int), int x)
ntimes:
	# 非揮発性レジスタを退避
	std %r31, -8(%r1)
	std %r30, -16(%r1)
	std %r29, -24(%r1)
	# n, f, xは非揮発性レジスタで管理する
	mr %r29, %r3
	mr %r30, %r4
	mr %r31, %r5
	# lrの退避とスタックフレームの管理
	mflr %r0
	std %r0, 16(%r1)
	stdu %r1, -48(%r1)
loop:
	cmpdi %r29, 0
	ble loop_end
	# %r3に現在のxの値を
	mr %r3, %r31
	# fを実行
	mtctr %r30
	bctrl
	# 返り値をxに保存
	mr %r31, %r3
	addi %r29, %r29, -1
	b loop
loop_end:
	# 戻り値はxの値
	mr %r3, %r31
	# スタックと非揮発性レジスタの復帰
	addi %r1, %r1, 48
	ld %r0, 16(%r1)
	mtlr %r0
	ld %r29, -24(%r1)
	ld %r30, -16(%r1)
	ld %r31, -8(%r1)
	blr
