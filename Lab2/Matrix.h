#pragma once
#include <vector>
#include <stdexcept>

template <typename ValueInMatrix>
class Matrix
{
public:
	Matrix<ValueInMatrix>(unsigned countOfRows, unsigned countOfCols);
	Matrix<ValueInMatrix>(const Matrix& m);

	Matrix<ValueInMatrix>& operator= (const Matrix<ValueInMatrix>& m);

	ValueInMatrix& operator() (unsigned row, unsigned col);        // Subscript operators often come in pairs
	ValueInMatrix  operator() (unsigned row, unsigned col) const;  // Subscript operators often come in pairs

	template<typename RightValueInMatrix>
	Matrix<ValueInMatrix> operator * (const Matrix<RightValueInMatrix>* rMatrix);

	template<typename RightValueInMatrix>
	Matrix<ValueInMatrix> operator + (const Matrix<RightValueInMatrix>* rMatrix);

	template<typename RightValueInMatrix>
	Matrix<ValueInMatrix> operator - (const Matrix<RightValueInMatrix>* rMatrix);

	std::vector<ValueInMatrix> operator [] (unsigned row);

	unsigned GetRowCount() const;
	unsigned GetColCount() const;

	static Matrix<int> GenerateIdentityMatrix(int size);

	Matrix<ValueInMatrix>* GetInverted();

private:
	std::vector<std::vector<ValueInMatrix>> Data;
	std::vector<ValueInMatrix> data_;
	unsigned Cols, Rows;
};

template <typename ValueInMatrix>
Matrix<ValueInMatrix>::Matrix<ValueInMatrix>(unsigned rows, unsigned cols) : Rows(rows), Cols(cols)
{
	if (rows == 0 || cols == 0)
		throw std::invalid_argument("Matrix constructor has 0 size");
	data_ = std::vector<ValueInMatrix>(Rows * Cols);
}

template <typename MatrixType>
Matrix<MatrixType>::Matrix<MatrixType>(const Matrix<MatrixType>& matrix)
{
	Rows = matrix.Rows;
	Cols = matrix.Cols;
	data_ = std::vector<MatrixType>(Rows * Cols);
	for (int i = 0; i < Rows * Cols; ++i)
	{
		data_[i] = matrix.data_[i];
	}
	data_ = matrix.data_;
}

template <typename ValueInMatrix>
Matrix<ValueInMatrix>& Matrix<ValueInMatrix>::operator=(const Matrix<ValueInMatrix>& m)
{
	Rows = m.GetRowCount();
	Cols = m.GetColCount();
	data_ = std::vector<ValueInMatrix>(Rows * Cols);
	for (int i = 0; i < Rows; ++i)
	{
		for (int j = 0; j < Cols; ++j)
		{
			this->operator()(i, j) = m(i, j);
		}
	}
	return *this;
}

template <typename ValueInMatrix>
template <typename RightValueInMatrix>
Matrix<ValueInMatrix> Matrix<ValueInMatrix>::operator*(const Matrix<RightValueInMatrix>* rMatrix)
{
	if (this->GetColCount() != rMatrix->GetRowCount())
	{
		throw std::invalid_argument(
			" оличество столбцов левой матрицы должно равн€тьс€ количеству строк правой матрицы");
	}
	auto A = this;
	auto B = rMatrix;
	auto C = Matrix<ValueInMatrix>(A->GetRowCount(), B->GetColCount());
	auto p = this->GetColCount();
	for (int i = 0; i < C.GetRowCount(); ++i)
	{
		for (int j = 0; j < C.GetColCount(); ++j)
		{
			ValueInMatrix cij = 0;
			for (int k = 0; k < p; ++k)
			{
				cij = cij + A->operator()(i, k) * B->operator()(k, j);
			}
			C(i, j) = cij;
		}
	}
	return C;
}

template <typename ValueInMatrix>
template <typename RightValueInMatrix>
Matrix<ValueInMatrix> Matrix<ValueInMatrix>::operator+(const Matrix<RightValueInMatrix>* rMatrix)
{
	if (this->GetColCount() != rMatrix->GetColCount() || this->GetRowCount() != rMatrix->GetRowCount())
	{
		throw std::invalid_argument("ћатрицы должны быть одинаковые по размеру!");
	}
	auto C = Matrix(this->GetRowCount(), this->GetColCount());
	for (int i = 0; i < this->GetRowCount(); ++i)
	{
		for (int j = 0; j < this->GetColCount(); ++j)
		{
			C(i, j) = this->operator()(i, j) + rMatrix->operator()(i, j);
		}
	}
	return C;
}

