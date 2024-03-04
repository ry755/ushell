#include "ushell.h"

void main(void) {
    uS_Syscall(0, 0, 0, 0, SYS_BeginFrameDraw);
    uS_Syscall((u16)"hello world!", 0, 0, 0, SYS_BlitStrRam);
    while (1) { uS_Syscall(0, 0, 0, 0, SYS_WaitFrame); }
}
