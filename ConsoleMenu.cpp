#include "ConsoleMenu.h"
#include "InputChecker.h"
#include "TextWorker.h"

void ConsoleMenu::menu()
{
	InputChecker checker;
	TextWorker worker;
	int var;
	while (true) {
		cout << endl;
		cout << "Меню" << endl;
		cout << "Выберите вариант: " << endl;
		cout << "1. Ввести текст с клавиатуры." << endl;
		cout << "2. Ввести текст из файла." << endl;
		cout << "3. Показать информацию о программе." << endl;
		cout << "4. Провести тестирование. " << endl;
		cout << "5. Выйти из программы. " << endl;
		cout << endl;
		var = checker.numberCheck();
		if (!checker.errorCheck()) {
			continue;
		}
		cin.ignore(INT_MAX, '\n');
		switch (var) {
		case keyboard: {
			worker.keyboardInput();
			//worker.getAverage();
			break;
		}
		case from_file: {
			worker.fileInput();
			break;
		}
		case info: {
			printGreeting();
			break;
		}
		case test: {
			//module_tests();
			//menu();
			break;
		}
		case out: {
			cout << "Программа завершена." << endl;
			break;
		}
		default: {
			cout << "Повторите ввод! " << endl;
		}
		}
		cin.clear();
		if (var == out) {
			break;
		}
	}
}

void ConsoleMenu::printGreeting()
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
