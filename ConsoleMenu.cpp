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
		cout << "����" << endl;
		cout << "�������� �������: " << endl;
		cout << "1. ������ ����� � ����������." << endl;
		cout << "2. ������ ����� �� �����." << endl;
		cout << "3. �������� ���������� � ���������." << endl;
		cout << "4. �������� ������������. " << endl;
		cout << "5. ����� �� ���������. " << endl;
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
			cout << "��������� ���������." << endl;
			break;
		}
		default: {
			cout << "��������� ����! " << endl;
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
	cout << "��� ��������� ������� ������� �������������� �������� ���� ���� � ������. " << endl;
	cout << endl;
	cout << "�����: ����������� �������" << endl;
	cout << "������: 494" << endl;
	cout << "������������ ������ �1" << endl;
	cout << "������� 12" << endl;
	cout << endl;
}
