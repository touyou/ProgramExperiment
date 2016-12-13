    .globl f
f:
    cmpdi %r3, 0
    beqlr
    li %r5, 0
    mtctr %r3
    mr %r6, %r4
init_loop:
    std %r5, 0(%r6)
    addi %r6, %r6, 8
    addi %r5, %r5, 1
    bdnz init_loop
    li %r5, 2
    li %r6, 16
outer_loop:
    cmpd %r5, %r3
    bge- outer_loop_end
    add %r8, %r4, %r6
    ld %r7, 0(%r8)
    cmpd %r7, %r5
    bne outer_loop_cont
    addi %r9, %r3, -1
    divdu %r9, %r9, %r5
    mtctr %r9
    addi %r10, %r5, -1
inner_loop:
    ld %r7, 0(%r8)
    divwu %r7, %r7, %r5
    mullw %r7, %r7, %r10
    std %r7, 0(%r8)
    add %r8, %r8, %r6
    bdnz inner_loop
outer_loop_cont:
    addi %r5, %r5, 1
    addi %r6, %r6, 8
    b outer_loop
outer_loop_end:
    blr
