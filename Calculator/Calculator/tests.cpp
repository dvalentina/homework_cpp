#include "tests.h"
#include "calculator.h"

#include <iostream>
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

void TestAddition()
{
    std::cerr << "------------------------\n";
    int fails_count = 0;
    Calculator calculator;
    ASSERT_EQUAL(calculator.Addition(4, 5), 9);
    ASSERT_EQUAL(calculator.Addition(5, 4), 9);
    ASSERT_EQUAL(calculator.Addition(4, 0), 4);
    ASSERT_EQUAL(calculator.Addition(-1, 2), 1);
    ASSERT_EQUAL(calculator.Addition(-1, -2), -3);
    ASSERT_EQUAL(calculator.Addition(-1, 1), 0);
    ASSERT_EQUAL(calculator.Addition(50000, 50000), 100000);
    if (fails_count == 0)
    {
        std::cerr << "TestAddition: OK" << std::endl;
    }
    else
    {
        std::cout << "TestAddition fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "------------------------\n";
}


void TestDifference()
{
    std::cerr << "------------------------\n";
    int fails_count = 0;
    Calculator calculator;
    ASSERT_EQUAL(calculator.Difference(5, 4), 1);
    ASSERT_EQUAL(calculator.Difference(4, 5), -1);
    ASSERT_EQUAL(calculator.Difference(4, 4), 0);
    ASSERT_EQUAL(calculator.Difference(4, 0), 4);
    ASSERT_EQUAL(calculator.Difference(-1, -2), 1);
    ASSERT_EQUAL(calculator.Difference(60000, 50000), 10000);
    if (fails_count == 0)
    {
        std::cerr << "TestDifference: OK" << std::endl;
    }
    else
    {
        std::cout << "TestDifference fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "------------------------\n";
}

void TestMultiplication()
{
    std::cerr << "------------------------\n";
    int fails_count = 0;
    Calculator calculator;
    ASSERT_EQUAL(calculator.Multiplication(6, 3), 18);
    ASSERT_EQUAL(calculator.Multiplication(3, 6), 18);
    ASSERT_EQUAL(calculator.Multiplication(1, 3), 3);
    ASSERT_EQUAL(calculator.Multiplication(0, 3), 0);
    ASSERT_EQUAL(calculator.Multiplication(-5, 3), -15);
    ASSERT_EQUAL(calculator.Multiplication(-1, -1), 1);
    ASSERT_EQUAL(calculator.Multiplication(40000, -40000), -1600000000);
    if (fails_count == 0)
    {
        std::cerr << "TestMultiplication: OK" << std::endl;
    }
    else
    {
        std::cout << "TestMultiplication fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "------------------------\n";
}

void TestDivision()
{
    std::cerr << "------------------------\n";
    int fails_count = 0;
    Calculator calculator;
    ASSERT_EQUAL(calculator.Division(8, 2), 4);
    ASSERT_EQUAL(calculator.Division(2, 2), 1);
    ASSERT_EQUAL(calculator.Division(2, 1), 2);
    ASSERT_EQUAL(calculator.Division(6, -2), -3);
    ASSERT_EQUAL(calculator.Division(-6, -2), 3);
    ASSERT_EQUAL(calculator.Division(0, 1), 0);
    ASSERT_EQUAL(calculator.Division(50000, 50000), 1);
    if (fails_count == 0)
    {
        std::cerr << "TestDivision: OK" << std::endl;
    }
    else
    {
        std::cout << "TestDivision fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "------------------------\n";
}

void TestPowerRaising()
{
    std::cerr << "------------------------\n";
    int fails_count = 0;
    Calculator calculator;
    ASSERT_EQUAL(calculator.PowerRaising(2, 3), 8);
    ASSERT_EQUAL(calculator.PowerRaising(2, -2), 0);
    ASSERT_EQUAL(calculator.PowerRaising(2, 1), 2);
    ASSERT_EQUAL(calculator.PowerRaising(2, 0), 1);
    ASSERT_EQUAL(calculator.PowerRaising(1, 3), 1);
    ASSERT_EQUAL(calculator.PowerRaising(0, 3), 0);
    ASSERT_EQUAL(calculator.PowerRaising(0, 0), 1);
    ASSERT_EQUAL(calculator.PowerRaising(-3, 2), 9);
    ASSERT_EQUAL(calculator.PowerRaising(-3, 3), -27);
    ASSERT_EQUAL(calculator.PowerRaising(-1, 1600000000), 1);
    ASSERT_EQUAL(calculator.PowerRaising(40000, 2), 1600000000);
    if (fails_count == 0)
    {
        std::cerr << "TestPowerRaising: OK" << std::endl;
    }
    else
    {
        std::cout << "TestPowerRaising fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "------------------------\n";
}

void TestSignsMatching()
{
    std::cerr << "------------------------\n";
    int fails_count = 0;
    Calculator calculator;
    ASSERT_EQUAL(calculator.SignsEqual(2, 3), true);
    ASSERT_EQUAL(calculator.SignsEqual(-2, -3), true);
    ASSERT_EQUAL(calculator.SignsEqual(-2, 3), false);
    ASSERT_EQUAL(calculator.SignsEqual(2, -2), false);
    ASSERT_EQUAL(calculator.SignsEqual(50000, 60000), true);
    ASSERT_EQUAL(calculator.SignsEqual(50000, -60000), false);
    ASSERT_EQUAL(calculator.SignsEqual(-50000, -60000), true);
    if (fails_count == 0)
    {
        std::cerr << "TestSignsEqual: OK" << std::endl;
    }
    else
    {
        std::cout << "TestSignsEqual fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "------------------------\n";
}

void TestNOD()
{
    std::cerr << "------------------------\n";
    int fails_count = 0;
    Calculator calculator;
    ASSERT_EQUAL(calculator.NOD(0, 2), 2);
    ASSERT_EQUAL(calculator.NOD(2, 0), 2);
    ASSERT_EQUAL(calculator.NOD(3, 2), 1);
    ASSERT_EQUAL(calculator.NOD(3, 3), 3);
    ASSERT_EQUAL(calculator.NOD(-3, 3), 3);
    ASSERT_EQUAL(calculator.NOD(-3, -3), 3);
    ASSERT_EQUAL(calculator.NOD(3, 9), 3);
    ASSERT_EQUAL(calculator.NOD(6, 20), 2);
    ASSERT_EQUAL(calculator.NOD(12, 18), 6);
    ASSERT_EQUAL(calculator.NOD(50000, 60000), 10000);
    if (fails_count == 0)
    {
        std::cerr << "TestNOD: OK" << std::endl;
    }
    else
    {
        std::cout << "TestNOD fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "------------------------\n";
}

void TestNOK()
{
    std::cerr << "------------------------\n";
    int fails_count = 0;
    Calculator calculator;
    ASSERT_EQUAL(calculator.NOK(2, 2), 2);
    ASSERT_EQUAL(calculator.NOK(-2, 2), 2);
    ASSERT_EQUAL(calculator.NOK(-2, -2), 2);
    ASSERT_EQUAL(calculator.NOK(2, 3), 6);
    ASSERT_EQUAL(calculator.NOK(6, 8), 24);
    ASSERT_EQUAL(calculator.NOK(8, 6), 24);
    ASSERT_EQUAL(calculator.NOK(1, 2), 2);
    ASSERT_EQUAL(calculator.NOK(50000, 60000), 300000);
    if (fails_count == 0)
    {
        std::cerr << "TestNOK: OK" << std::endl;
    }
    else
    {
        std::cout << "TestNOK fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "------------------------\n";
}