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
bool sd_needs_reinit = true;

static u8 old_video_config;

// the video mode's SPI RAM accesses messes with SD card accesses,
// so we disable it when needed
static void uS_SDBeginOp() {
    old_video_config = m74_config;
    m74_config = 0;
    if (sd_needs_reinit) {
        disk_initialize(0);
        sd_needs_reinit = false;
    }
}

static void uS_SDEndOp() {
    m74_config = old_video_config;
    sd_needs_reinit = (bool)old_video_config;
}

u8 uS_SDInit() {
    uS_SDBeginOp();
    u8 result = f_mount(0, &fs);
    uS_SDEndOp();
    return result;
}

// open a file
// returns true on success
bool uS_SDOpenFile(sd_file_t *file, char *path, u8 mode) {
    uS_SDBeginOp();
    u8 result = f_open(&(file->file), path, mode);
    uS_SDEndOp();
    return result == FR_OK;
}

// close a file, flushing any changes to disk
// returns true on success
bool uS_SDCloseFile(sd_file_t *file) {
    uS_SDBeginOp();
    u8 result = f_close(&(file->file));
    uS_SDEndOp();
    return result == FR_OK;
}

// open a directory
// returns true on success
bool uS_SDOpenDir(sd_dir_t *dir, char *path) {
    uS_SDBeginOp();
    u8 result = f_opendir(&(dir->dir), path);
    uS_SDEndOp();
    return result == FR_OK;
}

// read bytes from a file into the specified buffer
// returns the number of bytes actually read
u16 uS_SDReadFile(sd_file_t *file, u16 bytes_to_read, u16 byte_offset, u8 *buffer) {
    u16 bytes_read;
    uS_SDBeginOp();
    if (f_lseek(&(file->file), (DWORD)byte_offset) != FR_OK) { uS_SDEndOp(); return 0; }
    if (f_read(&(file->file), buffer, bytes_to_read, &bytes_read) != FR_OK) { uS_SDEndOp(); return 0; }
    uS_SDEndOp();
    return bytes_read;
}

// read a file info block from a directory, then increment to the next file
// pass NULL for `file` to rewind the directory
// returns true on success
bool uS_SDReadDir(sd_dir_t *dir, sd_file_info_t *file) {
    FILINFO file_info;
    uS_SDBeginOp();
    if (file == NULL) { f_readdir(&(dir->dir), 0); uS_SDEndOp(); return true; }
    if (f_readdir(&(dir->dir), &file_info) != FR_OK) { uS_SDEndOp(); return false; }
    uS_SDEndOp();

    strncpy(file->name, file_info.fname, 13);
    file->attribute = file_info.fattrib;
    file->size = file_info.fsize;
    return true;
}
