#include <iostream>
#include <windows.h>
 
using namespace std;

int cps = 0;
bool click = false;
bool Hide = false;

void Explorer()
{
	system("cmd /c taskkill /f /im explorer.exe & start explorer.exe");
}
void Menu()
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
	system("title RuntimeBroken");
    system("cls");
    cout << "\n  Press F4 to Start or Stop!" << endl;
    cout << "  Press END change CPS!" << endl;
    cout << "  Press INSERT Hide/Show this Program!" << endl;
    cout << "  Press HOME Self_Destruct!" << endl;
    cout << "  White a CPS number:" << endl;
    cin >> cps;
	system("cls");
	cout << "\n  Press F4 to Start or Stop!" << endl;
	cout << "  Press END change CPS!" << endl;
	cout << "  Press INSERT Hide/Show this Program!" << endl;
	cout << "  Press HOME Self_Destruct!" << endl;
	cout << "  CPS: " << cps << endl;
	cout << "  Stats: OFF" << endl;
}

void Clicker()
{
    while (1)
    {
    	if(cps > 1000){
    		cps = 0;
            MessageBox(NULL, "The max CPS is 1000!", "RuntimeBroken", 0);
            Menu();
        }
        int sleeptime = (1000 + rand() % 200) / cps;
    	Sleep(1);
    	if (GetAsyncKeyState(VK_INSERT))
      {
        if (Hide == true) {
        ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
        Hide = false;
        Sleep(500);	
        }
		
        else
        if (Hide == false) {
        ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
		Hide = true;
		Sleep(500);	
        }
      }
        if (GetAsyncKeyState(VK_END))
        {
            Sleep(200);
            Menu();
        }
        if (GetAsyncKeyState(VK_F4))
        {
        if (click == true) {
        system("title RuntimeBroken");
        system("cls");
        cout << "\n  Press F4 to Start or Stop!" << endl;
        cout << "  Press END change CPS!" << endl;
        cout << "  Press INSERT Hide/Show this Program!" << endl;
        cout << "  Press HOME Self_Destruct!" << endl;
        cout << "  CPS: " << cps << endl;
        cout << "  Stats: OFF" << endl;
        click = false;
		Sleep(500); }
		
        else
        if (click == false) {
        system("title RuntimeBroken");
        system("cls");
        cout << "\n  Press F4 to Start or Stop!" << endl;
        cout << "  Press END change CPS!" << endl;
        cout << "  Press INSERT Hide/Show this Program!" << endl;
        cout << "  Press HOME Self_Destruct!" << endl;
        cout << "  CPS: " << cps << endl;
        cout << "  Stats: ON" << endl;
        click = true;
		Sleep(500); }
        
      }

        if (click == true)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(sleeptime);
        }
        if(GetAsyncKeyState(VK_HOME)){
			system("ipconfig /flushdns");
			system("cmd /c taskkill /f /im RuntimeBroken.exe & del q RuntimeBroken.exe & exit");
            MessageBox(NULL, "Self-Destruct Sucessful!", "RuntimeBroken", 0);
        }
    }
}
int main()
{
	Explorer();
    Menu();
    Clicker();
}
