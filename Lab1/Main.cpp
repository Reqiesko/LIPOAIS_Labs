#include <iostream>
#include <Windows.h>
#include "ConsoleMenu.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ConsoleMenu::Menu();
}
