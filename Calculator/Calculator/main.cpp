#include <vector>

#include "calculator.h"

int main()
{
	std::vector<Calculator> calculators;

	Calculator pair_of_numbers_1(-15, -5);
	calculators.push_back(pair_of_numbers_1);

	Calculator pair_of_numbers_2(0, 0);
	calculators.push_back(pair_of_numbers_2);

	PrintCalculator(calculators);
	return 0;
}
