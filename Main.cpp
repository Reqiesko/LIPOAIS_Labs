#include <iostream>
#include <string.h>
#include <Windows.h>
#include "TextWorker.h"
#include "ConsoleMenu.h"



using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ConsoleMenu menu;
	menu.menu();
}