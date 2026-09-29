#include <iostream>
#include "calculator.h"

int main()
{
    int a = 10;
    int b = 5;

    std::cout << "a + b = " << Calculator::Add(a, b) << std::endl;
    std::cout << "a - b = " << Calculator::Sub(a, b) << std::endl;

    return 0;
}