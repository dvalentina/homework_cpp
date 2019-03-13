#pragma once

#include <iostream>
#include <cmath>
#include <vector>

class Calculator
{
public:
	Calculator() = default;
	virtual ~Calculator() = default;

	int Addition(const int number_1, const int number_2) const;
	int Difference(const int number_1, const int number_2) const;
	int Multiplication(const int number_1, const int number_2) const;
	int Division(const int number_1, const int number_2) const;
	int PowerRaising(const int number_1, const int number_2) const;
	bool SignsEqual(const int number_1, const int number_2) const;

	int NOD(const int number_1, const int number_2) const;
	int NOK(const int number_1, const int number_2) const;
};

