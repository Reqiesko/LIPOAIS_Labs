#pragma once
#include <iostream> 
#include <string> 
#include <fstream> 
#include <regex>
#include <iterator>

enum whenFileExistVariants {
	rewrite = 1,
	createNew
};
class TextWorker
{
	public:
		bool file_exist(std::string path);
		void keyboardInput();
		bool isFilePathGood(std::string filename);
		void fileInput();
		void getAverage(std::istream& is, int n);
		void askToSaveData(std::string data, std::string nameOfData);
		void saveData(std::string data);
		std::string resultAsString();
	private:
		std::string text;
		//std::string result;
		std::vector<double> averageCountOfSym;
};
