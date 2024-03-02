#!/bin/bash

mkdir -p ../bin/ushell/

function build {
    avr-as -mmcu=atmega644 $1.s -o $1.elf
    avr-ld -Map $1.map --defsym=__TEXT_REGION_ORIGIN__=0x8000 -o $1.out $1.elf
    avr-objcopy -O binary $1.out $1.bin
    cp $1.bin ../bin/ushell/
}

build test
build key_test
build paint
