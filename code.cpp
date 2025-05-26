//#define log 1
#include "bsod.h"

int main() {
    LASTINPUTINFO lii;
    lii.cbSize = sizeof(LASTINPUTINFO);
    DWORD lastTime = 0;
    Sleep(10000);
    GetLastInputInfo(&lii);
    while (true) {
        if (GetLastInputInfo(&lii)) {
            DWORD idleTime = GetTickCount() - lii.dwTime;
            if (lastTime != lii.dwTime) {
                if (lastTime != 0) {
                    bsod();
                }
                lastTime = lii.dwTime;
            }
        }
        Sleep(100);
    }
    return 0;
}