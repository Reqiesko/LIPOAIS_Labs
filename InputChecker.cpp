#include "InputChecker.h"

using namespace std;

int InputChecker::numberCheck()
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

bool InputChecker::errorCheck() {
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Пожалуйста введите цифру из ниже указанных! " << endl;
		return false;
	}
	return true;
}
