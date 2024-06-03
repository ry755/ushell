#include "../ushell.h"
#include <string.h>

#define APP_PAGE_SIZE 25

char apps[APP_PAGE_SIZE][13];
u8 number_of_apps = 0;

void AddApp(char *name) {
    u8 index = number_of_apps++;
    strncpy(&apps[index][0], name, 13);
    uS_BlitStrRam(&apps[index][0], 8, index * 8 + 16);
}

bool CheckAppName(char *name) {
    name += strnlen(name, 13) - 3;
    if (strncmp(name, "APP", 3) == 0)
        return true;
    else
        return false;
}

void main(void) {
    uS_BeginFrameDraw();
    uS_BlitStr(PSTR("desktop"), 0, 0);

    sd_dir_t apps_dir;
    sd_file_info_t app_info;
    uS_EnableVideo(false);
    if (!uS_OpenDir(&apps_dir, "/")) {
        uS_EnableVideo(true);
        uS_BlitStr(PSTR("failed to open / directory!"), 0, 0);
        while (true) uS_WaitFrame();
    }
    for (u8 i = 0; i < APP_PAGE_SIZE; i++) {
        memset(&apps[i][0], 0, 13);
        if (uS_ReadDir(&apps_dir, &app_info)) {
            if (CheckAppName(app_info.name))
                AddApp(app_info.name);
        } else {
            break;
        }
    }
    uS_EnableVideo(true);

    while (true) {
        if (uS_GetMouseButtons() & LEFT_MOUSE_BUTTON) {
            uS_EnableVideo(false);
            u8 app_id = uS_GetMouseY() / 8 - 2;
            uS_Exec(apps[app_id]);
            uS_EnableVideo(true);
            uS_BlitStr(PSTR("failed to execute application!"), 0, 0);
            uS_BlitStrRam(apps[app_id], 248, 0);
        }

        uS_WaitFrame();
    }
}
