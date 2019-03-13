#include <iostream>
#include <cmath>
#include <vector>

#include "calculator.h"


int Calculator::Addition(const int number_1, const int number_2) const
{
	return number_1 + number_2;
}

int Calculator::Difference(const int number_1, const int number_2) const
{
	return number_1 - number_2;
}

int Calculator::Multiplication(const int number_1, const int number_2) const
{
	return number_1 * number_2;
}

int Calculator::Division(const int number_1, const int number_2) const
{   
    return number_1 / number_2;
}

int Calculator::PowerRaising(const int number_1, const int number_2) const
{
	return pow(number_1, number_2);
}
	
bool Calculator::SignsEqual(const int number_1, const int number_2) const
{   
	if (number_1 * number_2 > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
    
int Calculator::NOD(const int number_1, const int number_2) const
{
    if (number_1 == 0 && number_2 != 0)
    {
        return abs(number_2);
    }

    if (number_1 != 0 && number_2 == 0)
    {
        return abs(number_1);
    }

    else //алгоритм Евклида
    {
        int a = abs(number_1);
        int b = abs(number_2);

        while (a != b)
        {
            if (a > b)
            {
                a -= b;
            }
            else
            {
                b -= a;
            }
        }
        return a;
    }
}

int Calculator::NOK(const int number_1, const int number_2) const
{
    while (NOD(number_1, number_2) != 0 && number_1 != 0 && number_2 != 0)
    {
        if (number_1 * number_2 / NOD(number_1, number_2) > 0)
        {
            return number_1 * number_2 / NOD(number_1, number_2);
        }
        else
        {
            return -(number_1 * number_2 / NOD(number_1, number_2));
        }
    }
}



