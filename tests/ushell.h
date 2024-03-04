#ifndef USHELL_H
#define USHELL_H

#include <stdint.h>
#include <avr/pgmspace.h>

#include "syscall.h"

typedef uint8_t  u8;
typedef int8_t   s8;
typedef uint16_t u16;
typedef int16_t  s16;
typedef uint32_t u32;
typedef int32_t  s32;

u16 uS_Syscall(u16 u16_0, u16 u16_1, u16 u16_2, u16 u16_3, u8 syscall);

#endif
