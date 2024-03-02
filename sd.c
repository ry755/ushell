#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>
#include <fatfs/ff.h>
#include <fatfs/diskio.h>
#include <string.h>

#include "sd.h"

FATFS fs;

static u8 old_video_config;

// the video mode's SPI RAM accesses messes with SD card accesses,
// so we disable it when needed
static void uS_SDBeginOp() {
    old_video_config = m74_config;
    m74_config = 0;
}

static void uS_SDEndOp() {
    m74_config = old_video_config;
}

u8 uS_SDInit() {
    uS_SDBeginOp();
    disk_initialize(0);
    u8 result = f_mount(0, &fs);
    uS_SDEndOp();
    return result;
}

bool uS_SDOpenFile(sd_file_t *file, char *file_name, u8 mode) {
    uS_SDBeginOp();
    u8 result = f_open(&(file->file), file_name, mode);
    uS_SDEndOp();
    return result == FR_OK;
}

// read bytes from a file into the specified buffer
u16 uS_SDReadFile(sd_file_t *file, u16 bytes_to_read, u16 byte_offset, u8 *buffer) {
    u16 bytes_read;
    uS_SDBeginOp();
    if (f_lseek(&(file->file), (DWORD)byte_offset) != FR_OK) { uS_SDEndOp(); return 0; }
    if (f_read(&(file->file), buffer, bytes_to_read, &bytes_read) != FR_OK) { uS_SDEndOp(); return 0; }
    uS_SDEndOp();
    return bytes_read;
}
