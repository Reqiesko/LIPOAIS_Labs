#include "InputChecker.h"
#include <iostream>


using namespace std;

int InputChecker::NumberCheck()
{
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Ошибка! Повторите ввод!" << endl;
	}
	return a;
}
