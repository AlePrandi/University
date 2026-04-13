#primo es
sub t0,t0,t1
bge t0,zero, end1
mv t0, zero
end1:
li t2, -1
sub t1,t1, t2


#secondo es
li t2, 2
sub t0, t0, t2
add t0, t0, t1
bge t0,t1, else2
addi t0,t0,1
#beq zero,zero, end2
j end2 # J usato per salto incondizionato
else2:
addi t1,t1,1
end2: