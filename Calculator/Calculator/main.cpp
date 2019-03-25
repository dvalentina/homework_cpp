#include <vector>

#include "calculator.h"
#include "tests.h"

int main()
{
    //==============================================
    //==================TESTS=======================
    //==============================================
    TestAddition();
    TestDifference();
    TestMultiplication();
    TestDivision();
    TestPowerRaising();
    TestSignsMatching();

    TestNOD();
    TestNOK();
    //==============================================
    //================END=OF=TESTS==================
    //==============================================

    Calculator calc;

    std::cout << "sum of two numbers = " << calc.Addition(45, 60) << std::endl;
    std::cout << "difference of two numbers = " << calc.Difference(-400, 500) << std::endl;
    std::cout << "multiplication of two numbers = " << calc.Multiplication(3, 700) << std::endl;
    std::cout << "division of two numbers = " << calc.Division(5, 1) << std::endl;
    std::cout << "power raising of the first number  = " << calc.PowerRaising(0, 0) << std::endl;
    std::cout << "NOD of two numbers = " << calc.NOD(5, 10) << std::endl;
    std::cout << "NOK of two numbers = " << calc.NOK(73, 8) << std::endl;

    if (calc.SignsEqual(5, -5) == 1)
    {
        std::cout << "signs are equal" << std::endl;
    }
    else
    {
        std::cout << "signs are not equal" << std::endl;
    }

    return 0;
}
	
