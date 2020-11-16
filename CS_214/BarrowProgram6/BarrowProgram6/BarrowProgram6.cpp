/*******************************************************************
* CS 214-01 Programming Assignment Relations
* File: BarrowProgram6.cpp
* Author: Mason Barrow
* Desc: Determines different properties of a relation on a set
* Date: November 15, 2020
*
* I attest that this program is entirely my own work
*******************************************************************/

#include <iostream>
#include <array>

using namespace std;

int main()
{
	int set1[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int set2[6] = { 1, 3, 5, 15, 30, 60 };
	char set3[5] = { 'a','b','c','d','e' };
	int set4[6] = { 1, 2, 3, 4, 5, 6 };

	int relation1[7][7] = {
		1,0,1,1,0,0,0,
		0,1,0,0,0,0,1,
		1,0,1,1,0,0,0,
		1,0,1,1,0,0,0,
		0,0,0,0,1,1,0,
		0,0,0,0,1,1,0,
		0,1,0,0,0,0,1 };

	int set1Len = sizeof(set1) / sizeof(set1[0]);
	int rel1Len = sizeof(relation1) / sizeof(relation1[0]);

	cout << "Set S = { ";
	for (int i = 0; i < set1Len; i++) {
		if (i != set1Len - 1) {
			cout << set1[i] << ", ";
		}
		else {
			cout << set1[i] << " }" << endl;
		}
	}
	
	cout << "\nRelation R:S [] S = { ";
	for (int i = 0; i < set1Len; i++) {
		for (int j = 0; j < set1Len; j++) {
			if (relation1[i][j] == 1) {
				if (!(i == 6 && j == 6)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}
	
	cout << "\nThe Boolean Matrix of the Relation:" << endl;
	cout << "\n  | ";
	for (int i = 1; i <= set1Len; i++) {
		cout << i << "  ";
	}
	cout << "\n--";
	for (int i = 1; i <= set1Len; i++) {
		cout << "---";
	}
	for (int i = 0; i < set1Len; i++) {
		cout << "\n" << i+1 << " | ";
		for (int j = 0; j < set1Len; j++) {
			cout << relation1[i][j] << "  ";
		}
	}

}