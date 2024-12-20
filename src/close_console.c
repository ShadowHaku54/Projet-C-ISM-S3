#include <windows.h>
#include <stdlib.h>
#include "close_console.h"

void fermer_console()
{
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

    Sleep(100);

    exit(0);
}
