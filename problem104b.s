	.global swap_gt
swap_gt:
	# ポインタに入っている値を一旦レジスタに保存
	lwa %r5, 0(%r3)
	lwa %r6, 0(%r4)
	# x <= yが成立していたらskipまで飛ぶ
	cmpw %r5, %r6
	ble skip
	# ポインタの場所に入れ替えて値をセット
	stw %r5, 0(%r4)
	stw %r6, 0(%r3)
skip:
	blr
