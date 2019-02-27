#include <iostream>
#include "matrix_test.h"
#include "matrix.h"
#include "profile.h"

#include <cassert>

#define ASSERT_EQUAL(x, y)                                         \
    if ((x) != (y))                                                \
    {                                                              \
        std::cerr << "Assertion failed. File: " << __FILE__        \
            << " Line: " << __LINE__ << " "                        \
            << x << " != " << y << " ("                            \
            << #x << " != " << #y << ")" << std::endl;             \
        fails_count++;                                             \
    }

void TestGetHeight()
{
    std::cerr << "----------------------------" << std::endl;
    int fails_count = 0;
    {
        Matrix ordinary_matrix(10, 11);
        ASSERT_EQUAL(ordinary_matrix.GetHeight(), 10);
    }
    {
        Matrix zero_height_matrix(0, 3);
        ASSERT_EQUAL(zero_height_matrix.GetHeight(), 0);
    }
    {
        Matrix zero_width_matrix(3, 0);
        ASSERT_EQUAL(zero_width_matrix.GetHeight(), 0);
    }
    {
        Matrix zero_matrix(0, 0);
        ASSERT_EQUAL(zero_matrix.GetHeight(), 0);
    }
    if (fails_count == 0)
    {
        std::cerr << "TestGetHeight: OK" << std::endl;
    }
    else
    {
        std::cout << "TestGetHeight fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------------" << std::endl;
}

void TestGetWidth()
{
    std::cerr << "----------------------------" << std::endl;
    int fails_count = 0;
    {
        Matrix ordinary_matrix(10, 11);
        ASSERT_EQUAL(ordinary_matrix.GetWidth(), 11);
    }
    {
        Matrix zero_height_matrix(0, 3);
        ASSERT_EQUAL(zero_height_matrix.GetWidth(), 0);
    }
    {
        Matrix zero_width_matrix(3, 0);
        ASSERT_EQUAL(zero_width_matrix.GetWidth(), 0);
    }
    {
        Matrix zero_matrix(0, 0);
        ASSERT_EQUAL(zero_matrix.GetWidth(), 0);
    }
    if (fails_count == 0)
    {
        std::cerr << "TestGetWidth: OK" << std::endl;
    }
    else
    {
        std::cout << "TestGetWidth fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------------" << std::endl;
}

void TestGetValue()
{
    std::cerr << "----------------------------" << std::endl;
    Matrix matrix(5, 6);
    int fails_count = 0;
    //из начала, конца и середины
    ASSERT_EQUAL(matrix.GetValue(0, 0), 0);
    ASSERT_EQUAL(matrix.GetValue(4, 5), 0);
    ASSERT_EQUAL(matrix.GetValue(2, 1), 0);
    //а вдруг метод возвращает только нули?
    matrix.SetValue(0, 0, 1);
    ASSERT_EQUAL(matrix.GetValue(0, 0), 1);
    //не перепутаны ли столбцы и строки
    matrix.SetValue(2, 3, 2);
    ASSERT_EQUAL(matrix.GetValue(2, 3), 2);
    ASSERT_EQUAL(matrix.GetValue(3, 2), 0);
    //переписанна€ €чейка - вдруг до этого в €чейке был мусор, но удачно нужного значени€
    matrix.SetValue(2, 3, 3);
    ASSERT_EQUAL(matrix.GetValue(2, 3), 3);
    if (fails_count == 0)
    {
        std::cerr << "TestGetValue: OK" << std::endl;
    }
    else
    {
        std::cout << "TestGetValue fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------------" << std::endl;
}

void TestSetValue()
{
    std::cerr << "----------------------------" << std::endl;
    Matrix matrix(4, 5);
    matrix.SetValue(0, 0, 1);
    int fails_count = 0;
    ASSERT_EQUAL(matrix.GetValue(0, 0), 1);
    matrix.SetValue(3, 4, 10);
    ASSERT_EQUAL(matrix.GetValue(3, 4), 10);
    matrix.SetValue(3, 2, 10);
    ASSERT_EQUAL(matrix.GetValue(3, 2), 10);
    ASSERT_EQUAL(matrix.GetValue(2, 3), 0);
    matrix.SetValue(3, 2, 9);
    ASSERT_EQUAL(matrix.GetValue(3, 2), 9);
    if (fails_count == 0)
    {
        std::cerr << "TestSetValue: OK" << std::endl;
    }
    else
    {
        std::cout << "TestSetValue fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------------" << std::endl;
}

void TestTranspose()
{
    std::cerr << "----------------------------" << std::endl;
    int fails_count = 0;
    Matrix square_matrix(5, 5);
    square_matrix.SetValue(1, 1, 2);
    square_matrix.SetValue(2, 3, 23);
    square_matrix.SetValue(3, 2, 32);
    Matrix tr_square_matrix = square_matrix.Transpose();
    ASSERT_EQUAL(tr_square_matrix.GetValue(1, 1), 2);
    ASSERT_EQUAL(tr_square_matrix.GetValue(2, 3), 32);
    ASSERT_EQUAL(tr_square_matrix.GetValue(3, 2), 23);
    if (fails_count == 0)
    {
        std::cerr << "TestTranspose: OK" << std::endl;
    }
    else
    {
        std::cout << "TestTranspose fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------------" << std::endl;
}