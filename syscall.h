#ifndef SYSCALL_H
#define SYSCALL_H

#include <uzebox.h>

#define SYS_BeginFrameDraw  0
#define SYS_EndFrameDraw    1
#define SYS_WaitFrame       2
#define SYS_Blit            3
#define SYS_BlitRam         4
#define SYS_BlitChar        5
#define SYS_BlitStr         6
#define SYS_BlitStrRam      7
#define SYS_GetKey          8
#define SYS_GetMouseButtons 9
#define SYS_GetMouseX       10
#define SYS_GetMouseY       11
#define SYS_Open            12
#define SYS_Close           13
#define SYS_OpenDir         14
#define SYS_Read            15
#define SYS_ReadDir         16
#define SYS_Exec            17
#define SYS_EnableVideo     18

u16 uS_Syscall(u16 u16_0, u16 u16_1, u16 u16_2, u16 u16_3, u8 syscall);
void uS_SyscallTrampolineInstall();

#endif
