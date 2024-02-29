#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>
#include <spiram.h>
#include <bootlib.h>

#include "sd.h"
#include "flash.h"

u8 uS_FlashPage(u8 *source, u8 target_page) {
    asm volatile(
        "mov r24, %A0" "\n\t"
        "mov r25, %B0" "\n\t"
        "mov r22, %1"  "\n\t"
        "call 0xFFAA"  "\n" :: // call Prog_Page
        "e" (source),
        "r" (target_page) :
        "r0", "r1", "r24", "r25", "r26", "r27", "r30", "r31"
    );
    // TODO: get the actual return value from Prog_Page
    return 1;
}

void uS_FlashFile(sd_file_t *file, u8 starting_target_page, u8 ending_target_page) {
    u32 sector = 0;
    for (u8 target_page = starting_target_page; target_page < ending_target_page;) {
        u8 *buf = (u8 *)uS_SDReadFileSector(file, sector++);
        uS_FlashPage(&buf[0], target_page++);
        uS_FlashPage(&buf[256], target_page++);
    }
}
