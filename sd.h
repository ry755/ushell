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

u8 uS_SDInit();
bool uS_SDOpenFile(sd_file_t *file, char *file_name, u8 mode);
u16 uS_SDReadFile(sd_file_t *file, u16 bytes_to_read, u16 byte_offset, u8 *buffer);

#endif
