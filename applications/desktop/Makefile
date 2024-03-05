all: desktop.bin

%.bin: main.c
	avr-gcc -mmcu=atmega644 -DF_CPU=28636360UL -Os -T ../ushell.ld ../startup.s $< ../ushell.c -o $@.elf
	avr-objcopy -O binary $@.elf $@
	cp $@ ../../bin/ushell/

.PHONY: clean
clean:
	rm -f *.bin *.map *.elf
