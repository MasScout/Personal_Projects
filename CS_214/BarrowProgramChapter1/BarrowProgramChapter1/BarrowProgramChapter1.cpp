// BarrowProgramChapter1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int number = 0;
	int possibilities = 0;
	
	// Input for Number of Variables in Truth Table
	cout << "This program will print a truth table for you." << endl;
	cout << "Please enter the number of variables to print in your truth table: ";
	cin >> number;
	while (number < 1 || number > 5) {
		cout << "The number of variables must be between 1 and 5. Please try again: ";
		cin >> number;
	}

	// Input for Variables in Truth Table
	vector<char> symbolList(number);
	for (int i = 0; i < number; i++) {
		char tempSymbol;
		cout << "Enter Symbol " << i + 1 << ": ";
		cin >> tempSymbol;
		while (tempSymbol != 'A' && tempSymbol != 'B' && tempSymbol != 'C' && tempSymbol != 'x' && tempSymbol != 'y' && tempSymbol != 'z') {
			cout << "Eligible symbols are A, B, C, x, y, and z. Please try again: ";
			cin >> tempSymbol;
		}
		symbolList[i] = tempSymbol;
	}

	// Populating Truth Table
	possibilities = pow(2, number);
	vector<vector<char>> truthTable(possibilities, vector<char> (number, '0'));
	int iterator = possibilities / 2;
	int counter = 0;
	bool switcher = true;
	for (int col = 0; col < number; col++) {
		for (int row = 0; row < possibilities; row++) {
			if (counter >= iterator) {
				switcher = !switcher;
				counter = 0;
			}
			if (counter < iterator) {
				if (switcher == true) {
					truthTable[row][col] = 'T';
				}
				else {
					truthTable[row][col] = 'F';
				}
			}
			counter++;
		}
		iterator = iterator / 2;
		counter = 0;
		switcher = true;
	}

	// Printing Truth Table Header
	cout << "\n";
	for (int i = 0; i < number; i++) {
		cout << symbolList[i] << "\t";
	}
	cout << "\n";

	// Printing Truth Table Body
	for (int i = 0; i < possibilities; i++) {
		for (int j = 0; j < number; j++) {
			cout << truthTable[i][j] << "\t";
		}
		cout << "\n";
	}
}