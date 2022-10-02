#pragma once

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
	static void Menu();
	static void PrintGreeting();
};
