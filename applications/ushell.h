#ifndef USHELL_H
#define USHELL_H

#include <stdbool.h>
#include <stdint.h>
#include <avr/pgmspace.h>

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

#define LEFT_MOUSE_BUTTON (2 << 8)
#define RIGHT_MOUSE_BUTTON (1 << 8)

typedef uint8_t  u8;
typedef int8_t   s8;
typedef uint16_t u16;
typedef int16_t  s16;
typedef uint32_t u32;
typedef int32_t  s32;

typedef struct {
    void *fs;
    u16 id;
    u8 flag;
    u8 pad1;
    u32 fptr;
    u32 fsize;
    u32 sclust;
    u32 clust;
    u32 dsect;
    u32 dir_sect;
    u8 *dir_ptr;
} _inner_sd_file_t;

typedef struct {
    _inner_sd_file_t file;
} sd_file_t;

typedef struct {
    u32 size;
    u8 attribute;
    char name[13];
} sd_file_info_t;

typedef struct {
    void *fs;
    u16 id;
    u16 index;
    u32 sclust;
    u32 clust;
    u32 sect;
    u8 *dir;
    u8 *fn;
} _inner_sd_dir_t;

typedef struct {
    _inner_sd_dir_t file;
} sd_dir_t;

u16 __attribute__ ((optimize("O1"))) uS_Syscall(u16 u16_0, u16 u16_1, u16 u16_2, u16 u16_3, u8 syscall);

void uS_BeginFrameDraw();
void uS_EndFrameDraw();
void uS_WaitFrame();
void uS_Blit(u8 *bitmap, u8 *mask, u16 x, u16 y);
void uS_BlitRam(u8 *bitmap, u8 *mask, u16 x, u16 y);
void uS_BlitChar(char c, u16 x, u16 y);
void uS_BlitStr(const char *str, u16 x, u16 y);
void uS_BlitStrRam(char *str, u16 x, u16 y);
u16 uS_GetKey();
u16 uS_GetMouseButtons();
u16 uS_GetMouseX();
u16 uS_GetMouseY();
bool uS_Open(sd_file_t *file, char *path, u8 mode);
bool uS_Close(sd_file_t *file);
bool uS_OpenDir(sd_dir_t *dir, char *path);
u16 uS_Read(sd_file_t *file, u16 bytes_to_read, u16 byte_offset, u8 *buffer);
bool uS_ReadDir(sd_dir_t *dir, sd_file_info_t *file);
void uS_Exec(char *path);
void uS_EnableVideo(bool enable);

#endif
