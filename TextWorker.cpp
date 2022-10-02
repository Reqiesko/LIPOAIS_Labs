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


bool TextWorker::file_exist(string path) {
    return std::filesystem::exists(path);
}

void TextWorker::getAverage(istream& is, int n) {
    this->result = "";
    vector<double> avgPerLine;
    int count = 0;
    generate_n(back_inserter(avgPerLine), n, [&]() {
        string line;
        getline(is, line);
        count++;
        auto words = istringstream(line);
        int  words_count = 0;
        int  words_length = 0;
        while (words >> line)
        {
            words_count++;
            words_length += line.length();
        }
        
        this->result +=  std::string("\n������� �������������� � ������ �" + to_string(count) +  " " + to_string((words_length*1.0) / words_count));
        return words_count ? static_cast<double>(words_length) / words_count : 0.0;
        });
    cout << this->result;
    //result= accumulate(avgPerLine.cbegin(), avgPerLine.cend(), 0.0) / avgPerLine.size();
};

void TextWorker::keyboardInput()
{
    cout << "���� �������� ������ � �������, ��� ���������� ����� ������� ctrl+x" << endl;
    getline(cin, this->text, '\030');
    int linesCount = count(this->text.begin(), this->text.end(), '\n');
    auto test = istringstream(this->text);
    getAverage(test, linesCount);
    askToSaveData(this->text, "������� ������");
    askToSaveData(this->result, "���������");
}

bool TextWorker::isFilePathGood(string path) {
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

void TextWorker::fileInput() {
    string filePath, lines;
    int linesCount = 0;
    cout << "������� ���� � �����: " << endl;
    getline(cin, filePath);
    ifstream fileRead(filePath);
    if (isFilePathGood(filePath) && fileRead.is_open())
    {
        this->text.clear();
        try {
            while (getline(fileRead, lines)) {
                this->text += lines + '\n';
                linesCount++;
            }
            cout << '\n' << "������ �� �����: " << '\n' << this->text << endl;
            auto test = istringstream(this->text);
            getAverage(test, linesCount);
        }
        catch (string ex) {
            cout << ex << endl; 
        }
        askToSaveData(this->text, "������� ������");
        askToSaveData(this->result, "���������");
    }
    else {
        cout << "������!" << endl;
    }
}

void TextWorker::askToSaveData(std::string data, std::string nameOfData) {
    while (true) {
        string answer;
        cout << "\n��������� " + nameOfData +" � ����? | ��/���" << endl;
        cin >> answer; cin.clear();
        cin.ignore(INT_MAX, '\n');
        if (answer == "��") {
            this->saveData(data);
            return;
        }
        if (answer == "���") {
            return;
        }

    }
}

void TextWorker::saveData(std::string data)
{
    string fileName;
    ofstream out;
    if (data == "") {
        cout << "������ ������" << endl;
        return;
    }
    while (true)
    {
        cout << "������� ���� � �����: " << endl;
        getline(cin, fileName);
        if (isFilePathGood(fileName))
        {
            if (file_exist(fileName)) {
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
                    case rewrite:
                    {
                        out.open(fileName);
                        out << data;
                        cout << "�������" << endl;
                        return;
                    }
                    case createNew: {
                        saveData(data);
                        return;
                    }
                    default:
                        break;
                    }
                }
            }
            else
            {
                out.open(fileName);
                out << data;
                cout << "�������" << endl;
                return;
            }
        }
        
        //out.open(fileName);
        //if (isFilePathGood(fileName) && out.is_open())
        //{
        //    out << data << std::endl;
        //    cout << "�������" << endl;
        //    break;
        //}
        else {
            cout << "���������� ������� ����" << endl;
        }
    }

}
