/*
 *  Mode 748, Row mode 6/7 image
 *  Copyright (C) 2018 Sandor Zsuga (Jubatian)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TILES_H
#define TILES_H

#include <avr/pgmspace.h>

unsigned char res_cursor[8] = {
    0b00000000,
    0b01111000,
    0b01110000,
    0b01111000,
    0b01011000,
    0b00000000,
    0b00000000,
    0b00000000
};

unsigned char res_cursor_mask[8] = {
    0b11111000,
    0b11111000,
    0b11111000,
    0b11111000,
    0b11111000,
    0b00000000,
    0b00000000,
    0b00000000
};

/*unsigned char res_cursor[64] = {
    1,1,1,1,1,1,0,0,
    1,2,2,2,1,0,0,0,
    1,2,2,1,0,0,0,0,
    1,2,1,1,1,0,0,0,
    1,1,0,0,1,1,0,0,
    1,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};*/

// 1bpp ASCII font
const unsigned char res_font[2048] PROGMEM = {
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x7EU, 0x81U, 0xA5U, 0x81U, 0xBDU, 0x99U, 0x81U, 0x7EU,
    0x7EU, 0xFFU, 0xDBU, 0xFFU, 0xC3U, 0xE7U, 0xFFU, 0x7EU,
    0x6CU, 0xFEU, 0xFEU, 0xFEU, 0x7CU, 0x38U, 0x10U, 0x00U,
    0x10U, 0x38U, 0x7CU, 0xFEU, 0x7CU, 0x38U, 0x10U, 0x00U,
    0x38U, 0x7CU, 0x38U, 0xFEU, 0xFEU, 0xD6U, 0x10U, 0x38U,
    0x10U, 0x10U, 0x38U, 0x7CU, 0xFEU, 0x7CU, 0x10U, 0x38U,
    0x00U, 0x00U, 0x18U, 0x3CU, 0x3CU, 0x18U, 0x00U, 0x00U,
    0xFFU, 0xFFU, 0xE7U, 0xC3U, 0xC3U, 0xE7U, 0xFFU, 0xFFU,
    0x00U, 0x3CU, 0x66U, 0x42U, 0x42U, 0x66U, 0x3CU, 0x00U,
    0xFFU, 0xC3U, 0x99U, 0xBDU, 0xBDU, 0x99U, 0xC3U, 0xFFU,
    0x0FU, 0x07U, 0x0FU, 0x7DU, 0xCCU, 0xCCU, 0xCCU, 0x78U,
    0x3CU, 0x66U, 0x66U, 0x66U, 0x3CU, 0x18U, 0x7EU, 0x18U,
    0x3FU, 0x33U, 0x3FU, 0x30U, 0x30U, 0x70U, 0xF0U, 0xE0U,
    0x7FU, 0x63U, 0x7FU, 0x63U, 0x63U, 0x67U, 0xE6U, 0xC0U,
    0x18U, 0xDBU, 0x3CU, 0xE7U, 0xE7U, 0x3CU, 0xDBU, 0x18U,
    0x80U, 0xE0U, 0xF8U, 0xFEU, 0xF8U, 0xE0U, 0x80U, 0x00U,
    0x02U, 0x0EU, 0x3EU, 0xFEU, 0x3EU, 0x0EU, 0x02U, 0x00U,
    0x18U, 0x3CU, 0x7EU, 0x18U, 0x18U, 0x7EU, 0x3CU, 0x18U,
    0x66U, 0x66U, 0x66U, 0x66U, 0x66U, 0x00U, 0x66U, 0x00U,
    0x7FU, 0xDBU, 0xDBU, 0x7BU, 0x1BU, 0x1BU, 0x1BU, 0x00U,
    0x3EU, 0x63U, 0x38U, 0x6CU, 0x6CU, 0x38U, 0xCCU, 0x78U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x7EU, 0x7EU, 0x7EU, 0x00U,
    0x18U, 0x3CU, 0x7EU, 0x18U, 0x7EU, 0x3CU, 0x18U, 0xFFU,
    0x18U, 0x3CU, 0x7EU, 0x18U, 0x18U, 0x18U, 0x18U, 0x00U,
    0x18U, 0x18U, 0x18U, 0x18U, 0x7EU, 0x3CU, 0x18U, 0x00U,
    0x00U, 0x18U, 0x0CU, 0xFEU, 0x0CU, 0x18U, 0x00U, 0x00U,
    0x00U, 0x30U, 0x60U, 0xFEU, 0x60U, 0x30U, 0x00U, 0x00U,
    0x00U, 0x00U, 0xC0U, 0xC0U, 0xC0U, 0xFEU, 0x00U, 0x00U,
    0x00U, 0x24U, 0x66U, 0xFFU, 0x66U, 0x24U, 0x00U, 0x00U,
    0x00U, 0x18U, 0x3CU, 0x7EU, 0xFFU, 0xFFU, 0x00U, 0x00U,
    0x00U, 0xFFU, 0xFFU, 0x7EU, 0x3CU, 0x18U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x30U, 0x78U, 0x78U, 0x30U, 0x30U, 0x00U, 0x30U, 0x00U,
    0x6CU, 0x6CU, 0x6CU, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x6CU, 0x6CU, 0xFEU, 0x6CU, 0xFEU, 0x6CU, 0x6CU, 0x00U,
    0x30U, 0x7CU, 0xC0U, 0x78U, 0x0CU, 0xF8U, 0x30U, 0x00U,
    0x00U, 0xC6U, 0xCCU, 0x18U, 0x30U, 0x66U, 0xC6U, 0x00U,
    0x38U, 0x6CU, 0x38U, 0x76U, 0xDCU, 0xCCU, 0x76U, 0x00U,
    0x60U, 0x60U, 0xC0U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x18U, 0x30U, 0x60U, 0x60U, 0x60U, 0x30U, 0x18U, 0x00U,
    0x60U, 0x30U, 0x18U, 0x18U, 0x18U, 0x30U, 0x60U, 0x00U,
    0x00U, 0x66U, 0x3CU, 0xFFU, 0x3CU, 0x66U, 0x00U, 0x00U,
    0x00U, 0x30U, 0x30U, 0xFCU, 0x30U, 0x30U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x30U, 0x30U, 0x60U,
    0x00U, 0x00U, 0x00U, 0xFCU, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x30U, 0x30U, 0x00U,
    0x06U, 0x0CU, 0x18U, 0x30U, 0x60U, 0xC0U, 0x80U, 0x00U,
    0x7CU, 0xC6U, 0xCEU, 0xDEU, 0xF6U, 0xE6U, 0x7CU, 0x00U,
    0x30U, 0x70U, 0x30U, 0x30U, 0x30U, 0x30U, 0xFCU, 0x00U,
    0x78U, 0xCCU, 0x0CU, 0x38U, 0x60U, 0xCCU, 0xFCU, 0x00U,
    0x78U, 0xCCU, 0x0CU, 0x38U, 0x0CU, 0xCCU, 0x78U, 0x00U,
    0x1CU, 0x3CU, 0x6CU, 0xCCU, 0xFEU, 0x0CU, 0x1EU, 0x00U,
    0xFCU, 0xC0U, 0xF8U, 0x0CU, 0x0CU, 0xCCU, 0x78U, 0x00U,
    0x38U, 0x60U, 0xC0U, 0xF8U, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0xFCU, 0xCCU, 0x0CU, 0x18U, 0x30U, 0x30U, 0x30U, 0x00U,
    0x78U, 0xCCU, 0xCCU, 0x78U, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0x78U, 0xCCU, 0xCCU, 0x7CU, 0x0CU, 0x18U, 0x70U, 0x00U,
    0x00U, 0x30U, 0x30U, 0x00U, 0x00U, 0x30U, 0x30U, 0x00U,
    0x00U, 0x30U, 0x30U, 0x00U, 0x00U, 0x30U, 0x30U, 0x60U,
    0x18U, 0x30U, 0x60U, 0xC0U, 0x60U, 0x30U, 0x18U, 0x00U,
    0x00U, 0x00U, 0xFCU, 0x00U, 0x00U, 0xFCU, 0x00U, 0x00U,
    0x60U, 0x30U, 0x18U, 0x0CU, 0x18U, 0x30U, 0x60U, 0x00U,
    0x78U, 0xCCU, 0x0CU, 0x18U, 0x30U, 0x00U, 0x30U, 0x00U,
    0x7CU, 0xC6U, 0xDEU, 0xDEU, 0xDEU, 0xC0U, 0x78U, 0x00U,
    0x30U, 0x78U, 0xCCU, 0xCCU, 0xFCU, 0xCCU, 0xCCU, 0x00U,
    0xFCU, 0x66U, 0x66U, 0x7CU, 0x66U, 0x66U, 0xFCU, 0x00U,
    0x3CU, 0x66U, 0xC0U, 0xC0U, 0xC0U, 0x66U, 0x3CU, 0x00U,
    0xF8U, 0x6CU, 0x66U, 0x66U, 0x66U, 0x6CU, 0xF8U, 0x00U,
    0xFEU, 0x62U, 0x68U, 0x78U, 0x68U, 0x62U, 0xFEU, 0x00U,
    0xFEU, 0x62U, 0x68U, 0x78U, 0x68U, 0x60U, 0xF0U, 0x00U,
    0x3CU, 0x66U, 0xC0U, 0xC0U, 0xCEU, 0x66U, 0x3EU, 0x00U,
    0xCCU, 0xCCU, 0xCCU, 0xFCU, 0xCCU, 0xCCU, 0xCCU, 0x00U,
    0x78U, 0x30U, 0x30U, 0x30U, 0x30U, 0x30U, 0x78U, 0x00U,
    0x1EU, 0x0CU, 0x0CU, 0x0CU, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0xE6U, 0x66U, 0x6CU, 0x78U, 0x6CU, 0x66U, 0xE6U, 0x00U,
    0xF0U, 0x60U, 0x60U, 0x60U, 0x62U, 0x66U, 0xFEU, 0x00U,
    0xC6U, 0xEEU, 0xFEU, 0xFEU, 0xD6U, 0xC6U, 0xC6U, 0x00U,
    0xC6U, 0xE6U, 0xF6U, 0xDEU, 0xCEU, 0xC6U, 0xC6U, 0x00U,
    0x38U, 0x6CU, 0xC6U, 0xC6U, 0xC6U, 0x6CU, 0x38U, 0x00U,
    0xFCU, 0x66U, 0x66U, 0x7CU, 0x60U, 0x60U, 0xF0U, 0x00U,
    0x78U, 0xCCU, 0xCCU, 0xCCU, 0xDCU, 0x78U, 0x1CU, 0x00U,
    0xFCU, 0x66U, 0x66U, 0x7CU, 0x6CU, 0x66U, 0xE6U, 0x00U,
    0x78U, 0xCCU, 0x60U, 0x30U, 0x18U, 0xCCU, 0x78U, 0x00U,
    0xFCU, 0xB4U, 0x30U, 0x30U, 0x30U, 0x30U, 0x78U, 0x00U,
    0xCCU, 0xCCU, 0xCCU, 0xCCU, 0xCCU, 0xCCU, 0xFCU, 0x00U,
    0xCCU, 0xCCU, 0xCCU, 0xCCU, 0xCCU, 0x78U, 0x30U, 0x00U,
    0xC6U, 0xC6U, 0xC6U, 0xD6U, 0xFEU, 0xEEU, 0xC6U, 0x00U,
    0xC6U, 0xC6U, 0x6CU, 0x38U, 0x38U, 0x6CU, 0xC6U, 0x00U,
    0xCCU, 0xCCU, 0xCCU, 0x78U, 0x30U, 0x30U, 0x78U, 0x00U,
    0xFEU, 0xC6U, 0x8CU, 0x18U, 0x32U, 0x66U, 0xFEU, 0x00U,
    0x78U, 0x60U, 0x60U, 0x60U, 0x60U, 0x60U, 0x78U, 0x00U,
    0xC0U, 0x60U, 0x30U, 0x18U, 0x0CU, 0x06U, 0x02U, 0x00U,
    0x78U, 0x18U, 0x18U, 0x18U, 0x18U, 0x18U, 0x78U, 0x00U,
    0x10U, 0x38U, 0x6CU, 0xC6U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0xFFU,
    0x30U, 0x30U, 0x18U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x78U, 0x0CU, 0x7CU, 0xCCU, 0x76U, 0x00U,
    0xE0U, 0x60U, 0x60U, 0x7CU, 0x66U, 0x66U, 0xDCU, 0x00U,
    0x00U, 0x00U, 0x78U, 0xCCU, 0xC0U, 0xCCU, 0x78U, 0x00U,
    0x1CU, 0x0CU, 0x0CU, 0x7CU, 0xCCU, 0xCCU, 0x76U, 0x00U,
    0x00U, 0x00U, 0x78U, 0xCCU, 0xFCU, 0xC0U, 0x78U, 0x00U,
    0x38U, 0x6CU, 0x60U, 0xF0U, 0x60U, 0x60U, 0xF0U, 0x00U,
    0x00U, 0x00U, 0x76U, 0xCCU, 0xCCU, 0x7CU, 0x0CU, 0xF8U,
    0xE0U, 0x60U, 0x6CU, 0x76U, 0x66U, 0x66U, 0xE6U, 0x00U,
    0x30U, 0x00U, 0x70U, 0x30U, 0x30U, 0x30U, 0x78U, 0x00U,
    0x0CU, 0x00U, 0x0CU, 0x0CU, 0x0CU, 0xCCU, 0xCCU, 0x78U,
    0xE0U, 0x60U, 0x66U, 0x6CU, 0x78U, 0x6CU, 0xE6U, 0x00U,
    0x70U, 0x30U, 0x30U, 0x30U, 0x30U, 0x30U, 0x78U, 0x00U,
    0x00U, 0x00U, 0xCCU, 0xFEU, 0xFEU, 0xD6U, 0xC6U, 0x00U,
    0x00U, 0x00U, 0xF8U, 0xCCU, 0xCCU, 0xCCU, 0xCCU, 0x00U,
    0x00U, 0x00U, 0x78U, 0xCCU, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0x00U, 0x00U, 0xDCU, 0x66U, 0x66U, 0x7CU, 0x60U, 0xF0U,
    0x00U, 0x00U, 0x76U, 0xCCU, 0xCCU, 0x7CU, 0x0CU, 0x1EU,
    0x00U, 0x00U, 0xDCU, 0x76U, 0x66U, 0x60U, 0xF0U, 0x00U,
    0x00U, 0x00U, 0x7CU, 0xC0U, 0x78U, 0x0CU, 0xF8U, 0x00U,
    0x10U, 0x30U, 0x7CU, 0x30U, 0x30U, 0x34U, 0x18U, 0x00U,
    0x00U, 0x00U, 0xCCU, 0xCCU, 0xCCU, 0xCCU, 0x76U, 0x00U,
    0x00U, 0x00U, 0xCCU, 0xCCU, 0xCCU, 0x78U, 0x30U, 0x00U,
    0x00U, 0x00U, 0xC6U, 0xD6U, 0xFEU, 0xFEU, 0x6CU, 0x00U,
    0x00U, 0x00U, 0xC6U, 0x6CU, 0x38U, 0x6CU, 0xC6U, 0x00U,
    0x00U, 0x00U, 0xCCU, 0xCCU, 0xCCU, 0x7CU, 0x0CU, 0xF8U,
    0x00U, 0x00U, 0xFCU, 0x98U, 0x30U, 0x64U, 0xFCU, 0x00U,
    0x1CU, 0x30U, 0x30U, 0xE0U, 0x30U, 0x30U, 0x1CU, 0x00U,
    0x18U, 0x18U, 0x18U, 0x00U, 0x18U, 0x18U, 0x18U, 0x00U,
    0xE0U, 0x30U, 0x30U, 0x1CU, 0x30U, 0x30U, 0xE0U, 0x00U,
    0x76U, 0xDCU, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x10U, 0x38U, 0x6CU, 0xC6U, 0xC6U, 0xFEU, 0x00U,
    0x78U, 0xCCU, 0xC0U, 0xCCU, 0x78U, 0x18U, 0x0CU, 0x78U,
    0x00U, 0xCCU, 0x00U, 0xCCU, 0xCCU, 0xCCU, 0x7EU, 0x00U,
    0x1CU, 0x00U, 0x78U, 0xCCU, 0xFCU, 0xC0U, 0x78U, 0x00U,
    0x7EU, 0xC3U, 0x3CU, 0x06U, 0x3EU, 0x66U, 0x3FU, 0x00U,
    0xCCU, 0x00U, 0x78U, 0x0CU, 0x7CU, 0xCCU, 0x7EU, 0x00U,
    0xE0U, 0x00U, 0x78U, 0x0CU, 0x7CU, 0xCCU, 0x7EU, 0x00U,
    0x30U, 0x30U, 0x78U, 0x0CU, 0x7CU, 0xCCU, 0x7EU, 0x00U,
    0x00U, 0x00U, 0x78U, 0xC0U, 0xC0U, 0x78U, 0x0CU, 0x38U,
    0x7EU, 0xC3U, 0x3CU, 0x66U, 0x7EU, 0x60U, 0x3CU, 0x00U,
    0xCCU, 0x00U, 0x78U, 0xCCU, 0xFCU, 0xC0U, 0x78U, 0x00U,
    0xE0U, 0x00U, 0x78U, 0xCCU, 0xFCU, 0xC0U, 0x78U, 0x00U,
    0xCCU, 0x00U, 0x70U, 0x30U, 0x30U, 0x30U, 0x78U, 0x00U,
    0x7CU, 0xC6U, 0x38U, 0x18U, 0x18U, 0x18U, 0x3CU, 0x00U,
    0xE0U, 0x00U, 0x70U, 0x30U, 0x30U, 0x30U, 0x78U, 0x00U,
    0xC6U, 0x38U, 0x6CU, 0xC6U, 0xFEU, 0xC6U, 0xC6U, 0x00U,
    0x30U, 0x30U, 0x00U, 0x78U, 0xCCU, 0xFCU, 0xCCU, 0x00U,
    0x1CU, 0x00U, 0xFCU, 0x60U, 0x78U, 0x60U, 0xFCU, 0x00U,
    0x00U, 0x00U, 0x7FU, 0x0CU, 0x7FU, 0xCCU, 0x7FU, 0x00U,
    0x3EU, 0x6CU, 0xCCU, 0xFEU, 0xCCU, 0xCCU, 0xCEU, 0x00U,
    0x78U, 0xCCU, 0x00U, 0x78U, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0x00U, 0xCCU, 0x00U, 0x78U, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0x00U, 0xE0U, 0x00U, 0x78U, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0x78U, 0xCCU, 0x00U, 0xCCU, 0xCCU, 0xCCU, 0x7EU, 0x00U,
    0x00U, 0xE0U, 0x00U, 0xCCU, 0xCCU, 0xCCU, 0x7EU, 0x00U,
    0x00U, 0xCCU, 0x00U, 0xCCU, 0xCCU, 0x7CU, 0x0CU, 0xF8U,
    0xC3U, 0x18U, 0x3CU, 0x66U, 0x66U, 0x3CU, 0x18U, 0x00U,
    0xCCU, 0x00U, 0xCCU, 0xCCU, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0x18U, 0x18U, 0x7EU, 0xC0U, 0xC0U, 0x7EU, 0x18U, 0x18U,
    0x38U, 0x6CU, 0x64U, 0xF0U, 0x60U, 0xE6U, 0xFCU, 0x00U,
    0xCCU, 0xCCU, 0x78U, 0xFCU, 0x30U, 0xFCU, 0x30U, 0x30U,
    0xF8U, 0xCCU, 0xCCU, 0xFAU, 0xC6U, 0xCFU, 0xC6U, 0xC7U,
    0x0EU, 0x1BU, 0x18U, 0x3CU, 0x18U, 0x18U, 0xD8U, 0x70U,
    0x1CU, 0x00U, 0x78U, 0x0CU, 0x7CU, 0xCCU, 0x7EU, 0x00U,
    0x38U, 0x00U, 0x70U, 0x30U, 0x30U, 0x30U, 0x78U, 0x00U,
    0x00U, 0x1CU, 0x00U, 0x78U, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0x00U, 0x1CU, 0x00U, 0xCCU, 0xCCU, 0xCCU, 0x7EU, 0x00U,
    0x00U, 0xF8U, 0x00U, 0xF8U, 0xCCU, 0xCCU, 0xCCU, 0x00U,
    0xFCU, 0x00U, 0xCCU, 0xECU, 0xFCU, 0xDCU, 0xCCU, 0x00U,
    0x3CU, 0x6CU, 0x6CU, 0x3EU, 0x00U, 0x7EU, 0x00U, 0x00U,
    0x38U, 0x6CU, 0x6CU, 0x38U, 0x00U, 0x7CU, 0x00U, 0x00U,
    0x30U, 0x00U, 0x30U, 0x60U, 0xC0U, 0xCCU, 0x78U, 0x00U,
    0x00U, 0x00U, 0x00U, 0xFCU, 0xC0U, 0xC0U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0xFCU, 0x0CU, 0x0CU, 0x00U, 0x00U,
    0xC3U, 0xC6U, 0xCCU, 0xDEU, 0x33U, 0x66U, 0xCCU, 0x0FU,
    0xC3U, 0xC6U, 0xCCU, 0xDBU, 0x37U, 0x6FU, 0xCFU, 0x03U,
    0x18U, 0x18U, 0x00U, 0x18U, 0x18U, 0x18U, 0x18U, 0x00U,
    0x00U, 0x33U, 0x66U, 0xCCU, 0x66U, 0x33U, 0x00U, 0x00U,
    0x00U, 0xCCU, 0x66U, 0x33U, 0x66U, 0xCCU, 0x00U, 0x00U,
    0x22U, 0x88U, 0x22U, 0x88U, 0x22U, 0x88U, 0x22U, 0x88U,
    0x55U, 0xAAU, 0x55U, 0xAAU, 0x55U, 0xAAU, 0x55U, 0xAAU,
    0xDBU, 0x77U, 0xDBU, 0xEEU, 0xDBU, 0x77U, 0xDBU, 0xEEU,
    0x18U, 0x18U, 0x18U, 0x18U, 0x18U, 0x18U, 0x18U, 0x18U,
    0x18U, 0x18U, 0x18U, 0x18U, 0xF8U, 0x18U, 0x18U, 0x18U,
    0x18U, 0x18U, 0xF8U, 0x18U, 0xF8U, 0x18U, 0x18U, 0x18U,
    0x36U, 0x36U, 0x36U, 0x36U, 0xF6U, 0x36U, 0x36U, 0x36U,
    0x00U, 0x00U, 0x00U, 0x00U, 0xFEU, 0x36U, 0x36U, 0x36U,
    0x00U, 0x00U, 0xF8U, 0x18U, 0xF8U, 0x18U, 0x18U, 0x18U,
    0x36U, 0x36U, 0xF6U, 0x06U, 0xF6U, 0x36U, 0x36U, 0x36U,
    0x36U, 0x36U, 0x36U, 0x36U, 0x36U, 0x36U, 0x36U, 0x36U,
    0x00U, 0x00U, 0xFEU, 0x06U, 0xF6U, 0x36U, 0x36U, 0x36U,
    0x36U, 0x36U, 0xF6U, 0x06U, 0xFEU, 0x00U, 0x00U, 0x00U,
    0x36U, 0x36U, 0x36U, 0x36U, 0xFEU, 0x00U, 0x00U, 0x00U,
    0x18U, 0x18U, 0xF8U, 0x18U, 0xF8U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0xF8U, 0x18U, 0x18U, 0x18U,
    0x18U, 0x18U, 0x18U, 0x18U, 0x1FU, 0x00U, 0x00U, 0x00U,
    0x18U, 0x18U, 0x18U, 0x18U, 0xFFU, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0xFFU, 0x18U, 0x18U, 0x18U,
    0x18U, 0x18U, 0x18U, 0x18U, 0x1FU, 0x18U, 0x18U, 0x18U,
    0x00U, 0x00U, 0x00U, 0x00U, 0xFFU, 0x00U, 0x00U, 0x00U,
    0x18U, 0x18U, 0x18U, 0x18U, 0xFFU, 0x18U, 0x18U, 0x18U,
    0x18U, 0x18U, 0x1FU, 0x18U, 0x1FU, 0x18U, 0x18U, 0x18U,
    0x36U, 0x36U, 0x36U, 0x36U, 0x37U, 0x36U, 0x36U, 0x36U,
    0x36U, 0x36U, 0x37U, 0x30U, 0x3FU, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x3FU, 0x30U, 0x37U, 0x36U, 0x36U, 0x36U,
    0x36U, 0x36U, 0xF7U, 0x00U, 0xFFU, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0xFFU, 0x00U, 0xF7U, 0x36U, 0x36U, 0x36U,
    0x36U, 0x36U, 0x37U, 0x30U, 0x37U, 0x36U, 0x36U, 0x36U,
    0x00U, 0x00U, 0xFFU, 0x00U, 0xFFU, 0x00U, 0x00U, 0x00U,
    0x36U, 0x36U, 0xF7U, 0x00U, 0xF7U, 0x36U, 0x36U, 0x36U,
    0x18U, 0x18U, 0xFFU, 0x00U, 0xFFU, 0x00U, 0x00U, 0x00U,
    0x36U, 0x36U, 0x36U, 0x36U, 0xFFU, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0xFFU, 0x00U, 0xFFU, 0x18U, 0x18U, 0x18U,
    0x00U, 0x00U, 0x00U, 0x00U, 0xFFU, 0x36U, 0x36U, 0x36U,
    0x36U, 0x36U, 0x36U, 0x36U, 0x3FU, 0x00U, 0x00U, 0x00U,
    0x18U, 0x18U, 0x1FU, 0x18U, 0x1FU, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x1FU, 0x18U, 0x1FU, 0x18U, 0x18U, 0x18U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x3FU, 0x36U, 0x36U, 0x36U,
    0x36U, 0x36U, 0x36U, 0x36U, 0xFFU, 0x36U, 0x36U, 0x36U,
    0x18U, 0x18U, 0xFFU, 0x18U, 0xFFU, 0x18U, 0x18U, 0x18U,
    0x18U, 0x18U, 0x18U, 0x18U, 0xF8U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x1FU, 0x18U, 0x18U, 0x18U,
    0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU,
    0x00U, 0x00U, 0x00U, 0x00U, 0xFFU, 0xFFU, 0xFFU, 0xFFU,
    0xF0U, 0xF0U, 0xF0U, 0xF0U, 0xF0U, 0xF0U, 0xF0U, 0xF0U,
    0x0FU, 0x0FU, 0x0FU, 0x0FU, 0x0FU, 0x0FU, 0x0FU, 0x0FU,
    0xFFU, 0xFFU, 0xFFU, 0xFFU, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x76U, 0xDCU, 0xC8U, 0xDCU, 0x76U, 0x00U,
    0x00U, 0x78U, 0xCCU, 0xF8U, 0xCCU, 0xF8U, 0xC0U, 0xC0U,
    0x00U, 0xFCU, 0xCCU, 0xC0U, 0xC0U, 0xC0U, 0xC0U, 0x00U,
    0x00U, 0xFEU, 0x6CU, 0x6CU, 0x6CU, 0x6CU, 0x6CU, 0x00U,
    0xFCU, 0xCCU, 0x60U, 0x30U, 0x60U, 0xCCU, 0xFCU, 0x00U,
    0x00U, 0x00U, 0x7EU, 0xD8U, 0xD8U, 0xD8U, 0x70U, 0x00U,
    0x00U, 0x66U, 0x66U, 0x66U, 0x66U, 0x7CU, 0x60U, 0xC0U,
    0x00U, 0x76U, 0xDCU, 0x18U, 0x18U, 0x18U, 0x18U, 0x00U,
    0xFCU, 0x30U, 0x78U, 0xCCU, 0xCCU, 0x78U, 0x30U, 0xFCU,
    0x38U, 0x6CU, 0xC6U, 0xFEU, 0xC6U, 0x6CU, 0x38U, 0x00U,
    0x38U, 0x6CU, 0xC6U, 0xC6U, 0x6CU, 0x6CU, 0xEEU, 0x00U,
    0x1CU, 0x30U, 0x18U, 0x7CU, 0xCCU, 0xCCU, 0x78U, 0x00U,
    0x00U, 0x00U, 0x7EU, 0xDBU, 0xDBU, 0x7EU, 0x00U, 0x00U,
    0x06U, 0x0CU, 0x7EU, 0xDBU, 0xDBU, 0x7EU, 0x60U, 0xC0U,
    0x38U, 0x60U, 0xC0U, 0xF8U, 0xC0U, 0x60U, 0x38U, 0x00U,
    0x78U, 0xCCU, 0xCCU, 0xCCU, 0xCCU, 0xCCU, 0xCCU, 0x00U,
    0x00U, 0xFCU, 0x00U, 0xFCU, 0x00U, 0xFCU, 0x00U, 0x00U,
    0x30U, 0x30U, 0xFCU, 0x30U, 0x30U, 0x00U, 0xFCU, 0x00U,
    0x60U, 0x30U, 0x18U, 0x30U, 0x60U, 0x00U, 0xFCU, 0x00U,
    0x18U, 0x30U, 0x60U, 0x30U, 0x18U, 0x00U, 0xFCU, 0x00U,
    0x0EU, 0x1BU, 0x1BU, 0x18U, 0x18U, 0x18U, 0x18U, 0x18U,
    0x18U, 0x18U, 0x18U, 0x18U, 0x18U, 0xD8U, 0xD8U, 0x70U,
    0x30U, 0x30U, 0x00U, 0xFCU, 0x00U, 0x30U, 0x30U, 0x00U,
    0x00U, 0x76U, 0xDCU, 0x00U, 0x76U, 0xDCU, 0x00U, 0x00U,
    0x38U, 0x6CU, 0x6CU, 0x38U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x18U, 0x18U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x18U, 0x00U, 0x00U, 0x00U,
    0x0FU, 0x0CU, 0x0CU, 0x0CU, 0xECU, 0x6CU, 0x3CU, 0x1CU,
    0x78U, 0x6CU, 0x6CU, 0x6CU, 0x6CU, 0x00U, 0x00U, 0x00U,
    0x70U, 0x18U, 0x30U, 0x60U, 0x78U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x3CU, 0x3CU, 0x3CU, 0x3CU, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U
};

#endif
