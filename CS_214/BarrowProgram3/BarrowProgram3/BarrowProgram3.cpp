//-----------------------------------------------------------------------------------
// File:					BarrowProgram3.cpp
// Purpose:					Performs Factorial and Fibonacci Calculations Recursively
// Programming Language:	C++
// Author:					Mason Barrow
// Date:					September 2020
//-----------------------------------------------------------------------------------

#include <iostream>

using namespace std;

int factorial(int n);
int fibonacci(int n);

int main() {
	bool choice;
	int input;

	cout << "Would you like to calculate the Factorial (0) or the Fibonacci (1)? ";
	cin >> choice;
	cout << "What value would you like to calculate? ";
	cin >> input;

	if (choice) {
		while (input < 0 || input >= 48) {
			cout << "Value for fibonacci must be an integer between 0 and 47. Please try again: ";
			cin >> input;
		}
		unsigned int answer = fibonacci(input);
		cout << answer << endl;
	}
	else {
		while (input < 0 || input >= 13) {
			cout << "Value for factorial must be an integer between 0 and 12. Please try again: ";
			cin >> input;
		}
		unsigned int answer = factorial(input);
		cout << answer << endl;
	}

	
}

int factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}