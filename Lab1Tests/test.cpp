#include "pch.h"
#include "../Lab1/TextWorker.h"
#include "../Lab1/TextWorker.cpp"

TEST(TestCaseName, TestName1) {
	TextWorker tw;
	auto str = std::string("¿¿¿¿ ¿¿\n¿ ¿");
	auto strStream = std::istringstream(str);
	tw.GetAverage(strStream, 2);
	EXPECT_EQ(3.0, tw.AverageCountOfSym[0]);
    EXPECT_EQ(1.0, tw.AverageCountOfSym[1]);
}

TEST(TestCaseName, TestName2) {
	TextWorker tw;
	auto str = std::string("¿¿¿¿A ¿¿\n¿ ¿ A");
	auto strStream = std::istringstream(str);
	tw.GetAverage(strStream, 2);
	EXPECT_EQ(3.5, tw.AverageCountOfSym[0]);
	EXPECT_EQ(1.0, tw.AverageCountOfSym[1]);
}

TEST(TestCaseName, TestName3) {
	TextWorker tw;
	auto str = std::string("¿\n¿");
	auto strStream = std::istringstream(str);
	tw.GetAverage(strStream, 2);
	EXPECT_EQ(1.0, tw.AverageCountOfSym[0]);
	EXPECT_EQ(1.0, tw.AverageCountOfSym[1]);
}

TEST(TestCaseName, TestName4) {
	TextWorker tw;
	auto str = std::string("¿¿¿¿¿¿\n¿AAAAAAAAAAAAAA¿");
	auto strStream = std::istringstream(str);
	tw.GetAverage(strStream, 2);
	EXPECT_EQ(6.0, tw.AverageCountOfSym[0]);
	EXPECT_EQ(16.0, tw.AverageCountOfSym[1]);
}

TEST(TestCaseName, TestName5) {
	TextWorker tw;
	auto str = std::string("");
	auto strStream = std::istringstream(str);
	tw.GetAverage(strStream,0);
	EXPECT_EQ(0, tw.AverageCountOfSym.size());
}