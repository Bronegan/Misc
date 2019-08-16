// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "calc.h"

int main()
{
	char choice;
	Calculator c;

	do {
		c.run();
		std::cout << "Run Again?" << std::endl;
		std::cin >> choice;

	} while (choice == 'y');
}

