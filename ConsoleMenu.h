#pragma once
#include "InputChecker.h"

using namespace std;

enum Input
{
	Keyboard = 1,
	FromFile = 2,
	Info = 3,
	Test = 4,
	Out = 5
};

class ConsoleMenu
{
public:
	void Menu();
	void PrintGreeting();
};
