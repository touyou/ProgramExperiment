	.globl mystrcmp
mystrcmp:
	# 1バイト読み込む
	lbz %r5, 0(%r3)
	lbz %r6, 0(%r4)
	# %r5 != %r6 のとき、 return_ne へ
	cmpd %r5, %r6
	bne return_ne
	# %r5 == %r6 == 0 のとき、 return_eq へ
	cmpdi %r5, 0
	beq return_eq
	# %r5 == %r6 != 0 のとき、処理続行
	addi %r3, %r3, 1
	addi %r4, %r4, 1
	b mystrcmp
return_ne:
	ble return_le
	li %r3, 1
	blr
return_le:
	li %r3, -1
	blr
return_eq:
	li %r3, 0
	blr
