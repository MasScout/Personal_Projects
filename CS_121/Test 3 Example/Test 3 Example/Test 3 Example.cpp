// Test 3 Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int examPrep[12][15];
	for (int j = 0; j <= 14;j++) {
		for (int i = 0; i <= 11; i++) {
			examPrep[j][i] = i + j;
			cout << examPrep[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int j = 0; j <= 14; j++) {
		for (int i = 0; i <= 11; i += 12) {
			cout << examPrep[j][i];
		}
	}
	cout << endl;
    return 0;
}

