.include "syscall.inc"

.global main
main:
    ldi r16, SYS_BeginFrameDraw
    call 0xEF00

    ldi r25, hi8(string)
    ldi r24, lo8(string)
    clr r23
    ldi r22, 8
    clr r21
    ldi r20, 8
    ldi r16, SYS_BlitStr
    call 0xEF00

    ldi r16, SYS_EndFrameDraw
    call 0xEF00

loop:
    ldi r16, SYS_BeginFrameDraw
    call 0xEF00
    ldi r16, SYS_EndFrameDraw
    call 0xEF00
    rjmp loop

string: .asciz "hello world from 'userspace'!!"
