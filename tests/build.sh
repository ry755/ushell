#!/bin/bash

mkdir -p ../bin/ushell/

function build_asm {
    avr-as -mmcu=atmega644 $1.s -o $1.elf
    avr-ld -Map $1.map -T ushell.ld -o $1.out $1.elf
    avr-objcopy -O binary $1.out $1.bin
    cp $1.bin ../bin/ushell/
}

function build_c {
    avr-gcc -mmcu=atmega644 -DF_CPU=28636360UL -Os -T ushell.ld $1.c ushell.c -o $1.elf
    avr-objcopy -O binary $1.elf $1.bin
    cp $1.bin ../bin/ushell/
}

build_asm test
build_asm key_test
build_asm paint
build_c hello
