#include "TextWorker.h"
#include <filesystem>
#include <regex>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std::filesystem;
using namespace std;


bool TextWorker::FileExist(const string path) const
{
	return exists(path);
}

void TextWorker::GetAverage(istream& is, const int n)
{
	this->AverageCountOfSym = std::vector<double>(n);
	//this->result = "";
	vector<double> avgPerLine;
	int count = 0;
	generate_n(back_inserter(avgPerLine), n, [&]()
	{
		string line;
		getline(is, line);
		count++;
		auto words = istringstream(line);
		int wordsCount = 0;
		int wordsLength = 0;
		while (words >> line)
		{
			wordsCount++;
			wordsLength += line.length();
		}
		this->AverageCountOfSym[count - 1] = (wordsLength * 1.0) / wordsCount;
		//this->result +=  std::string("\n������� �������������� � ������ �" + to_string(count) +  " " + to_string((words_length*1.0) / words_count));
		return wordsCount ? static_cast<double>(wordsLength) / wordsCount : 0.0;
	});
	//cout << this->result;
	//result= accumulate(avgPerLine.cbegin(), avgPerLine.cend(), 0.0) / avgPerLine.size();
};

void TextWorker::KeyboardInput()
{
	cout << "���� �������� ������ � �������, ��� ���������� ����� ������� ctrl+x" << endl;
	getline(cin, this->Text, '\030');
	int linesCount = count(this->Text.begin(), this->Text.end(), '\n');
	auto test = istringstream(this->Text);
	GetAverage(test, linesCount);
	auto result = this->ResultAsString();
	cout << result << endl;
	AskToSaveData(this->Text, "������� ������");
	AskToSaveData(result, "���������");
}

bool TextWorker::IsFilePathGood(string path)
{
	const size_t found = path.find_last_of('\\');
	const size_t point = path.find_last_of('.');
	const size_t base = point - found - 1;
	const string baseFilenameStr = path.substr(found + 1, base);
	const char* baseFilenameChar = baseFilenameStr.c_str();
	//ofstream file(path, ios::app);
	if (!_strcmpi(baseFilenameChar, "con"))
	{
		return false;
	}
	/*if (!filesystem::is_regular_file(path))
	{
	    return false;
	}
	file.close();*/
	return true;
}

void TextWorker::FileInput()
{
	string filePath, lines;
	int linesCount = 0;
	cout << "������� ���� � �����: " << endl;
	getline(cin, filePath);
	ifstream fileRead(filePath);
	if (IsFilePathGood(filePath) && fileRead.is_open())
	{
		this->Text.clear();
		try
		{
			while (getline(fileRead, lines))
			{
				this->Text += lines + '\n';
				linesCount++;
			}
			cout << '\n' << "������ �� �����: " << '\n' << this->Text << endl;
			auto test = istringstream(this->Text);
			GetAverage(test, linesCount);
		}
		catch (string ex)
		{
			cout << ex << endl;
		}
		auto result = this->ResultAsString();
		cout << result << endl;
		AskToSaveData(this->Text, "������� ������");
		AskToSaveData(result, "���������");
	}
	else
	{
		cout << "������!" << endl;
	}
}

void TextWorker::AskToSaveData(std::string data, std::string nameOfData)
{
	while (true)
	{
		string answer;
		cout << "\n��������� " + nameOfData + " � ����? | ��/���" << endl;
		cin >> answer;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		if (answer == "��")
		{
			this->SaveData(data);
			return;
		}
		if (answer == "���")
		{
			return;
		}
	}
}

void TextWorker::SaveData(std::string data)
{
	string fileName;
	ofstream out;
	if (data == "")
	{
		cout << "������ ������" << endl;
		return;
	}
	while (true)
	{
		cout << "������� ���� � �����: " << endl;
		getline(cin, fileName);
		if (IsFilePathGood(fileName))
		{
			if (FileExist(fileName))
			{
				cout << "���� �� ����! �������� �������." << endl;
				cout << "1. ������������." << endl;
				cout << "2. ������� ������ ����." << endl;
				int variant;
				while (true)
				{
					//getline(cin, variant);
					cin >> variant;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					switch (variant)
					{
					case Rewrite:
						{
							out.open(fileName);
							out << data;
							cout << "�������" << endl;
							return;
						}
					case CreateNew:
						{
							SaveData(data);
							return;
						}
					default:
						break;
					}
				}
			}
			out.open(fileName);
			out << data;
			cout << "�������" << endl;
			return;
		}

		//out.open(fileName);
		//if (isFilePathGood(fileName) && out.is_open())
		//{
		//    out << data << std::endl;
		//    cout << "�������" << endl;
		//    break;
		//}
		cout << "���������� ������� ����" << endl;
	}
}

std::string TextWorker::ResultAsString()
{
	string res = "";
	for (int i = 0; i < AverageCountOfSym.size(); ++i)
	{
		res += std::string(
			"\n������� �������������� � ������ �" + to_string(i) + " " + to_string(AverageCountOfSym[i]));
	}
	return res;
}
