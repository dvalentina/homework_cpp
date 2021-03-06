#include "matrix.h"
#include <vector>


std::istream& operator >> (std::istream& input_stream, Matrix& matrix)
{
	for (size_t y = 0; y < matrix.GetHeight(); y++)
	{
		for (size_t x = 0; x < matrix.GetWidth(); x++)
		{
			int temp_int = 0;
			input_stream >> temp_int;
			matrix.SetValue(y, x, temp_int);
		}
	}

	return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Matrix& matrix)
{
	for (size_t i = 0; i < matrix.GetHeight(); ++i)
	{
		output_stream << "|";
		for (size_t j = 0; j < matrix.GetWidth(); ++j)
		{
			output_stream << matrix.GetValue(i, j);
			if (j != matrix.GetWidth() - 1)
			{
				output_stream << " ";
			}
		}
		output_stream << "|" << std::endl;
	}
	return output_stream;
}

Matrix::Matrix(const size_t height, const size_t width)
{
	for (size_t i = 0; i < height; ++i)
	{
		std::vector<int> matrix_row(width);
		data_.push_back(matrix_row);
	}
}

size_t Matrix::GetHeight() const
{
	return data_.size();
}

size_t Matrix::GetWidth() const
{
	return data_[0].size();
}

int Matrix::GetValue(const size_t height_index, const size_t width_index) const
{
	return data_[height_index][width_index];
}

void Matrix::SetValue(const size_t height_index, const size_t width_index,
	const int value)
{
	data_[height_index][width_index] = value;
}

Matrix Matrix::Transpose() const
{
	Matrix transposed_matrix(this->GetWidth(), this->GetHeight());
	for (size_t i = 0; i < transposed_matrix.GetHeight(); ++i)
	{
		for (size_t j = 0; j < transposed_matrix.GetWidth(); ++j)
		{
			transposed_matrix.SetValue(i, j, this->GetValue(j, i));
		}
	}
	return transposed_matrix;
}

Matrix Matrix::operator*(const Matrix& rhs)
{
	try
	{
		if (this->GetWidth() != rhs.GetHeight())
		{
			throw 1;
		}
		Matrix composition_matrix(this->GetHeight(), rhs.GetWidth());
		for (size_t i = 0; i < composition_matrix.GetHeight(); ++i)
		{
			for (size_t j = 0; j < composition_matrix.GetWidth(); ++j)
			{
				int new_value = 0;
				for (size_t k = 0; k < this->GetWidth(); ++k)
				{
					new_value += this->GetValue(i, k) * rhs.GetValue(k, j);
				}
				composition_matrix.SetValue(i, j, new_value);
			}
		}
		return composition_matrix;
	}
	catch (int i)
	{
		std::cout << "Error " << i << ": cannot multiply due to different width of the first matrix and height of the second.";
	}
}

