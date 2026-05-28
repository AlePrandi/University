binsearch:
    bge a2, a1, else
    li a0, -1
    jr ra
    else:
    addi sp,sp, -4
    sw ra, 0(sp)
    
    add t0, a1, a2 #middle
    srai t0, t0, 1
    slli t1, t0, 2
    add t2, a0, t1
    lw t2, 0(t2)
    bne t2, a3, else1
    mv a0, t0
    j fine
    else1:
    bge a3, t2, else2
    addi a2, t0, -1
    jal binsearch
    j fine
    else2:
    addi a1, t0, 1
    jal binsearch
    fine:
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra