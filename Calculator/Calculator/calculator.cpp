#include <iostream>
#include <cmath>
#include <vector>

#include "calculator.h"

Calculator::Calculator(int n_1, int n_2)
	:number_1(n_1), number_2(n_2)
{
	std::cout << "two number were created" << std::endl;
}

double Calculator::Addition() const
{
	return number_1 + number_2;
}

double Calculator::Difference() const
{
	return number_1 - number_2;
}

double Calculator::Multiplication() const
{
	return number_1 * number_2;
}

double Calculator::Division() const
{   
	if (number_2 != 0)
	{
		return number_1 / number_2;
	}
}

double Calculator::PowerRaising() const
{
	return pow(number_1, number_2);
}
	
int Calculator::SignsMatching() const
{   
	if (number_1 > 0 && number_2 > 0 || number_1 < 0 && number_2 < 0)
	{
		return 1;
	}
	if (number_1 == 0 && number_2 == 0)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
    
int Calculator::NOD() const
{
	if (number_1 == 0 && number_2 != 0 || number_1 == 0 && number_2 == 0 || abs(number_1) == abs(number_2))
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

int Calculator::NOK() const
{
	if (NOD() != 0)
	{
		if (number_1 * number_2 / NOD() > 0)
		{
			return -(number_1 * number_2 / NOD());
		}
		else
		{
			return number_1 * number_2 / NOD();
		}
	}
	else
	{
		return 0;
	}
}

Calculator::~Calculator()
{
	std::cout << "destructor was called" << std::endl;
}

void PrintCalculator(const std::vector<Calculator> &calculators)
{
	for (int i = 0; i < calculators.size(); i++)
	{
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "sum of two numbers = " << calculators[i].Addition() << std::endl;
		std::cout << "difference of two numbers = " << calculators[i].Difference() << std::endl;
		std::cout << "multiplication of two numbers = " << calculators[i].Multiplication() << std::endl;
		
		std::cout << "division of two numbers = " << calculators[i].Division() << std::endl;
		std::cout << "power raising of the first number  = " << calculators[i].PowerRaising() << std::endl;

		if (calculators[i].SignsMatching() == 1)
		{
			std::cout << "the signs of numbers are the same" << std::endl;
		}
		if (calculators[i].SignsMatching() == 2)
		{
			std::cout << "both numbers = 0, so we can't talk about signs" << std::endl;
		}
		if (calculators[i].SignsMatching() == 3)
		{
			std::cout << "the signs of numbers are differnt" << std::endl;
		}

		std::cout << "NOD of two numbers = " << calculators[i].NOD() << std::endl;
		std::cout << "NOK of two numbers = " << calculators[i].NOK() << std::endl;
		std::cout << "-------------------------------------" << std::endl;
	}
}

