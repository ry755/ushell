#ifndef SD_H
#define SD_H

#include <stdbool.h>
#include <uzebox.h>

typedef char sd_file_name_t[11];

typedef struct {
    u32 starting_cluster;
    u32 current_position;
} sd_file_t;

bool uS_SDInit();
bool uS_SDOpen(sd_file_name_t file_name, sd_file_t *file);
const u8 *uS_SDReadFileSector(sd_file_t *file, u32 sector);

#endif
