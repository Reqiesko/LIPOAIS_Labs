#include <iostream>
#include <Windows.h>
#include "Matrix.h"
#include "Math.h"

int TryGetIntUntilSuccess(std::string inputMessage)
{
    std::cout << inputMessage << std::endl;
    std::string inputtedString;
    getline(std::cin, inputtedString);
    try
    {
        const int i = std::stoi(inputtedString);
        return i;
    }
    catch (const std::exception&)
    {
        return TryGetIntUntilSuccess(inputMessage);
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto order = TryGetIntUntilSuccess("Введите максимальный размер матрицы");
    std::vector<std::vector<double>> norms(4);
    for (int i = 0; i < 4; ++i)
    {
        norms[i] = std::vector<double>(order);
    }
    for (int i = 0; i < order; ++i)
    {
        auto matrix = MakeMatrix<double>(i + 1);
        auto inv = matrix.GetInverted();
        auto leftResidual = MakeLeftResidualMatrix(&matrix, inv);
        auto rightResidual = MakeRightResidualMatrix(&matrix, inv);
        auto leftNorm = GetRowNorm(&leftResidual);
        auto rightNorm = GetRowNorm(&rightResidual);
        norms[0][i] = (leftNorm);
        norms[1][i] = (rightNorm);
    }
    for (int i = 0; i < order; ++i)
    {
        auto m = MakeMatrix<float>(i + 1);
        auto inv = m.GetInverted();
        auto leftResidual = MakeLeftResidualMatrix(&m, inv);
        auto rightResidual = MakeRightResidualMatrix(&m, inv);
        auto leftNorm = GetRowNorm(&leftResidual);
        auto rightNorm = GetRowNorm(&rightResidual);
        norms[2][i] = (leftNorm);
        norms[3][i] = (rightNorm);
    }

    std::vector<std::string> headers{ "Порядок", "double left", "double right", "float left", "float right" };
    //std::cout << "Џ®ап¤®Є" 
    //    << std::setw(20)
    //    << std::setw(20) << "double left"
    //    << std::setw(20) << "double right"
    //    << std::setw(20) << "float left"
    //    << std::setw(20) << "float right"
    //    << std::endl;
    for (int i = 0; i < headers.size(); ++i) {
        std::cout << headers[i] << std::setw(20);
    }
    std::cout << std::setw(0) << std::endl;
    for (int i = 0; i < order; ++i)
    {
        std::cout << i + 1 << std::setw(20);
        for (int j = 0; j < headers.size() - 1; ++j)
        {
           std::cout << std::setw(20) << norms[j][i];
        }
        std::cout << std::endl;
    }
}