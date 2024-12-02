# uShell

uShell is a work-in-progress operating system for the [Uzebox game console](https://uzebox.org/).

# Images

![Photo of uShell's prototype desktop app](/docs/screenshots/photo-desktop.jpg)

![Photo of uShell's paint app](/docs/screenshots/photo-paint.jpg)

# Requirements

The uShell kernel requires a 128KB SPI RAM expansion, as well a patched version of [Jubatian's Bootloader V5](https://uzebox.org/forums/viewtopic.php?p=37689#p37689).

# Building

Simply run `make`. Ensure you have the repo submodules cloned beforehand, you can do this by either cloning the repo with `--recursive` or after cloning by running `git submodule update --init`.
To run, copy the bin/ushell.uze file and the bin/*.app files (such as desktop.app) to your Uzebox SD card.

# Known Bugs

 - Unpatched CUzebox builds will hang during SD card initialization
 - Hyperkin SNES mouse support is a bit experimental, the cursor likes to jump around the screen sometimes
