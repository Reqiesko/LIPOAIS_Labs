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
		std::string text;
		std::string result;
		void keyboardInput();
		bool isFilePathGood(std::string filename);
		void fileInput();
		void getAverage(std::istream& is, int n);
		void askToSaveData(std::string data, std::string nameOfData);
		void saveData(std::string data);
};
