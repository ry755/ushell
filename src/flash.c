#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>
#include <string.h>

#include "sd.h"
#include "flash.h"

u8 page_buffer[256];

u8 uS_FlashPage(u8 *source, u8 target_page) {
    if (target_page >= 0xF0) return 0;

    asm volatile (
        "cli"           "\n\t"
        "movw r24, %0"  "\n\t"
        "mov r22, %1"   "\n\t"
        "call 0xFF8C"   "\n\t" // call Prog_Page (must use patched bootloader!!)
        "sei"           "\n" ::
        "e" (source),
        "r" (target_page) :
        "r0", "r1", "r24", "r25", "r26", "r27", "r30", "r31"
    );

    // TODO: get the actual return value from Prog_Page
    return 1;
}

void uS_FlashFile(sd_file_t *file, u8 starting_target_page) {
    u8 target_page = starting_target_page;
    u16 offset = 0;
    memset(&page_buffer[0], 0, 256);
    while (uS_SDReadFile(file, 256, offset, &page_buffer[0]) != 0) {
        uS_FlashPage(&page_buffer[0], target_page++);
        offset += 256;
        memset(&page_buffer[0], 0, 256);
    }
}

// execute an application specified by the path
// returns only if the specified file failed to open
void uS_Exec(char *path) {
    sd_file_t app;
    if (!uS_SDOpenFile(&app, path, SD_READ)) return;
    uS_FlashFile(&app, USER_FLASH_PAGE);
    m74_config |= M74_CFG_ENABLE;
    asm ("jmp 0x8000");
}

bool uS_BootloaderCheck() {
    if (pgm_read_byte(0xFF8C) != 0xDC) return false;
    if (pgm_read_byte(0xFF8D) != 0x01) return false;
    return true;
}
