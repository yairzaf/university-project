.entry LENGTH
.extern W




MAIN: mov r3,LENGTH
 bne L3

.extern L3
.entry LOOP

LOOP: jmp L1(#-1,r6)

prn #-5
bne W(r4,r5)
sub r1,r4


L1: inc K

bne LOOP(K,W)

END: stop
STR: .string "abcdef"
LENGTH: .data 6,-9,15
K: .data 22

