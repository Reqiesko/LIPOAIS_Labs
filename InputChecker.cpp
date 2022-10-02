#include "InputChecker.h"

using namespace std;

int InputChecker::NumberCheck()
{
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Повторите ввод!" << endl;
	}
	return a;
}

bool InputChecker::ErrorCheck()
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Пожалуйста введите цифру из ниже указанных! " << endl;
		return false;
	}
	return true;
}
