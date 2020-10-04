//-----------------------------------------------------------------------------------
// File:					BarrowProgram4.cpp
// Purpose:					Creates a Pascal Triangle for up to 20 rows
// Programming Language:	C++
// Author:					Mason Barrow
// Date:					October 2020
//-----------------------------------------------------------------------------------

#include <iostream>

using namespace std;

long values(long x, long y);

int main() {
	int row;
	cout << "enter number of rows: ";
	cin >> row;
	while (row > 20) {
		cout << "number of rows must be 20 or less. please try again. ";
		cin >> row;
	}

	for (int i = 0; i < row; i++) {
		cout << i << "\t";
		for (int j = 0; j < (i + 1); j++) {
			cout << values(i, j) << " ";
		}
		cout << endl;
	}
}

long values(long x, long y) {
	int res = 1;
	if (y > x - y) {
		y = x - y;
	}
	for (int i = 0; i < y; ++i) {
		res *= (x - i);
		res /= (i + 1);
	}
	return res;
}
