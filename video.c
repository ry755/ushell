#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>
#include <spiram.h>
#include <keyboard.h>

#include "mouse.h"
#include "video.h"
#include "xram.h"

#include "tiles.h"

// row selectors
static unsigned char rowsel[] = {
    0U,  // first line: start at scanline 0
    255U // end of list
};

// VRAM rows for 216 lines
#define HIGHEST_VRAM_ROW 26
static m74_mode7_vram_t vramrow[HIGHEST_VRAM_ROW+1];

// tile row VRAM address table
static u16 const vramrow_offs[32U] PROGMEM = {
    (u16)(&vramrow[ 0]),
    (u16)(&vramrow[ 1]),
    (u16)(&vramrow[ 2]),
    (u16)(&vramrow[ 3]),
    (u16)(&vramrow[ 4]),
    (u16)(&vramrow[ 5]),
    (u16)(&vramrow[ 6]),
    (u16)(&vramrow[ 7]),
    (u16)(&vramrow[ 8]),
    (u16)(&vramrow[ 9]),
    (u16)(&vramrow[10]),
    (u16)(&vramrow[11]),
    (u16)(&vramrow[12]),
    (u16)(&vramrow[13]),
    (u16)(&vramrow[14]),
    (u16)(&vramrow[15]),
    (u16)(&vramrow[16]),
    (u16)(&vramrow[17]),
    (u16)(&vramrow[18]),
    (u16)(&vramrow[19]),
    (u16)(&vramrow[20]),
    (u16)(&vramrow[21]),
    (u16)(&vramrow[22]),
    (u16)(&vramrow[23]),
    (u16)(&vramrow[24]),
    (u16)(&vramrow[25]),
    (u16)(&vramrow[26]),
    (u16)(&vramrow[26]),
    (u16)(&vramrow[26]),
    (u16)(&vramrow[26]),
    (u16)(&vramrow[26]),
    (u16)(&vramrow[26])
};

static u16 under_cursor[8];
static bool showing_cursor = false;
static bool mouse_detected = false;
u16 cursor_x = 384 / 2;
u16 cursor_y = 216 / 2;

u8 keyboard_buffer = 0;
u8 keyboard_mod_buffer = 0;

static u16 framebuffer_addr;

extern bool snesMouseEnabled;
extern u16 mouse_state;

static void uS_ShowCursor() {
    if (showing_cursor) return;
    showing_cursor = true;

    // draw the cursor, saving what's under it
    // thanks to my friend mebibytedraco for helping with this!
    u16 byte_off = (cursor_y * 384L + cursor_x) / 8L;
    u8 bit_off = (cursor_y * 384L + cursor_x) % 8;
    for (u8 line = 0; line < 8; line++) {
        u8 high_byte = uS_XramReadU8(0, framebuffer_addr + byte_off);
        u8 low_byte = uS_XramReadU8(0, framebuffer_addr + byte_off + 1);
        u16 word = ((u16)high_byte << 8) | low_byte;
        under_cursor[line] = word;
        u16 mask = ((u16)res_cursor_mask[line] << 8) >> bit_off;
        word &= ~mask;
        u16 sprite = ((u16)res_cursor[line] << 8) >> bit_off;
        sprite |= word;
        uS_XramWriteU8(0, framebuffer_addr + byte_off, sprite >> 8);
        uS_XramWriteU8(0, framebuffer_addr + byte_off + 1, sprite & 0xFF);
        byte_off += 384L / 8L;
    }
}

static void uS_HideCursor() {
    if (!showing_cursor) return;
    showing_cursor = false;

    u16 byte_off = (cursor_y * 384L + cursor_x) / 8L;
    for (u8 line = 0; line < 8; line++) {
        uS_XramWriteU8(0, framebuffer_addr + byte_off, under_cursor[line] >> 8);
        uS_XramWriteU8(0, framebuffer_addr + byte_off + 1, under_cursor[line] & 0xFF);
        byte_off += 384L / 8L;
    }
}

static void uS_UpdateMouse() {
    /*u16 buttons = ReadJoypad(0);
    if (buttons & BTN_UP) cursor_y--;
    if (buttons & BTN_DOWN) cursor_y++;
    if (buttons & BTN_LEFT) cursor_x--;
    if (buttons & BTN_RIGHT) cursor_x++;*/

    u16 mouse = mouse_state;
    s16 mx = cursor_x;
    s16 my = cursor_y;

    if (mouse & 0x80) {
        mx -= (mouse & 0x7F);
        if (mx < 0) mx = 0;
    } else {
        mx += (mouse & 0x7F);
        if (mx > 383) mx = 383;
    }

    if (mouse & 0x8000) {
        my -= ((mouse >> 8) & 0x7F);
        if (my < 0) my = 0;
    } else {
        my += ((mouse >> 8) & 0x7F);
        if (my > 215) my = 215;
    }

    cursor_x = (u16)mx;
    cursor_y = (u16)my;
}

static void uS_UpdateKeyboard() {
    KeyboardPoll();
    keyboard_buffer = KeyboardGetKey(true);
    keyboard_mod_buffer = KeyboardGetModifiers();

    if (!mouse_detected) {
        switch (keyboard_buffer) {
            case KB_UP: cursor_y -= 2; break;
            case KB_DOWN: cursor_y += 2; break;
            case KB_LEFT: cursor_x -= 2; break;
            case KB_RIGHT: cursor_x += 2; break;
            default: break;
        }
        if ((s16)cursor_x < 0) cursor_x = 0;
        if ((s16)cursor_x > 383) cursor_x = 383;
        if ((s16)cursor_y < 0) cursor_y = 0;
        if ((s16)cursor_y > 215) cursor_x = 215;
    }
}

