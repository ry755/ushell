#ifndef VIDEO_H
#define VIDEO_H

#include <uzebox.h>

void uS_VideoInit();
void uS_BeginFrameDraw();
void uS_EndFrameDraw();
void uS_ClearLowSpiRam();
void uS_Blit(u8 *bitmap, u8 *mask, u16 x, u16 y);
void uS_BlitChar(u8 character, u16 x, u16 y);
void uS_BlitStr(u8 *str, u16 x, u16 y);
void uS_BlitStrRam(u8 *str, u16 x, u16 y);

#endif
