        ldr r1, =m
        ldr r1, [r1]
        ldr r2, =n
        ldr r2, [r2]
        mov r3, #0

loop:   cmp r1, r2
        blt exit
        sub r1, r1, r2
        add r3, r3, #1
        bal loop

exit:   ldr r2, =quot
        str r3, [r2]
        ldr r2, =rem
        str r1, [r2]
        swi 0x11

m:      .word       20
n:      .word       3
rem:    .word
quot:   .word