void _emu_whisper(u16 port, u8 value) {
    if (port==0x39 || port == 0) { u8 volatile *const _whisper_pointer1 = (u8 *)0x39; *_whisper_pointer1 = value; }
    if (port==0x3A || port == 1) { u8 volatile *const _whisper_pointer2 = (u8 *)0x3A; *_whisper_pointer2 = value; }
}

void uS_VideoInit() {
    // set main configuration flags, display disabled
    m74_config = 0;
    m74_discol = 0x49;

    SpiRamInit();
    uS_ClearLowSpiRam();

    // set rendering parameters for 4:3 display
    SetRenderingParameters(24, 216);

    // set row selector
    m74_rows = (u16)(&rowsel[0]);

    // set tile row VRAM addresses
    m74_vaddr = (u16)(&vramrow_offs[0]);

    // set up VRAM
    for (u16 i = 0; i < HIGHEST_VRAM_ROW+1; i++) {
        vramrow[i].config = 7; // row mode: 7
        vramrow[i].img_addr = (i * 48 * 8); // address in SPI RAM
        vramrow[i].fgcol = 0xB6;
        vramrow[i].bgcol = 0x49;
    }
    framebuffer_addr = vramrow[0].img_addr;

    // copy font data into SPI RAM
    SpiRamSeqWriteStart(M74_M67_FONT_OFF / 65536, M74_M67_FONT_OFF % 65536);
    for (u16 i = 0; i < 2048; i++) {
        SpiRamSeqWriteU8(pgm_read_byte(&res_font[i]));
    }
    SpiRamSeqWriteEnd();

    m74_config |= M74_CFG_ENABLE;
    WaitVsync(8);
    snesMouseEnabled = true;
    SetUserPostVsyncCallback(uS_ReadMouse);
    WaitVsync(20);
    uS_EndFrameDraw();
}

void uS_Die(char *string) {
    uS_HideCursor();
    uS_BlitStrRam((char *)string, 0, 0);
    while (true);
}

// call this at the beginning of your frame loop
void uS_BeginFrameDraw() {
    uS_HideCursor();
    //if ((DetectControllers() & 2) == 2) {
    //    mouse_detected = true;
    //    uS_UpdateMouse();
    //} else {
    //    mouse_detected = false;
    //}
    uS_UpdateMouse();
    uS_UpdateKeyboard();
}

// call this at the end of your frame loop
void uS_EndFrameDraw() {
    uS_ShowCursor();
    WaitVsync(1);
}

// wait for a new frame, while also keeping the mouse and keyboard polled
void uS_WaitFrame() {
    uS_EndFrameDraw();
    uS_BeginFrameDraw();
}

void uS_ClearLowSpiRam() {
    // disable the screen while accessing SPI RAM
    // this is to prevent data corruption that will occur if the
    // SPI RAM is accessed right at the beginning of a frame
    u8 old_config = m74_config;
    m74_config = 0;

    SpiRamSeqWriteStart(0, 0);
    for (u16 i = 0; i != 0xFFFF; i++) {
        SpiRamSeqWriteU8(0);
    }
    SpiRamSeqWriteEnd();

    // restore the old screen enable state
    m74_config = old_config;
}

// blit an 8x8 bitmap to the screen
// `mask` can be zero to draw the entire bitmap without transparency
void uS_Blit(u8 *bitmap, u8 *mask, u16 x, u16 y) {
    u8 default_mask[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    if (mask == 0) mask = &default_mask[0];

    // thanks to my friend mebibytedraco for helping with this!
    u16 byte_off = (y * 384L + x) / 8L;
    u8 bit_off = (y * 384 + x) % 8;
    for (u8 line = 0; line < 8; line++) {
        u8 high_byte = uS_XramReadU8(0, framebuffer_addr + byte_off);
        u8 low_byte = uS_XramReadU8(0, framebuffer_addr + byte_off + 1);
        u16 word = ((u16)high_byte << 8) | low_byte;
        u16 mask_word = ((u16)mask[line] << 8) >> bit_off;
        word &= ~mask_word;
        u16 sprite = ((u16)bitmap[line] << 8) >> bit_off;
        sprite |= word;
        uS_XramWriteU8(0, framebuffer_addr + byte_off, sprite >> 8);
        uS_XramWriteU8(0, framebuffer_addr + byte_off + 1, sprite & 0xFF);
        byte_off += 384L / 8L;
    }
}

// blit an 8x8 character bitmap to the screen
void uS_BlitChar(unsigned char character, u16 x, u16 y) {
    u8 char_bitmap[8];
    for (u8 i = 0; i < 8; i++)
        char_bitmap[i] = pgm_read_byte(&res_font[character * 8 + i]);
    uS_Blit(char_bitmap, 0, x, y);
}

void uS_BlitStr(const char *str, u16 x, u16 y) {
    do {
        uS_BlitChar(pgm_read_byte(str), x, y);
        x += 8;
    } while (pgm_read_byte(str++));
}

void uS_BlitStrRam(char *str, u16 x, u16 y) {
    do {
        uS_BlitChar(*str, x, y);
        x += 8;
    } while (*str++);
}
