	.global puts_twice
	.section ".text"
	.align 2
puts_twice:
	# 関数プロローグ
	# リンクレジスタの内容を呼び出し元のスタックフレームのLR Save Areaに保存
	mflr %r0
	std %r0, 16(%r1)
	# 受け取った引数をに退避するために
	# 8+4+4+8+8+64=96byteをスタックフレームとして確保する
	stdu %r1, -96(%r1)

	# 2回呼び出したいのでまず受け取った引数を一旦退避
	std %r3, 32(%r1)
	bl puts
	nop
	# 対比していたものを元に戻す
	ld %r3, 32(%r1)
	bl puts
	nop

	# 関数エピローグ
	# スタックサイズが固定なので巻き戻し
	la %r1, 96(%r1)
	ld %r0, 16(%r1)
	mtlr %r0
	blr
