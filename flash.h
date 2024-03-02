#ifndef FLASH_H
#define FLASH_H

#include <uzebox.h>

#include "sd.h"

#define USER_FLASH_PAGE 0x80

u8 uS_FlashPage(u8 *source, u8 target_page);
void uS_FlashFile(sd_file_t *file, u8 starting_target_page);
bool uS_BootloaderCheck();

#endif
