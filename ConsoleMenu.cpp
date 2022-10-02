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
		cout << "����" << endl;
		cout << "�������� �������: " << endl;
		cout << "1. ������ ����� � ����������." << endl;
		cout << "2. ������ ����� �� �����." << endl;
		cout << "3. �������� ���������� � ���������." << endl;
		cout << "4. �������� ������������. " << endl;
		cout << "5. ����� �� ���������. " << endl;
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
				cout << "��������� ���������." << endl;
				break;
			}
		default:
			{
				cout << "��������� ����! " << endl;
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
	cout << "��� ��������� ������� ������� �������������� �������� ���� ���� � ������. " << endl;
	cout << endl;
	cout << "�����: ����������� �������" << endl;
	cout << "������: 494" << endl;
	cout << "������������ ������ �1" << endl;
	cout << "������� 12" << endl;
	cout << endl;
}
