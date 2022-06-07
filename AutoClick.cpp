#include <iostream>
#include <stdlib.h>
#include <windows.h>
 
using namespace std;

int x = 0, y = 0, cps;
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
    cout << "\n  Precione F4 Inicia ou Para o Click!" << endl;
    cout << "  Precione END Trocar CPS!" << endl;
    cout << "  Precione INSERT Esconder/Mostrar esse Programa!" << endl;
    cout << "  Precione F5 Self_Destruct!" << endl;
    cout << "  Digite o numero de CPS (Clicks por segundos):" << endl;
    cin >> cps;
    cout << "\n Logs:\n" << endl;
}

void Clicker()
{
    while (1)
    {
    	Sleep(1);
    	int delay = (2000 / cps) / 1;
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
            Menu();
        }
        if (GetAsyncKeyState(VK_F4))
        {
        if (click == true) {
        cout << "Status OFF" << endl;
        click = false;
		Sleep(500); }
		
        else
        if (click == false) {
        cout << "Status ON!" << endl;
        click = true;
		Sleep(500); }
        
      }

        if (click == true)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(rand() % delay);
        }
        if(GetAsyncKeyState(VK_F5)){
                MessageBox(NULL, "AutoClick teve sucesso no selfdestruct", "RuntimeBroken", 0);
                system("ipconfig /flushdns");
                system("cmd /c taskkill /f /im RuntimeBroken.exe & del q RuntimeBroken.exe & exit");
            }
    }
}
int main()
{
	Explorer();
    Menu();
    Clicker();
}
