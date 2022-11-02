#pragma once
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Matrix.h"

template<typename ValueInMatrix>
Matrix<ValueInMatrix> MakeMatrix(int order);

template<typename ValueInMatrix>
Matrix<ValueInMatrix> MakeLeftResidualMatrix(Matrix<ValueInMatrix>* initial, Matrix<ValueInMatrix>* inverted);

template<typename ValueInMatrix>
Matrix<ValueInMatrix> MakeRightResidualMatrix(Matrix<ValueInMatrix>* initial, Matrix<ValueInMatrix>* inverted);

template<typename ValueInMatrix>
Matrix<ValueInMatrix> MakeMatrix(int order)
{
	Matrix<ValueInMatrix> matrix(order, order);
	for (int i = 0; i < order; ++i)
	{
		for (int j = 0; j < order; ++j)
		{
			matrix(i, j) = 1 / (static_cast<ValueInMatrix>(i + 1) + j + 1 - 1);
		}
	}
	return matrix;
}

template<typename ValueInMatrix>
Matrix<ValueInMatrix> MakeLeftResidualMatrix(Matrix<ValueInMatrix>* initial, Matrix<ValueInMatrix>* inverted)
{
	Matrix<int> identity = Matrix<ValueInMatrix>::GenerateIdentityMatrix(initial->GetColCount());
	Matrix<ValueInMatrix> res = ((*inverted) * initial) - &identity;
	return res;
}

template<typename ValueInMatrix>
Matrix<ValueInMatrix> MakeRightResidualMatrix(Matrix<ValueInMatrix>* initial, Matrix<ValueInMatrix>* inverted)
{
	Matrix<int> identity = Matrix<ValueInMatrix>::GenerateIdentityMatrix(initial->GetColCount());
	Matrix<ValueInMatrix> res = ((*initial) * inverted) - &identity;
	return res;
}

template<typename ValueInMatrix>
double GetRowNorm(Matrix<ValueInMatrix>* residualMatrix)
{
	auto order = residualMatrix->GetRowCount();
	std::vector<ValueInMatrix> sumOfRow = std::vector<ValueInMatrix>(order);
	for (int i = 0; i < order; ++i)
	{
		sumOfRow[i] = 0;
		for (int j = 0; j < order; ++j)
		{
			auto elem = residualMatrix->operator()(i, j);
			if (elem < 0)
			{
				elem = elem * -1;
			}
			sumOfRow[i] = sumOfRow[i] + elem;
		}
	}
	auto max = sumOfRow[0];
	for (int i = 0; i < order; ++i)
	{
		if (sumOfRow[i] > max)
		{
			max = sumOfRow[i];
		}
	}
	return static_cast<double>(max);
}