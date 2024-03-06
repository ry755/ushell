#include "../ushell.h"
#include <string.h>

#define APP_PAGE_SIZE 25

char apps[APP_PAGE_SIZE][13];

void main(void) {
    uS_BeginFrameDraw();
    uS_BlitStr(PSTR("desktop"), 0, 0);

    sd_dir_t apps_dir;
    sd_file_info_t app_info;
    uS_EnableVideo(false);
    if (!uS_OpenDir(&apps_dir, "/ushell")) {
        uS_EnableVideo(true);
        uS_BlitStr(PSTR("failed to open /ushell directory!"), 0, 0);
        while (true) uS_WaitFrame();
    }
    for (u8 i = 0; i < APP_PAGE_SIZE; i++) {
        memset(&apps[i][0], 0, 13);
        if (uS_ReadDir(&apps_dir, &app_info)) {
            strncpy(&apps[i][0], app_info.name, 13);
            uS_BlitStrRam(&apps[i][0], 8, i * 8 + 16);
        } else {
            break;
        }
    }
    uS_EnableVideo(true);

    while (true) {
        if (uS_GetMouseButtons() & LEFT_MOUSE_BUTTON) {
            uS_EnableVideo(false);
            char app[21] = "/ushell/";
            u8 app_id = uS_GetMouseY() / 8 - 2;
            strcat(app, &apps[app_id][0]);
            uS_Exec(app);
            uS_EnableVideo(true);
            uS_BlitStr(PSTR("failed to execute application!"), 0, 0);
        }

        uS_WaitFrame();
    }
}
