#ifndef calc_h
#define calc_h

#pragma once
#include <iostream>
class Calculator {
	public:
		int subtract(int a, int b) {
			return a - b;
		}
		int add(int a, int b) {
			return a + b;
		}
		int multiply(int a, int b) {
			return a * b;
		}
		int divide(int a, int b) {
			return a / b;
		}

		void run() {
			int choice, first, second;

			std::cout << "0 = Subtract, 1 = Add, 2 = Multiply, 4 = Divide, Other = End" << std::endl;
			std::cin >> choice;

			if (choice <= 4 && choice >= 0) {
				std::cout << "Please enter 2 numbers" << std::endl;
				std::cout << "First Number" << std::endl;
				std::cin >> first;
				std::cout << "Second Number" << std::endl;
				std::cin >> second;
			}

			switch (choice) {
				case 0:
					std::cout << first << " - " << second << " = " << subtract(first, second) << std::endl;
					break;
				case 1:
					std::cout << first << " + " << second << " = " << add(first, second) << std::endl;
					break;
				case 2:
					std::cout << first << " * " << second << " = " << multiply(first, second) << std::endl;
					break;
				case 3:
					std::cout << first << " / " << second << " = " << divide(first, second) << std::endl;
					break;
				default:
					std::cout << "No Selection" << std::endl;
					break;
			}
		}
};
#endif
