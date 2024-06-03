#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>

#include "flash.h"
#include "sd.h"
#include "syscall.h"
#include "video.h"

#define STARTUP_APP "desktop.app"

int main() {
    u8 sd_ok = uS_SDInit();
    uS_VideoInit();
    if (sd_ok != 0) {
        uS_BlitChar('0' + sd_ok, 0, 8);
        uS_Die("SD card?");
    }
    if (!uS_BootloaderCheck()) uS_Die("Patched bootloader?");
    uS_SyscallTrampolineInstall();

    uS_Exec(STARTUP_APP);
    uS_BlitStrRam(STARTUP_APP, 0, 8);
    uS_Die("Failed to exec startup app!");
}
