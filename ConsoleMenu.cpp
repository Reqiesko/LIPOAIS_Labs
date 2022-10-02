#include "ConsoleMenu.h"
#include "InputChecker.h"
#include "TextWorker.h"

void ConsoleMenu::Menu()
{
	InputChecker checker;
	TextWorker worker;
	while (true)
	{
		cout << endl;
		cout << "Меню" << endl;
		cout << "Выберите вариант: " << endl;
		cout << "1. Ввести текст с клавиатуры." << endl;
		cout << "2. Ввести текст из файла." << endl;
		cout << "3. Показать информацию о программе." << endl;
		cout << "4. Провести тестирование. " << endl;
		cout << "5. Выйти из программы. " << endl;
		cout << endl;
		const int var = checker.NumberCheck();
		if (!checker.ErrorCheck())
		{
			continue;
		}
		cin.ignore(INT_MAX, '\n');
		switch (var)
		{
		case Keyboard:
			{
				worker.KeyboardInput();
				//worker.getAverage();
				break;
			}
		case FromFile:
			{
				worker.FileInput();
				break;
			}
		case Info:
			{
				PrintGreeting();
				break;
			}
		case Test:
			{
				//module_tests();
				//menu();
				break;
			}
		case Out:
			{
				cout << "Программа завершена." << endl;
				break;
			}
		default:
			{
				cout << "Повторите ввод! " << endl;
			}
		}
		cin.clear();
		if (var == Out)
		{
			break;
		}
	}
}

void ConsoleMenu::PrintGreeting()
{
	system("cls");
	cout << "Эта программа считает среднее арифметическое значений длин слов в строке. " << endl;
	cout << endl;
	cout << "Автор: Нерадовский Артемий" << endl;
	cout << "Группа: 494" << endl;
	cout << "Лабораторная работа №1" << endl;
	cout << "Вариант 12" << endl;
	cout << endl;
}
