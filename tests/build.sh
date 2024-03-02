#!/bin/bash

mkdir -p ../bin/ushell/

avr-as -mmcu=atmega644 test.s -o test.elf
avr-ld -Map test.map --defsym=__TEXT_REGION_ORIGIN__=0x8000 -o test.out test.elf
avr-objcopy -O binary test.out test.bin
cp test.bin ../bin/ushell/

avr-as -mmcu=atmega644 key_test.s -o key_test.elf
avr-ld -Map key_test.map --defsym=__TEXT_REGION_ORIGIN__=0x8000 -o key_test.out key_test.elf
avr-objcopy -O binary key_test.out key_test.bin
cp key_test.bin ../bin/ushell/
