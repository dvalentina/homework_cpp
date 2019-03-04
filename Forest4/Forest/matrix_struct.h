#pragma once
#include <iostream>
#include <vector>
#include <istream>
#include <ostream>

struct Tree;
enum tree_state : int;

class Matrix
{
    friend std::ostream& operator<< (std::ostream& output_stream, Matrix& matrix);

public:
    Matrix(const size_t height, const size_t width);

    size_t GetHeight() const;
    size_t GetWidth() const;

    tree_state GetState(const size_t height_index, const size_t width_index) const;
    int GetElapsedTime(const size_t height_index, const size_t width_index) const;
    void SetState(const size_t height_index, const size_t width_index, const tree_state new_state);
    void SetElapsedTime(const size_t height_index, const size_t width_index, const int new_elapsed_time);

    Matrix Transpose() const;


private:
    std::vector<std::vector<Tree>> data_;
};


std::ostream& operator<<(std::ostream& output_stream, const Matrix& matrix);

