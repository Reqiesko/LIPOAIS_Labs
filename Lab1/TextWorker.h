#pragma once

#include <string>
#include <iostream>
#include <vector>

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
	void GetClearText();
	int GetLinesCount();
	static bool IsFilePathGood(std::string path);
	void FileInput();
	void GetAverage(std::istream& is, int n);
	void AskToSaveData(std::string data, std::string nameOfData);
	void SaveData(std::string data);
	std::string ResultAsString() const;
//private:
	std::string Text;
	std::vector<double> AverageCountOfSym;
};
