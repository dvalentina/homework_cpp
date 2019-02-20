#include "matrix_struct.h"
#include "forest.h"
#include <vector>
#include <stdexcept>

std::ostream& operator<<(std::ostream& output_stream, const Matrix& matrix)
{
    for (size_t i = 0; i < matrix.GetHeight(); ++i)
    {
        for (size_t j = 0; j < matrix.GetWidth(); ++j)
        {
            switch (matrix.GetState(i, j))
            {
            case NORMAL_TREE:
                output_stream << "|";
                break;
            case TREE_IN_FIRE:
                output_stream << "*";
                break;
            case BURNT_TREE:
                output_stream << " ";
                break;
            }
        }
        output_stream << std::endl;
    }
    return output_stream;
}

Matrix::Matrix(const size_t height, const size_t width)
{
    for (size_t i = 0; i < height; ++i)
    {
        std::vector<Tree> matrix_row;
        for (size_t j = 0; j < width; ++j)
        {
            Tree initial_tree;
            initial_tree.curr_state = NORMAL_TREE;
            initial_tree.elapsed_time = 10;
            matrix_row.push_back(initial_tree);
        }
        data_.push_back(matrix_row);
    }
    data_[size_t(height / 2)][size_t(width / 2)].curr_state = TREE_IN_FIRE;
    data_[size_t(height / 2)][size_t(width / 2)].elapsed_time = 12;
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

tree_state Matrix::GetState(const size_t height_index, const size_t width_index) const
{
    return data_[height_index][width_index].curr_state;
}

int Matrix::GetElapsedTime(const size_t height_index, const size_t width_index) const
{
    return data_[height_index][width_index].elapsed_time;
}

void Matrix::SetState(const size_t height_index, const size_t width_index, const tree_state new_state)
{
    data_[height_index][width_index].curr_state = new_state;
}

void Matrix::SetElapsedTime(const size_t height_index, const size_t width_index, const int new_elapsed_time)
{
    data_[height_index][width_index].elapsed_time = new_elapsed_time;
}

Matrix Matrix::Transpose() const
{
    Matrix transposed_matrix(this->GetWidth(), this->GetHeight());
    for (size_t i = 0; i < transposed_matrix.GetHeight(); ++i)
    {
        for (size_t j = 0; j < transposed_matrix.GetWidth(); ++j)
        {
            transposed_matrix.SetState(i, j, this->GetState(j, i));
            transposed_matrix.SetElapsedTime(i, j, this->GetElapsedTime(j, i));
        }
    }
    return transposed_matrix;
}