template <typename ValueInMatrix>
template <typename RightValueInMatrix>
Matrix<ValueInMatrix> Matrix<ValueInMatrix>::operator-(const Matrix<RightValueInMatrix>* rMatrix)
{
	if (this->GetColCount() != rMatrix->GetColCount() || this->GetRowCount() != rMatrix->GetRowCount())
	{
		throw std::invalid_argument("ћатрицы должны быть одинаковые по размеру!");
	}
	Matrix<ValueInMatrix> C = Matrix(this->GetRowCount(), this->GetColCount());
	for (int i = 0; i < this->GetRowCount(); ++i)
	{
		for (int j = 0; j < this->GetColCount(); ++j)
		{
			C(i, j) = this->operator()(i, j) - rMatrix->operator()(i, j);
		}
	}
	return C;
}

template <typename ValueInMatrix>
Matrix<ValueInMatrix>* Matrix<ValueInMatrix>::GetInverted()
{
	int order = GetColCount();

	// копируем начальную матрицу
	auto augmentedMatrix = Matrix(order, order * 2);
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			augmentedMatrix(i, j) = operator()(i, j);
		}
	}
	// заполн€ем правую часть расширенной матрицы единичной матрицей
	for (int i = 0; i < order; i++) {
		for (int j = order; j < 2 * order; j++) {
			if (j == (i + order))
			{
				augmentedMatrix(i, j) = 1;
			}
			else
			{
				augmentedMatrix(i, j) = 0;
			}
		}
	}
	for (int nrow = 0; nrow < order; ++nrow)
	{
		auto divider = augmentedMatrix(nrow, nrow);
		for (int i = 0; i < order * 2; ++i)
		{
			augmentedMatrix(nrow, i) = augmentedMatrix(nrow, i) / divider;
		}

		for (int lowerRow = nrow + 1; lowerRow < order; ++lowerRow)
		{
			auto factor = augmentedMatrix(lowerRow, nrow);
			for (int i = 0; i < order * 2; ++i)
			{
				augmentedMatrix(lowerRow, i) = augmentedMatrix(lowerRow, i) - factor * augmentedMatrix(nrow, i);
			}
		}
	}
	for (int col = order - 1; col >= 1; --col)
	{
		for (int row = col - 1; row >= 0; --row)
		{
			auto factor = augmentedMatrix(row, col);
			for (int i = 0; i < order * 2; ++i)
			{
				augmentedMatrix(row, i) = augmentedMatrix(row, i) - augmentedMatrix(col, i) * factor;
			}
		}
	}
	auto result = new Matrix(order, order);
	for (int i = 0; i < order; ++i)
	{
		for (int j = 0; j < order; ++j)
		{
			result->operator()(i, j) = augmentedMatrix(i, order + j);
		}
	}
	return result;
}

template <typename ValueInMatrix>
std::vector<ValueInMatrix> Matrix<ValueInMatrix>::operator[](unsigned row)
{
	return this->Data[row];
}

template <typename ValueInMatrix>
unsigned Matrix<ValueInMatrix>::GetRowCount() const
{
	return Rows;
}

template <typename ValueInMatrix>
unsigned Matrix<ValueInMatrix>::GetColCount() const
{
	return Cols;
}

template <typename ValueInMatrix>
Matrix<int> Matrix<ValueInMatrix>::GenerateIdentityMatrix(int size)
{
	Matrix<int> matrix(size, size);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix(i, j) = 0;
		}
	}
	for (int i = 0; i < size; ++i)
	{
		matrix(i, i) = 1;
	}
	return matrix;
}

template <typename ValueInMatrix>
ValueInMatrix& Matrix<ValueInMatrix>::operator()(unsigned row, unsigned col)
{
	if (row >= Rows || col >= Cols)
		throw std::invalid_argument("Matrix subscript out of bounds");
	return data_[Cols * row + col];
}

template <typename ValueInMatrix>
ValueInMatrix Matrix<ValueInMatrix>::operator()(unsigned row, unsigned col) const
{
	if (row >= Rows || col >= Cols)
		throw std::invalid_argument("const Matrix subscript out of bounds");
	return data_[Cols * row + col];
}