    .globl decrement
decrement:
    lwarx %r4, 0, %r3
    addi %r4, %r4, -1
    stwcx. %r4, 0, %r3
    bne- decrement

