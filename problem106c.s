	.global mystrlen
mystrlen:
	# 答えとして使う変数
	li %r5, 0
loop:
	# 1バイト読み込む
	lbz %r4, 0(%r3)
	# 終端文字に出会ったら終了
	cmpdi %r4, 0
	beq ret
	# 1文字あったのでカウントを増やす
	addi %r5, %r5, 1
	# 文字の場所も一文字進める
	addi %r3, %r3, 1
	b loop
ret:
	# 答えを返り値へと移動
	mr %r3, %r5
	blr
