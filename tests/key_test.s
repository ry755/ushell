.include "syscall.inc"

.global main
main:
    ldi r16, SYS_BeginFrameDraw
    call 0xEF00

    ldi r16, SYS_GetKey
    call 0xEF00
    clr r25
    cpi r24, 0
    breq done
    clr r23
    ldi r22, 1
    clr r21
    ldi r20, 1
    ldi r16, SYS_BlitChar
    call 0xEF00
done:
    ldi r16, SYS_EndFrameDraw
    call 0xEF00
    rjmp main
