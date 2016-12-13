	.global prime_factor
prime_factor:
	# 2から順に割っていく
	# 最初に一旦引数を避難する
	mr %r4, %r3
	# %r3をループ変数にする（ループを抜けた時に同時に返り値にもなる）
	li %r3, 2
loop:
	# %r4を%r3で割り切れるならそれが答え
	divw %r5, %r4, %r3
	mullw %r5, %r5, %r3
	cmpw %r5, %r4
	beq ret
	# %r3を1増やしてloopのところに戻る
	addi %r3, %r3, 1
	b loop
ret:
	# この時点で%r3が答えになっているからそのままreturn
	blr

