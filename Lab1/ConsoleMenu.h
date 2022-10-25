#pragma once

enum Input
{
	Keyboard = 1,
	FromFile = 2,
	Info = 3,
	Out = 4
};

class ConsoleMenu
{
public:
	static void Menu();
	static void PrintGreeting();
};