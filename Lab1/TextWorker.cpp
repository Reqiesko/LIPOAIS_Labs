#include "TextWorker.h"
#include <filesystem>
#include <fstream>


using namespace std::filesystem;
using namespace std;


bool TextWorker::FileExist(const string path) const
{
	return exists(path);
}

void TextWorker::GetAverage(istream& is, const int n)
{
	this->AverageCountOfSym = std::vector<double>(n);
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
			wordsLength += static_cast<int>(line.length());
		}
		this->AverageCountOfSym[count - 1] = (wordsLength * 1.0) / wordsCount;
		return wordsCount ? static_cast<double>(wordsLength) / wordsCount : 0.0;
	});
};

void TextWorker::KeyboardInput()
{
	cout << "���� �������� ������ � �������, ��� ���������� ����� ������� ctrl+x" << endl;
	getline(cin, this->Text, '\030');
	const int linesCount = static_cast<int>(ranges::count(this->Text, '\n'));
	auto test = istringstream(this->Text);
	GetAverage(test, linesCount);
	const auto result = this->ResultAsString();
	cout << result << endl;
	AskToSaveData(this->Text, "������� ������");
	AskToSaveData(result, "���������");
}

bool TextWorker::IsFilePathGood(const string path)
{
	const size_t found = path.find_last_of('\\');
	const size_t point = path.find_last_of('.');
	const size_t base = point - found - 1;
	const string baseFilenameStr = path.substr(found + 1, base);
	const char* baseFilenameChar = baseFilenameStr.c_str();
	if (!_strcmpi(baseFilenameChar, "con"))
	{
		return false;
	}
	return true;
}

void TextWorker::FileInput()
{
	string filePath;
	cout << "������� ���� � �����: " << endl;
	getline(cin, filePath);
	ifstream fileRead(filePath);
	if (IsFilePathGood(filePath) && fileRead.is_open())
	{
		this->Text.clear();
		try
		{
			int linesCount = 0;
			string lines;
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
	if (data.empty())
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
		cout << "���������� ������� ����" << endl;
	}
}

std::string TextWorker::ResultAsString() const
{
	string res;
	for (size_t i = 0; i < AverageCountOfSym.size(); ++i)
	{
		res += std::string(
			"\n������� �������������� � ������ �" + to_string(i) + " " + to_string(AverageCountOfSym[i]));
	}
	return res;
}
