#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>
#include <bootlib.h>
#include <string.h>

#include "sd.h"

u8 sd_buf[512];
sdc_struct_t sd_struct;

bool uS_SDInit() {
    sd_struct.bufp = &(sd_buf[0]);
    if (FS_Init(&sd_struct) != 0) return false;
    else return true;
}

bool uS_SDOpen(sd_file_name_t file_name, sd_file_t *file) {
    u32 result = FS_Find(&sd_struct,
        ((u16)(file_name[0]) << 8) |
        ((u16)(file_name[1])),
        ((u16)(file_name[2]) << 8) |
        ((u16)(file_name[3])),
        ((u16)(file_name[4]) << 8) |
        ((u16)(file_name[5])),
        ((u16)(file_name[6]) << 8) |
        ((u16)(file_name[7])),
        ((u16)(file_name[8]) << 8) |
        ((u16)(file_name[9])),
        ((u16)(file_name[10]) << 8) |
        ((u16)(0))
    );
    if (result == 0) return false;

    FS_Select_Cluster(&sd_struct, result);
    file->starting_cluster = result;
    file->current_position = FS_Get_Pos(&sd_struct);
    return true;
}

// read a sector in an opened file and return a pointer to the internal sector buffer
// BUG:  FS_Next_Sector() doesn't seem to ever return an EOF indicator, even though the docs say it does
//       this means you won't be able to detect the end of the file!! keep this in mind
// NOTE: you must copy the sector data to your own buffer if you intend to access it for long periods of time!
//       reading another sector (even a sector in a different file) will overwrite the internal buffer!
const u8 *uS_SDReadFileSector(sd_file_t *file, u32 sector) {
    // set the cluster and sector positions
    FS_Select_Cluster(&sd_struct, file->starting_cluster);
    FS_Set_Pos(&sd_struct, file->current_position);
    if (FS_Get_Sector(&sd_struct) != sector) {
        FS_Reset_Sector(&sd_struct);
        for (u32 i = 0; i < sector; i++) FS_Next_Sector(&sd_struct);
    }
    file->current_position = FS_Get_Pos(&sd_struct);

    // read a sector and return a pointer to the sector buffer
    FS_Read_Sector(&sd_struct);
    return &sd_buf[0];
}
