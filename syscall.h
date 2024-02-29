#ifndef SYSCALL_H
#define SYSCALL_H

#include <uzebox.h>

u16 uS_Syscall(u16 u16_0, u16 u16_1, u8 u8_0, u8 u8_1, u8 u8_2);
void uS_SyscallTrampolineInstall();

#endif
