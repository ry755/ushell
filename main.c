#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>

#include "flash.h"
#include "sd.h"
#include "syscall.h"
#include "video.h"

#define STARTUP_APP "/ushell/desktop.bin"

int main() {
    u8 sd_ok = uS_SDInit();
    uS_VideoInit();
    if (sd_ok != 0) {
        uS_BlitChar('0' + sd_ok, 0, 8);
        uS_Die("SD card?");
    }
    if (!uS_BootloaderCheck()) uS_Die("Bootloader?");
    uS_SyscallTrampolineInstall();

    sd_file_t startup_app;
    if (!uS_SDOpenFile(&startup_app, STARTUP_APP, SD_READ)) uS_Die("Startup app?");
    uS_FlashFile(&startup_app, USER_FLASH_PAGE);
    asm ("jmp 0x8000");
}
