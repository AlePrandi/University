.data
.word 0x11223344

.globl _start

.text
_start:

    addi t1,x0,41	#caricamento
    addi t2,x0,43
    addi t3,x0,47

    add t4,t1,t2	#somma
    add t4,t4,t3
    
exit:
    #il contenuto in x17 dice cosa deve
    #fare l'ecall -> 10 vuol dire esci
    addi x17,x0,10
    ecall