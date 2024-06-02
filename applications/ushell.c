#include "ushell.h"

u16 __attribute__ ((optimize("O1"))) uS_Syscall(u16 u16_0, u16 u16_1, u16 u16_2, u16 u16_3, u8 syscall) { asm ("call 0xEF00"); }

void uS_BeginFrameDraw() { uS_Syscall(0, 0, 0, 0, SYS_BeginFrameDraw); }
void uS_EndFrameDraw() { uS_Syscall(0, 0, 0, 0, SYS_EndFrameDraw); }
void uS_WaitFrame() { uS_Syscall(0, 0, 0, 0, SYS_WaitFrame); }
void uS_Blit(u8 *bitmap, u8 *mask, u16 x, u16 y) { uS_Syscall((u16)bitmap, (u16)mask, x, y, SYS_Blit); }
void uS_BlitRam(u8 *bitmap, u8 *mask, u16 x, u16 y) { uS_Syscall((u16)bitmap, (u16)mask, x, y, SYS_BlitRam); }
void uS_BlitChar(char c, u16 x, u16 y) { uS_Syscall((u16)c, x, y, 0, SYS_BlitChar); }
void uS_BlitStr(const char *str, u16 x, u16 y) { uS_Syscall((u16)str, x, y, 0, SYS_BlitStr); }
void uS_BlitStrRam(char *str, u16 x, u16 y) { uS_Syscall((u16)str, x, y, 0, SYS_BlitStrRam); }
u16 uS_GetKey() { return uS_Syscall(0, 0, 0, 0, SYS_GetKey); }
u16 uS_GetMouseButtons() { return uS_Syscall(0, 0, 0, 0, SYS_GetMouseButtons); }
u16 uS_GetMouseX() { return uS_Syscall(0, 0, 0, 0, SYS_GetMouseX); }
u16 uS_GetMouseY() { return uS_Syscall(0, 0, 0, 0, SYS_GetMouseY); }
bool uS_Open(sd_file_t *file, char *path, u8 mode) { return uS_Syscall((u16)file, (u16)path, (u16)mode, 0, SYS_Open); }
bool uS_Close(sd_file_t *file) { return uS_Syscall((u16)file, 0, 0, 0, SYS_Close); }
bool uS_OpenDir(sd_dir_t *dir, char *path) { return uS_Syscall((u16)dir, (u16)path, 0, 0, SYS_OpenDir); }
u16 uS_Read(sd_file_t *file, u16 bytes_to_read, u16 byte_offset, u8 *buffer) { return uS_Syscall((u16)file, bytes_to_read, byte_offset, (u16)buffer, SYS_Read); }
bool uS_ReadDir(sd_dir_t *dir, sd_file_info_t *file) { return uS_Syscall((u16)dir, (u16)file, 0, 0, SYS_ReadDir); }
void uS_Exec(char *path) { uS_Syscall((u16)path, 0, 0, 0, SYS_Exec); }
void uS_EnableVideo(bool enable) { uS_Syscall((u16)enable, 0, 0, 0, SYS_EnableVideo); }
