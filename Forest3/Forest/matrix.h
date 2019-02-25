#pragma once
#include <iostream>
#include <vector>
#include <istream>
#include <ostream>


template <typename T>
class Matrix
{
	friend std::istream& operator >> (std::istream& input_stream, Matrix& matrix);

public:
	Matrix(const size_t height, const size_t width);

	size_t GetHeight() const;
	size_t GetWidth() const;

	T GetValue(const size_t height_index, const size_t width_index) const;
	void SetValue(const size_t height_index, const size_t width_index,
		const T value);

	Matrix Transpose() const;

	Matrix operator*(const Matrix& rhs);

private:
	std::vector<std::vector<T>> data_;
};


template <typename T>
std::istream& operator >> (std::istream& input_stream, Matrix<T>& matrix);
template <typename T>
std::ostream& operator<<(std::ostream& output_stream, const Matrix<T>& matrix);

