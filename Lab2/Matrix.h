#pragma once
#include <vector>

template <typename ValueInMatrix>
class Matrix
{
public:
	Matrix(unsigned countOfRows, unsigned countOfCols);

	Matrix<ValueInMatrix>& operator= (const Matrix<ValueInMatrix>& m);
	template<typename RightValueInMatrix>
	Matrix<ValueInMatrix> operator * (const Matrix<RightValueInMatrix>& rMatrix);

	template<typename rightMatrixType>
	Matrix<ValueInMatrix> operator + (const Matrix<rightMatrixType>& rMatrix);

	template<typename rightMatrixType>
	Matrix<ValueInMatrix> operator - (const Matrix<rightMatrixType>& rMatrix);

	std::vector<ValueInMatrix> operator [] (unsigned row);

	unsigned getRowCount() const;
	unsigned getColCount() const;

	Matrix<ValueInMatrix> GetInverted();
private:
	std::vector<std::vector<ValueInMatrix>> Data;
	unsigned Cols, Rows;
};

template <typename ValueInMatrix>
Matrix<ValueInMatrix>& Matrix<ValueInMatrix>::operator=(const Matrix<ValueInMatrix>& m)
{

}

template <typename ValueInMatrix>
template <typename RightValueInMatrix>
Matrix<ValueInMatrix> Matrix<ValueInMatrix>::operator*(const Matrix<RightValueInMatrix>& rMatrix)
{
}

template <typename ValueInMatrix>
template <typename rightMatrixType>
Matrix<ValueInMatrix> Matrix<ValueInMatrix>::operator+(const Matrix<rightMatrixType>& rMatrix)
{
}

template <typename ValueInMatrix>
template <typename rightMatrixType>
Matrix<ValueInMatrix> Matrix<ValueInMatrix>::operator-(const Matrix<rightMatrixType>& rMatrix)
{
}

template <typename ValueInMatrix>
std::vector<ValueInMatrix> Matrix<ValueInMatrix>::operator[](unsigned row)
{
	return this->Data[row];
}

template <typename ValueInMatrix>
unsigned Matrix<ValueInMatrix>::getRowCount() const
{
	return Rows;
}

template <typename ValueInMatrix>
unsigned Matrix<ValueInMatrix>::getColCount() const
{
	return Cols;
}

