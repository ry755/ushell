#ifndef VIDEO_H
#define VIDEO_H

#include <uzebox.h>

void uS_VideoInit();
void uS_Die(char *string);
void uS_BeginFrameDraw();
void uS_EndFrameDraw();
void uS_WaitFrame();
void uS_ClearLowSpiRam();
void uS_Blit(u8 *bitmap, u8 *mask, u16 x, u16 y);
void uS_BlitChar(unsigned char character, u16 x, u16 y);
void uS_BlitStr(const char *str, u16 x, u16 y);
void uS_BlitStrRam(char *str, u16 x, u16 y);

#endif
