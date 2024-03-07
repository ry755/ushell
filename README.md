# uShell

uShell is a work-in-progress operating system kernel for the [Uzebox game console](https://uzebox.org/). Note that this branch is currently incompatible with CUzebox.

# Images

![Photo of uShell's prototype desktop app](/docs/screenshots/photo-desktop.jpg)

![Photo of uShell's paint app](/docs/screenshots/photo-paint.jpg)

# Requirements

The uShell kernel requires a 128KB SPI RAM expansion, as well as any version of [Jubatian's Bootloader V5](https://uzebox.org/forums/viewtopic.php?t=9405).

# Building

Simply run `make`. Ensure you have the repo submodules cloned beforehand, you can do this by either cloning the repo with `--recursive` or after cloning by running `git submodule init && git submodule update`.
To run, copy the bin/ushell.uze file and the bin/ushell directory to your Uzebox SD card. uShell expects to read its application files from the /ushell directory on the SD card.

# Known Bugs

 - Unpatched CUzebox builds will hang during SD card initialization, patched builds will die with a "Startup app?" error
 - After modifying internal flash, weird behavior may occur until the system is reset
    - May be due to swapping the interrupt vectors to the bootloader section during flashing, causing memory corruption?
    - If we don't swap the interrupt vectors then it will crash due to RWW not being re-enabled by the time a video interrupt comes in
    - The bootloader's `Prog_Page` routine at 0xFFAA re-enables interrupts immediately after executing `spm`, overriding our `cli`
 - Hyperkin SNES mouse support is a bit experimental, the cursor likes to jump around the screen sometimes
