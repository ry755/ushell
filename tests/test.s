.global main
main:
    ldi r16, 0 ; uS_BeginFrameDraw
    call 0xEF00

    ldi r25, hi8(string)
    ldi r24, lo8(string)
    ldi r20, 1
    ldi r18, 1
    ldi r16, 2 ; Print
    call 0xEF00

    ldi r16, 1 ; uS_EndFrameDraw
    call 0xEF00

loop:
    ldi r16, 0 ; uS_BeginFrameDraw
    call 0xEF00
    ldi r16, 1 ; uS_EndFrameDraw
    call 0xEF00
    rjmp loop

string: .asciz "hello world from 'userspace'!!"
