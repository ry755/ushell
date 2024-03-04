#include "ushell.h"

u16 uS_Syscall(u16 u16_0, u16 u16_1, u16 u16_2, u16 u16_3, u8 syscall) { asm ("call 0xEF00"); }
