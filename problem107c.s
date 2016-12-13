	# int型の変数を用意する
	.section ".data"
	.align 2
variable:
	# 初期値が0
	.long 0
	# こっからfresh関数、セクションを.textに
	.section ".text"
	.global fresh
	.align 2
fresh:
	# まずはvariableの位置を取ってくる
	addis %r4, %r2, variable@toc@ha
	addi %r4, %r4, variable@toc@l
	# 返り値にはその時点での数値を代入
	ld %r3, 0(%r4)
	# 返り値に1足したものを用意
	addi %r5, %r3, 1
	# 次の値として書き込む
	std %r5, 0(%r4)
	blr
