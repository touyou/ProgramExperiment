	.section ".rodata"
	.align 3
	# 定数0.0と1.0
fzero:
	.double 0.0
	.align 3
fone:
	.double 1.0
	.section ".text"
	.align 2
	.global saturate
saturate:
	# 0.0を読み出す
	addis %r3, %r2, fzero@toc@ha
	addi %r3, %r3, fzero@toc@l
	# %f2に0.0を、%f3に1.0を入れる
	lfd %f2, 0(%r3)
	# 1.0を読み出す
	addis %r3, %r2, fone@toc@ha
	addi %r3, %r3, fone@toc@l
	lfd %f3, 0(%r3)
	# 0.0以下なら0.0を返す(NaNを除外するために二回にわける)
	fcmpu %cr0, %f1, %f2
	blt ret_zero
	beq ret_zero
	# 1.0より大きいなら1.0を返す
	fcmpu %cr0, %f1, %f3
	bgt ret_one
	# 0.0以上1.0以下もしくはNaNならそのまま
	blr
ret_zero:
	fmr %f1, %f2
	blr
ret_one:
	fmr %f1, %f3
	blr

