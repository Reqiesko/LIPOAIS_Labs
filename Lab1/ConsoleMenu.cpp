#include "ConsoleMenu.h"
#include "InputChecker.h"
#include "TextWorker.h"

void ConsoleMenu::Menu()
{
	TextWorker worker;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "Меню" << std::endl;
		std::cout << "Выберите вариант: " << std::endl;
		std::cout << "1. Ввести текст с клавиатуры." << std::endl;
		std::cout << "2. Ввести текст из файла." << std::endl;
		std::cout << "3. Показать информацию о программе." << std::endl;
		std::cout << "4. Провести тестирование. " << std::endl;
		std::cout << "5. Выйти из программы. " << std::endl;
		std::cout << std::endl;
		const int var = InputChecker::NumberCheck();
		if (!InputChecker::ErrorCheck())
		{
			continue;
		}
		std::cin.ignore(INT_MAX, '\n');
		switch (var)
		{
		case Keyboard:
			{
				worker.KeyboardInput();
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
				break;
			}
		case Out:
			{
				std::cout << "Программа завершена." << std::endl;
				break;
			}
		default:
			{
				std::cout << "Повторите ввод! " << std::endl;
			}
		}
		std::cin.clear();
		if (var == Out)
		{
			break;
		}
	}
}

void ConsoleMenu::PrintGreeting()
{
	system("cls");
	std::cout << "Эта программа считает среднее арифметическое значений длин слов в строке. " << std::endl;
	std::cout << std::endl;
	std::cout << "Автор: Нерадовский Артемий" << std::endl;
	std::cout << "Группа: 494" << std::endl;
	std::cout << "Лабораторная работа №1" << std::endl;
	std::cout << "Вариант 12" << std::endl;
	std::cout << std::endl;
}
