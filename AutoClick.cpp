#include <iostream>
#include <windows.h>
#include <stdio.h>
 
using namespace std;

int x = 0, y = 0, cps;
bool click = false;
bool Hide = false;

void Menu()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	if (MessageBoxA(NULL,"Essa é uma versão de demostração.\nPodem existir bugs. Deseja continuar?", "AutoClick Modo de Demostração", MB_YESNO) == IDYES)
	{
        MessageBoxA(NULL,"Boa Sorte!","",MB_OK);
    }
    else
    {
        exit(0);
    }
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
	system("title AutoClick Modo de Demostração");
    system("cls");
    cout << "\n     Precione F4 para Comecar e Parar!" << endl;
    cout << "     Precione HOME para mudar o CPS!" << endl;
    cout << "     Precione INSERT Esconder a o Programa e Mostrar!" << endl;
    cout << "     Precione END para executar o Selfdestruct" << endl;
    cout << "     Digite o numero de CPS (Clicks por segundos):" << endl;
    cin >> cps;
    cout << "\n  Logs:\n" << endl;
}

void Clicker()
{
    while (1)
    {
    	Sleep(1);
    	if (GetAsyncKeyState(0x2D))
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
        if (GetAsyncKeyState(VK_HOME))
        {
            Menu();
        }
        if (GetAsyncKeyState(0x73))
        {
        if (click == true) {
        cout << "AutoClick Desativado!" << endl;
        click = false;
		Sleep(100); }
		
        else
        if (click == false) {
        cout << "AutoClick Ativado!" << endl;
        click = true;
		Sleep(100); }
        
      }

        if (click == true)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(1000 / cps);
        }
        if(GetAsyncKeyState(0x23)){
                system("ipconfig /flushdns");
                system("cmd /c taskkill /f /im AutoClick.exe & del q AutoClick.exe");
                system("cls");
                MessageBox(NULL, "Selfdestruct realizado com Sucesso!", "AutoClick Modo de Demostração", 0);
                exit(0);
            }
    }
}
int main()
{
    Menu();
    Clicker();
}
