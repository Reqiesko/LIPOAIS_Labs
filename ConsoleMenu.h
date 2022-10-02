#pragma once
#include "InputChecker.h"

using namespace std;

enum input {
	keyboard = 1,
	from_file = 2,
	info = 3,
	test = 4,
	out = 5
};

class ConsoleMenu
{
    public:
		void menu();
		void printGreeting();
};

