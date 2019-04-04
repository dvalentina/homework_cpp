#include "matrix.h"
#include "profile.h"
#include <vector>
#include <stdexcept>
#include <utility>
#include <cassert>
#include <future>

std::istream& operator>>(std::istream& input_stream, Matrix& matrix)
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

Matrix::Matrix()
{
    std::vector<int> matrix_row;
    data_.push_back(matrix_row);
}

Matrix::Matrix(const size_t height, const size_t width)
{
    data_.reserve(height);
    if (width > 0)
    {
        for (size_t i = 0; i < height; ++i)
        {
            std::vector<int> matrix_row(width);
            data_.push_back(std::move(matrix_row));
        }
    }
}

size_t Matrix::GetHeight() const
{
    return data_.size();
}

size_t Matrix::GetWidth() const
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

int Matrix::GetValue(const size_t height_index, const size_t width_index) const
{
    return data_[height_index][width_index];
}

void Matrix::SetValue(const size_t height_index, const size_t width_index,
    const int value)
{
    data_[height_index][width_index] = value;
}

std::vector<std::vector<int>> Matrix::GetData() const
{
    return data_;
}

void Matrix::SetData(std::vector<std::vector<int>> data)
{
    this->data_ = data;
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

Matrix MultiplicateMatrices(const Matrix& lhs, const Matrix& rhs, const size_t begin_height_pos, const size_t end_height_pos)
{
    assert(lhs.GetWidth() == rhs.GetHeight());
    Matrix rhs_transposed = rhs.Transpose();
    Matrix result(lhs.GetHeight(), rhs.GetWidth());
    for (size_t i = begin_height_pos; i < end_height_pos; ++i)
    {
        for (size_t j = 0; j < result.GetWidth(); ++j)
        {
            int value = 0;
            size_t length = lhs.GetWidth();
            for (size_t k = 0; k < length; ++k)
            {
                value += lhs.GetValue(i, k) * rhs_transposed.GetValue(j, k);
            }
            result.SetValue(i, j, value);
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& rhs)
{
    if (this->GetWidth() != rhs.GetHeight())
    {
        throw std::logic_error("Multiplying matrices of incorrect sizes");
    }

    Matrix result(this->GetHeight(), rhs.GetWidth());

    //sync not chance-friendly
    for (size_t i = 0; i < result.GetHeight(); ++i)
    {
        for (size_t j = 0; j < result.GetWidth(); ++j)
        {
            int new_value = 0;
            for (size_t k = 0; k < this->GetWidth(); ++k)
            {
                new_value += this->GetValue(i, k) * rhs.GetValue(k, j);
            }
            result.SetValue(i, j, new_value);
        }
    }

    //sync cache-friendly
    //result = MultiplicateMatrices(*this, rhs, 0, this->GetHeight());
    

    //async cache-friendly
    /*const size_t threads_count = 4;
    std::vector<std::future<Matrix>> partials;
    partials.reserve(threads_count);
    const size_t height_part_size = (size_t)(this->GetHeight() / threads_count);

    for (size_t i = 0; i < threads_count; ++i)
    {
        const size_t begin_height_pos = i * height_part_size;
        const size_t end_height_pos = (i + 1 == threads_count) ?
            this->GetHeight() : (i + 1) * height_part_size;
        std::future<Matrix> partial_matrix_multiplication = std::async(
            std::launch::async,
            MultiplicateMatrices, *this, rhs, begin_height_pos, end_height_pos
        );
        partials.push_back(std::move(partial_matrix_multiplication));
    }
    std::cerr << "All threads started" << std::endl;

    for (size_t i = 0; i < threads_count; ++i)
    {
        std::cerr << "Waiting thread #" << i << std::endl;
        result = result + partials[i].get();
    }*/
    
    return result;
}

Matrix Matrix::operator+(const Matrix& rhs)
{
    assert(this->GetHeight() == rhs.GetHeight());
    assert(this->GetWidth() == rhs.GetWidth());
    Matrix result(this->GetHeight(), rhs.GetWidth());
    for (size_t i = 0; i < this->GetHeight(); ++i)
    {
        for (size_t j = 0; j < this->GetWidth(); ++j)
        {
            result.SetValue(i, j, this->GetValue(i, j) + rhs.GetValue(i, j));
        }
    }
    return result;
}

