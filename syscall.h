#ifndef SYSCALL_H
#define SYSCALL_H

#include <uzebox.h>

#define SYS_BeginFrameDraw 0
#define SYS_EndFrameDraw   1
#define SYS_BlitChar       2
#define SYS_BlitStr        3
#define SYS_BlitStrRam     4

u16 uS_Syscall(u16 u16_0, u16 u16_1, u16 u16_2, u16 u16_3, u8 syscall);
void uS_SyscallTrampolineInstall();

#endif
