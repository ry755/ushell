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

    // this may look overly complicated, and it is.
    // BUT, if we don't move the interrupt vectors then it will crash due to RWW
    // not being enabled by the time a video interrupt comes in. the
    // bootloader re-enables interrupts immediately after executing `spm`, which
    // causes issues for us.
    asm volatile (
        "cli"           "\n\t"
        "ldi r31, 1"    "\n\t" // ldi r31, (1 << ICVE)
        "out 0x35, r31" "\n\t" // out MCUCR, r31
        "ldi r31, 2"    "\n\t" // ldi r31, (1 << IVSEL) ; move vectors to bootloader
        "out 0x35, r31" "\n\t" // out MCUCR, r31
        "movw r24, %0"  "\n\t"
        "mov r22, %1"   "\n\t"
        "call 0xFFAA"   "\n\t" // call Prog_Page
        "ldi r31, 1"    "\n\t" // ldi r31, (1 << ICVE)
        "out 0x35, r31" "\n\t" // out MCUCR, r31
        "ldi r31, 0"    "\n\t" // ldi r31, 0 ; move vectors back to start of flash
        "out 0x35, r31" "\n\t" // out MCUCR, r31
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

bool uS_BootloaderCheck() {
    if (pgm_read_byte(0xFFAA) != 0xDC) return false;
    if (pgm_read_byte(0xFFAB) != 0x01) return false;
    return true;
}
