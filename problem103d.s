	.global maxof2
maxof2:
	# x<=yならans_yに分岐
	cmpw %r3, %r4
	ble ans_y
	# そうでなければxが答え
	blr
ans_y:
	# xの入っていたところにyを入れればそれが返り値になる
	mr %r3, %r4
	blr
