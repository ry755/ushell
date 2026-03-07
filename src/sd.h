#ifndef SD_H
#define SD_H

#include <stdbool.h>
#include <uzebox.h>
#include <fatfs/ff.h>

#define	SD_OPEN_EXISTING 0x00
#define	SD_READ          0x01
#define	SD_WRITE         0x02
#define	SD_CREATE_NEW    0x04
#define	SD_CREATE_ALWAYS 0x08
#define	SD_OPEN_ALWAYS   0x10

typedef struct {
    FIL file;
} sd_file_t;

typedef struct {
    u32 size;
    u8 attribute;
    char name[13];
} sd_file_info_t;

typedef struct {
    DIR dir;
} sd_dir_t;

u8 uS_SDInit();
bool uS_SDOpenFile(sd_file_t *file, char *path, u8 mode);
bool uS_SDCloseFile(sd_file_t *file);
bool uS_SDOpenDir(sd_dir_t *dir, char *path);
u16 uS_SDReadFile(sd_file_t *file, u16 bytes_to_read, u16 byte_offset, u8 *buffer);
bool uS_SDReadDir(sd_dir_t *dir, sd_file_info_t *file);

#endif
