#include "../ushell.h"

void main(void) {
    uS_BeginFrameDraw();
    uS_BlitStr(PSTR("hello desktop!"), 0, 0);
    while (1) { uS_WaitFrame(); }
}
