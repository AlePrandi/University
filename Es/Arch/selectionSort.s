selection_sort:
    li t0, 1
    bge a1, t0, elseSort
    jr ra
    elseSort:
    addi sp, sp, -16
    sw ra, 0(sp)
    sw s1, 4(sp) #array
    sw s2, 8(sp) #size
    sw s3, 12(sp) #min_indx

    mv s1, a0
    mv s2, a1
    
    jal minarray
    mv s3, a0 #min_indx
    mv a0, s1
    li a1, 0
    mv a2, s3
    jal swap
    li t0, 1
    slli t0,t0, 2 
    add a0, s1, t0
    addi a1, s2, -1
    jal selection_sort
    lw ra, 0(sp)
    lw s1, 4(sp)
    lw s2, 8(sp)
    lw s3, 12(sp)
    addi sp, sp, 16
    jr ra


swap:
    mv t1, a1
    add t2, t1, a0
    lw t0, 0(t2)
    mv t1, a2
    add t3, t1, a0
    lw t4, 0(t3)
    sw t4, 0(t2)
    sw t0, 0(t3)
    jr ra
    
minarray:
    li t0, 0 #min_idx
    lw t1, 0(a0) #min_val
    li t2, 0 #i
    while:
    bge t2, a1, end
    slli t3, t2, 2
    add t4, a0, t3
    lw t5, 0(t4)
    bge t5, t1, else
    mv t0, t2
    mv t1, t5
    else:
    addi t2,t2,1
    j while
    end:
    mv a0,t0
    jr ra