#include "matrix.h"
#include <vector>
#include <stdexcept>

//�������� ��� �������
template <typename T>
std::istream& operator >> (std::istream& input_stream, Matrix<T>& matrix)
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

//�������� ��� �������
template <typename T>
std::ostream& operator<<(std::ostream& output_stream, const Matrix<T>& matrix)
{
	for (size_t i = 0; i < matrix.GetHeight(); ++i)
	{
		for (size_t j = 0; j < matrix.GetWidth(); ++j)
		{
			output_stream << matrix.GetValue(i, j);
			if (j != matrix.GetWidth() - 1)
			{
				output_stream << " ";
			}
		}
		output_stream << std::endl;
	}
	return output_stream;
}

template <typename T>
Matrix<T>::Matrix(const size_t height, const size_t width)
{
	for (size_t i = 0; i < height; ++i)
	{
		std::vector<T> matrix_row(width);
		data_.push_back(matrix_row);
	}
}

template <typename T>
size_t Matrix<T>::GetHeight() const
{
	return data_.size();
}

template <typename T>
size_t Matrix<T>::GetWidth() const
{
    if (data_.size() == 0)
    {
        return 0;
    }
    else
    {
        return data_[0].size();
    }
}

template <typename T>
int Matrix<T>::GetValue(const size_t height_index, const size_t width_index) const
{
	return data_[height_index][width_index];
}

template <typename T>
void Matrix<T>::SetValue(const size_t height_index, const size_t width_index,
	const T value)
{
	data_[height_index][width_index] = value;
}

template <typename T>
Matrix<T> Matrix<T>::Transpose() const
{
	Matrix<T> transposed_matrix(this->GetWidth(), this->GetHeight());
	for (size_t i = 0; i < transposed_matrix.GetHeight(); ++i)
	{
		for (size_t j = 0; j < transposed_matrix.GetWidth(); ++j)
		{
			transposed_matrix.SetValue(i, j, this->GetValue(j, i));
		}
	}
	return transposed_matrix;
}

/*� ����������� ������� �������� ������ �����?
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
{
    if (this->GetWidth() != rhs.GetHeight())
    {
        throw std::logic_error("Multiplying matrices of incorrect sizes");
    }
    Matrix<T> composition_matrix(this->GetHeight(), rhs.GetWidth());
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
}*/

