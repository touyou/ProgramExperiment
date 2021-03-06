	.global fib
	.align 2
fib:
	# n == 0なら0を返す
	cmpdi %r3, 0
	beq ret_zero
	# n == 1なら1を返す
	cmpdi %r3, 1
	beq ret_one
	# それ以外の場合はスタックフレームを作って再帰呼び出し
	# ローカル変数に今の値を確保するので48byte用意
	mflr %r0
	std %r0, 16(%r1)
	stdu %r1, -48(%r1)
	# まずはnの内容を退避
	stw %r3, 32(%r1)
	# n-1にする
	subi %r3, %r3, 1
	bl fib
	# この時点で%r3にfib(n-1)の結果が入る
	# これを別の場所に退避する
	stw %r3, 36(%r1)
	# %r3にはnをロードする
	lwa %r3, 32(%r1)
	# n-2にする
	subi %r3, %r3, 2
	bl fib
	# %r3にfib(n-2)の結果が入っているのでその内容を足す
	lwa %r4, 36(%r1)
	add %r3, %r3, %r4
	# 復帰
	addi %r1, %r1, 48
	ld %r0, 16(%r1)
	mtlr %r0
	blr
ret_zero:
	li %r3, 0
	blr
ret_one:
	li %r3, 1
	blr
