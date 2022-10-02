#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <iterator>

enum WhenFileExistVariants
{
	Rewrite = 1,
	CreateNew
};

class TextWorker
{
public:
	bool FileExist(std::string path) const;
	void KeyboardInput();
	bool IsFilePathGood(std::string filename);
	void FileInput();
	void GetAverage(std::istream& is, int n);
	void AskToSaveData(std::string data, std::string nameOfData);
	void SaveData(std::string data);
	std::string ResultAsString();
private:
	std::string Text;
	//std::string result;
	std::vector<double> AverageCountOfSym;
};
