#include <iostream>
#include <Windows.h>

int main()
{
    // Set the thread priority to maximum
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

    bool isButtonClicked = false;

    while (true) {
        Sleep(50);

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }

        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            if (!isButtonClicked) {
                isButtonClicked = true;
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            }
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        }
        else {
            if (isButtonClicked) {
                isButtonClicked = false;
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            }
        }
    }

    return 0;
}