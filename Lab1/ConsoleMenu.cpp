#include "ConsoleMenu.h"
#include "InputChecker.h"
#include "TextWorker.h"

void ConsoleMenu::Menu()
{
	TextWorker worker;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "����" << std::endl;
		std::cout << "�������� �������: " << std::endl;
		std::cout << "1. ������ ����� � ����������." << std::endl;
		std::cout << "2. ������ ����� �� �����." << std::endl;
		std::cout << "3. �������� ���������� � ���������." << std::endl;
		std::cout << "4. �������� ������������. " << std::endl;
		std::cout << "5. ����� �� ���������. " << std::endl;
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
				std::cout << "��������� ���������." << std::endl;
				break;
			}
		default:
			{
				std::cout << "��������� ����! " << std::endl;
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
	std::cout << "��� ��������� ������� ������� �������������� �������� ���� ���� � ������. " << std::endl;
	std::cout << std::endl;
	std::cout << "�����: ����������� �������" << std::endl;
	std::cout << "������: 494" << std::endl;
	std::cout << "������������ ������ �1" << std::endl;
	std::cout << "������� 12" << std::endl;
	std::cout << std::endl;
}
