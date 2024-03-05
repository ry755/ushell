#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>
#include <string.h>

#include "flash.h"
#include "syscall.h"
#include "video.h"

extern u8 page_buffer[256];
extern u8 keyboard_buffer;
extern u8 keyboard_mod_buffer;
extern u16 cursor_x;
extern u16 cursor_y;
extern u16 mouse_buttons;

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
        case SYS_Blit: {
            u8 bitmap[8];
            u8 mask[8];
            for (u8 i = 0; i < 8; i++) bitmap[i] = pgm_read_byte(u16_0 + i);
            for (u8 i = 0; i < 8; i++) mask[i] = pgm_read_byte(u16_1 + i);
            uS_Blit(bitmap, mask, u16_2, u16_3);
            return 0;
        }
        case SYS_BlitRam:
            uS_Blit((u8 *)u16_0, (u8 *)u16_1, u16_2, u16_3);
            return 0;
        case SYS_BlitChar:
            uS_BlitChar((unsigned char)u16_0, u16_1, u16_2);
            return 0;
        case SYS_BlitStr:
            uS_BlitStr((char *)u16_0, u16_1, u16_2);
            return 0;
        case SYS_BlitStrRam:
            uS_BlitStrRam((char *)u16_0, u16_1, u16_2);
            return 0;
        case SYS_GetKey:
            return (keyboard_mod_buffer << 8) | keyboard_buffer;
        case SYS_GetMouseButtons:
            return mouse_buttons;
        case SYS_GetMouseX:
            return cursor_x;
        case SYS_GetMouseY:
            return cursor_y;
        case SYS_Open:
            return uS_SDOpenFile((sd_file_t *)u16_0, (char *)u16_1, (u8)u16_2);
        case SYS_Close:
            return uS_SDCloseFile((sd_file_t *)u16_0);
        case SYS_OpenDir:
            return uS_SDOpenDir((sd_dir_t *)u16_0, (char *)u16_1);
        case SYS_Read:
            return uS_SDReadFile((sd_file_t *)u16_0, u16_1, u16_2, (u8 *)u16_3);
        case SYS_ReadDir:
            return uS_SDReadDir((sd_dir_t *)u16_0, (sd_file_info_t *)u16_1);

        default:
            return 0;
    }
}

// install a `jmp uS_Syscall` trampoline opcode to 0xEF00
void uS_SyscallTrampolineInstall() {
    memset(&page_buffer[0], 0, 256);
    page_buffer[0] = 0x0C;
    page_buffer[1] = 0x94;
    page_buffer[2] = (u16)uS_Syscall & 0xFF;
    page_buffer[3] = (u16)uS_Syscall >> 8;
    uS_FlashPage(&page_buffer[0], 0xEF);
}
