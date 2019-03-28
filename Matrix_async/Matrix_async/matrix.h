#pragma once
#include <iostream>
#include <vector>
#include <istream>
#include <ostream>


class Matrix
{
	friend std::istream& operator>>(std::istream& input_stream, Matrix& matrix);

public:
    Matrix();
	Matrix(const size_t height, const size_t width);

	size_t GetHeight() const;
	size_t GetWidth() const;

	int GetValue(const size_t height_index, const size_t width_index) const;
	void SetValue(const size_t height_index, const size_t width_index,
		const int value);
    std::vector<std::vector<int>> GetData() const;
    void SetData(std::vector<std::vector<int>> data);
	Matrix Transpose() const;

	Matrix operator*(const Matrix& rhs);
    Matrix operator+(const Matrix& rhs);

private:
	std::vector<std::vector<int>> data_;
};



std::istream& operator >> (std::istream& input_stream, Matrix& matrix);
std::ostream& operator<<(std::ostream& output_stream, const Matrix& matrix);

