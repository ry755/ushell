.include "syscall.inc"

.global main
main:
    ldi r16, SYS_BeginFrameDraw
    call 0xEF00

    clr r3 ; Y counter
    clr r4 ; character
y_loop:
    clr r2 ; X counter
x_loop:
    clr r25
    mov r24, r4
    ldi r16, 8
    mul r2, r16
    movw r22, r0
    mul r3, r16
    movw r20, r0
    ldi r16, SYS_BlitChar
    call 0xEF00

    inc r4
    breq done
    inc r2
    ldi r16, 48
    cp r2, r16
    brne x_loop
    inc r3
    ldi r16, 27
    cp r3, r16
    brne y_loop

loop:
    ldi r16, SYS_BeginFrameDraw
    call 0xEF00
done:
    ldi r16, SYS_EndFrameDraw
    call 0xEF00
    rjmp loop
