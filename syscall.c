#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>
#include <bootlib.h>
#include <string.h>

#include "flash.h"
#include "syscall.h"
#include "video.h"

extern u8 sd_buf[512];
extern u8 keyboard_buffer;
extern u8 keyboard_mod_buffer;

u16 uS_Syscall(u16 u16_0, u16 u16_1, u16 u16_2, u16 u16_3, u8 syscall) {
    switch (syscall) {
        case SYS_BeginFrameDraw:
            uS_BeginFrameDraw();
            return 0;
        case SYS_EndFrameDraw:
            uS_EndFrameDraw();
            return 0;
        case SYS_WaitFrame:
            uS_WaitFrame();
            return 0;
        case SYS_Blit:
            uS_Blit((u8 *)u16_0, (u8 *)u16_1, u16_2, u16_3);
            return 0;
        case SYS_BlitChar:
            uS_BlitChar((char)u16_0, u16_1, u16_2);
            return 0;
        case SYS_BlitStr:
            uS_BlitStr((char *)u16_0, u16_1, u16_2);
            return 0;
        case SYS_BlitStrRam:
            uS_BlitStrRam((char *)u16_0, u16_1, u16_2);
            return 0;
        case SYS_GetKey:
            return (keyboard_mod_buffer << 8) | keyboard_buffer;
    }

    return 1;
}

// install a `jmp uS_Syscall` trampoline opcode to 0xEF00
void uS_SyscallTrampolineInstall() {
    // here we are using the sector buffer as temporary storage
    // we can't allocate a 256 byte array on the stack here,
    // and putting it in the global space is a waste of precious ram
    // so, simply use the existing buffer!
    memset(&sd_buf[0], 0, 512);
    sd_buf[0] = 0x0C;
    sd_buf[1] = 0x94;
    sd_buf[2] = (u16)uS_Syscall & 0xFF;
    sd_buf[3] = (u16)uS_Syscall >> 8;
    uS_FlashPage(&sd_buf[0], 0xEF);
}
