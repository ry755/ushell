#include <uzebox.h>

#define uS_Wait200ns() asm volatile ("lpm\n\tlpm\n\t");

static u16 temp_pad_state;

u16 mouse_state;

// see this forum post for details: https://uzebox.org/forums/viewtopic.php?p=36055#p36055
void uS_ReadMouse() {
    u16 buttons = 0;
    u8 i;

    JOYPAD_OUT_PORT |= _BV(JOYPAD_LATCH_PIN); // latch controllers
    for (i = 0; i < 8; i++) uS_Wait200ns(); // wait 1.6us
    JOYPAD_OUT_PORT &= ~(_BV(JOYPAD_LATCH_PIN)); // unlatch controllers

    // read button states from the shift registers
    for (i = 0; i < 16; i++) {
        buttons >>= 1;

        JOYPAD_OUT_PORT &= ~(_BV(JOYPAD_CLOCK_PIN)); // pulse clock pin
        //uS_Wait200ns(); //not necessary!?

        if (((JOYPAD_IN_PORT & (1 << JOYPAD_DATA1_PIN)) == 0))// || ((JOYPAD_IN_PORT & (1 << JOYPAD_DATA2_PIN)) == 0))
            buttons |= (1 << 15);

        JOYPAD_OUT_PORT |= _BV(JOYPAD_CLOCK_PIN);
        for (u8 j = 0; j < 33; j++) uS_Wait200ns();
    }

    temp_pad_state = buttons;
    buttons = 0;
    for (i = 0; i < 8; i++) uS_Wait200ns(); // wait 1.6us

    if (temp_pad_state == (BTN_START+BTN_SELECT+BTN_Y+BTN_B)) SoftReset();

    // Read extended mouse data on both ports (it's fine if there is no mouse there)
    for (i = 0; i < 16; i++) {
        buttons <<= 1;

        JOYPAD_OUT_PORT &= ~(_BV(JOYPAD_CLOCK_PIN)); // pulse clock pin
        for (u8 j = 0; j < 8; j++) uS_Wait200ns();

        if (((JOYPAD_IN_PORT & (1 << JOYPAD_DATA1_PIN)) == 0))
            buttons |= 1;

        JOYPAD_OUT_PORT |= _BV(JOYPAD_CLOCK_PIN);
        for (u8 j = 0; j < 33; j++) uS_Wait200ns();
        if (i == 7) for (u8 j = 0; j < 100; j++) uS_Wait200ns();
    }

    mouse_state = buttons;
}
