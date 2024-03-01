#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>
#include <spiram.h>
#include <bootlib.h>

#include "xram.h"

// write a u8 to XRAM, redoing the transfer if it occurred at the start of a frame
void uS_XramWriteU8(u8 bank, u16 address, u8 value) {
    ClearVsyncFlag();
    SpiRamWriteU8(bank, address, value);
    if (GetVsyncFlag())
        SpiRamWriteU8(bank, address, value);
}

// read a u8 from XRAM, redoing the transfer if it occurred at the start of a frame
u8 uS_XramReadU8(u8 bank, u16 address) {
    ClearVsyncFlag();
    u8 value = SpiRamReadU8(bank, address);
    if (GetVsyncFlag())
        value = SpiRamReadU8(bank, address);
    return value;
}
