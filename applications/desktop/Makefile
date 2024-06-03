all: desktop.app

%.app: main.c
	avr-gcc -mmcu=atmega644 -DF_CPU=28636360UL -Os -T ../ushell.ld ../startup.s $< ../ushell.c -o $@.elf
	avr-objcopy -O binary $@.elf $@
	cp $@ ../../bin/

.PHONY: clean
clean:
	rm -f *.app *.map *.elf
