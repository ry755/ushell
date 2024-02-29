#!/bin/bash

avr-as -mmcu=atmega644 test.s -o test.elf
avr-ld -Map test.map --defsym=__TEXT_REGION_ORIGIN__=0x8000 -o test.out test.elf
avr-objcopy -O binary test.out test.bin
cp test.bin ../bin/
