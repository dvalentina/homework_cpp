#pragma once

#include <iostream>
#include <cmath>
#include <vector>

class Calculator
{
public:
	Calculator(int n_1, int n_2);
	virtual ~Calculator();

	double Addition() const;
	double Difference() const;
	double Multiplication() const;
	double Division() const;
	double PowerRaising() const;
	int SignsMatching() const;

	int NOD() const;
	int NOK() const;

private:
	int number_1;
	int number_2;
};

void PrintCalculator(const std::vector<Calculator> &calculators);