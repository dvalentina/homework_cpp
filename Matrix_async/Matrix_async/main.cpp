#include <iostream>
#include "matrix.h"
#include "profile.h"

int main()
{ 
    Matrix matrix1(4000, 1000);
    for (size_t i = 0; i < matrix1.GetHeight(); ++i)
    {
        for (size_t j = 0; j < matrix1.GetWidth(); ++j)
        {
            matrix1.SetValue(i, j, 1);
        }
    }

    Matrix matrix2(1000, 6000);
    for (size_t i = 0; i < matrix2.GetHeight(); ++i)
    {
        for (size_t j = 0; j < matrix2.GetWidth(); ++j)
        {
            matrix2.SetValue(i, j, 2);
        }
    }

    {LOG_DURATION("time")
        Matrix result = matrix1 * matrix2;
    }
    return 0;
}