.include "syscall.inc"

.global main
main:
    ldi r16, SYS_BeginFrameDraw
    call 0xEF00

    ldi r25, hi8(string)
    ldi r24, lo8(string)
    clr r23
    clr r22
    clr r21
    clr r20
    ldi r16, SYS_BlitStr
    call 0xEF00

loop:
    ; get left mouse button
    ldi r16, SYS_GetMouseButtons
    call 0xEF00
    andi r25, 2
    cpi r25, 2
    brne done

    ; get the mouse X position and save it in r3:r2
    ldi r16, SYS_GetMouseX
    call 0xEF00
    movw r2, r24

    ; get the mouse Y position
    ldi r16, SYS_GetMouseY
    call 0xEF00

    movw r18, r24
    movw r20, r2
    ldi r24, lo8(block)
    ldi r25, hi8(block)
    movw r22, r24
    ldi r16, SYS_Blit
    call 0xEF00
done:
    ldi r16, SYS_WaitFrame
    call 0xEF00
    rjmp loop

string: .asciz "paint!!"

block:
    .byte 0b11110000
    .byte 0b11110000
    .byte 0b11110000
    .byte 0b11110000
    .byte 0b00000000
    .byte 0b00000000
    .byte 0b00000000
    .byte 0b00000000
