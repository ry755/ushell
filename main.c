#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>
#include <spiram.h>
#include <bootlib.h>

#include "flash.h"
#include "sd.h"
#include "syscall.h"
#include "video.h"

int main() {
    bool sd_ok = uS_SDInit();
    uS_VideoInit();
    if (!sd_ok) {
        Print(1, 1, PSTR("No SD Card?"));
        while (true);
    }
    uS_SyscallTrampolineInstall();

    sd_file_name_t file_name = { 'T', 'E', 'S', 'T', ' ', ' ', ' ', ' ', 'B', 'I', 'N' };
    sd_file_t file;
    if (!uS_SDOpen(file_name, &file)) {
        Print(1, 1, PSTR("test.bin?"));
        while (true);
    }
    uS_FlashFile(&file, USER_FLASH_PAGE, USER_FLASH_PAGE+1);

    asm volatile ("jmp 0x8000");
}
