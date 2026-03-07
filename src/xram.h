#ifndef XRAM_H
#define XRAM_H

#include <uzebox.h>

void uS_XramWriteU8(u8 bank, u16 address, u8 value);
u8 uS_XramReadU8(u8 bank, u16 address);

#endif
