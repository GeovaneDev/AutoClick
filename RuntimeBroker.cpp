#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int cps = 12;
bool click = false;
bool Hide = true;

void Bypass() {
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    system("cmd /c taskkill /f /im explorer.exe & start explorer.exe");
}

void Menu() {
    system("cls");
    cout << "===============================" << endl;
    cout << "      RuntimeBroken Menu       " << endl;
    cout << "===============================" << endl;
    cout << "  Press F4: Start/Stop Clicks" << endl;
    cout << "  Press END: Change CPS" << endl;
    cout << "  Press HOME: Hide/Show Program" << endl;
    cout << "  CPS: " << cps << endl;
    cout << "  Stats: " << (click ? "ON" : "OFF") << endl;
    cout << "===============================" << endl;
}

void Clicker() {
    while (true) {
        if (GetAsyncKeyState(VK_HOME)) {
            ::ShowWindow(::GetConsoleWindow(), Hide ? SW_SHOW : SW_HIDE);
            Hide = !Hide;
            Sleep(500);
            Menu();
        }

        if (GetAsyncKeyState(VK_END)) {
            cps = 0;
            ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
            Menu();
        }

        if (GetAsyncKeyState(VK_F4)) {
            click = !click;
            Menu();
            Sleep(500);
        }

        if (click) {
            srand(static_cast<unsigned int>(time(NULL)));
            int randomFactor = rand() % 30;
            int sleeptime = (1000 / cps) / 1 + randomFactor;
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(sleeptime);
        }

        Sleep(10);
    }
}

int main() {
    Bypass();
    Menu();
    Clicker();

    return 0;
}

