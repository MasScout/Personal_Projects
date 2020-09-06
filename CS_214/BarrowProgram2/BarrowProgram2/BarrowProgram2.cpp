//-------------------------------------------------------------------------
// File:					BarrowProgram2.cpp
// Purpose:					Prints a table used for exhaustive proofs
// Programming Language:	C++
// Author:					Mason Barrow
// Date:					September 2020
//-------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int start;
	int stop;
	char type;
	int cols;

	cout << "Welcome to the Exhaustive Proof Table Printer.\n" << endl;
	cout << "Enter the integer starting value: ";
	cin >> start;
	cout << "Enter the integer ending value: ";
	cin >> stop;
	cout << "Do you want All (A), Even (E), or Odd (O) values to be printed: ";
	cin >> type;
	while (tolower(type) != 'a' && tolower(type) != 'e' && tolower(type) != 'o') {
		cout << "Eligible options are A, E, and O";
		cin >> type;
	}

	int counter = 0;
	for (int i = start; i <= stop; i++) {
		if (tolower(type) == 'a') {
			counter++;
		}
		if (tolower(type) == 'e' && i % 2 == 0) {
			counter++;
		}
		if (tolower(type) == 'o' && i % 2 != 0) {
			counter++;
		}
	}

	vector<int> rowList(counter);
	int j = 0;
	for (int i = start; i <= stop; i++) {
		if (tolower(type) == 'a') {
			rowList[j] = i;
			j++;
		}
		if (tolower(type) == 'e' && i % 2 == 0) {
			rowList[j] = i;
			j++;
		}
		if (tolower(type) == 'o' && i % 2 != 0) {
			rowList[j] = i;
			j++;
		}
	}

	cout << endl << "How many additional columns do you want printed? ";
	cin >> cols;
	cin.ignore(100, '\n');
	vector<string> columnList(cols);
	for (int i = 0; i < cols; i++) {
		cout << "Column " << i + 1 << " text: ";
		getline(cin, columnList[i]);
	}

	cout << endl << "Following is the table you requested." << endl;
	cout << "n";
	for (int i = 0; i < cols; i++) {
		cout << "     " << columnList[i];
	}
	cout << endl;
	for (int i = 0; i < size(rowList); i++) {
		cout << rowList[i] << endl;
	}
}

