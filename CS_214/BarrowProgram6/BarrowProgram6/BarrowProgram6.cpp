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
	// Declare Sets
	int set1[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int set2[6] = { 1, 3, 5, 15, 30, 60 };
	char set3[5] = { 'a','b','c','d','e' };
	int set4[6] = { 1, 2, 3, 4, 5, 6 };

	// Declare Relations
	int relation1[7][7] = {
		1,0,1,1,0,0,0,
		0,1,0,0,0,0,1,
		1,0,1,1,0,0,0,
		1,0,1,1,0,0,0,
		0,0,0,0,1,1,0,
		0,0,0,0,1,1,0,
		0,1,0,0,0,0,1 };
	int relation2[6][6] = {
		1,1,1,1,1,1,
		0,1,0,1,1,1,
		0,0,1,1,1,1,
		0,0,0,1,1,1,
		0,0,0,0,1,1,
		0,0,0,0,0,1 };
	int relation3[5][5] = {
		1,1,0,0,0,
		0,0,1,0,0,
		0,0,0,0,1,
		0,0,0,1,1,
		0,0,0,1,0 };
	int relation4[6][6] = {
		1,0,0,0,0,0,
		0,0,1,0,0,0,
		0,1,0,1,0,0,
		0,0,0,0,1,0,
		0,0,0,0,0,1,
		0,0,0,0,1,0 };


	// FOR SET 1
	int set1Len = sizeof(set1) / sizeof(set1[0]);
	int rel1Len = sizeof(relation1) / sizeof(relation1[0]);

	cout << "SET 1: " << endl;

	// Print Set
	cout << "Set S = { ";
	for (int i = 0; i < set1Len; i++) {
		if (i != set1Len - 1) {
			cout << set1[i] << ", ";
		}
		else {
			cout << set1[i] << " }" << endl;
		}
	}
	
	// Print Relation List
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
	
	// Print Boolean Matrix
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

	// Calculate Properties
	bool reflexive1 = true;
	bool irreflexive1 = true;
	bool symmetric1 = true;
	bool asymmetric1 = true;
	bool antisymmetric1 = true;

	for (int i = 0; i < set1Len; i++) {
		for (int j = 0; j < set1Len; j++) {
			// Calculate Reflexiveness
			if (i == j && relation1[i][j] != 1) {
				reflexive1 = false;
			}

			// Calculate Irreflexiveness
			if (i == j && relation1[i][j] == 1) {
				irreflexive1 = false;
			}
			
			// Calculate Symmetry
			if (relation1[i][j] == 1) {
				if (!(relation1[j][i] == 1)) {
					symmetric1 = false;
				}
			}

			// Calculate Antisymmetry
			if (i != j && relation1[i][j] == 1) {
				if ((relation1[j][i] == 1)) {
					antisymmetric1 = false;
				}
			}
		}
	}

	// Calculate Asymmetry
	if (reflexive1 || symmetric1) {
		asymmetric1 = false;
	}
	
	// Print Properties
	cout << "\n\nThe Properties of the relation:" << endl;
	cout << "Reflexive: ";
	if (reflexive1 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Irreflexive: ";
	if (irreflexive1 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Symmetric: ";
	if (symmetric1 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Asymmetric: ";
	if (asymmetric1 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Antisymmetric: ";
	if (asymmetric1 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	// FOR SET 2
	int set2Len = sizeof(set2) / sizeof(set2[0]);
	int rel2Len = sizeof(relation2) / sizeof(relation2[0]);

	cout << "\n\n\nSET 2: " << endl;

	// Print Set
	cout << "Set S = { ";
	for (int i = 0; i < set2Len; i++) {
		if (i != set2Len - 1) {
			cout << set2[i] << ", ";
		}
		else {
			cout << set2[i] << " }" << endl;
		}
	}

	// Print Relation List
	cout << "\nRelation R:S [] S = { ";
	for (int i = 0; i < set2Len; i++) {
		for (int j = 0; j < set2Len; j++) {
			if (relation2[i][j] == 1) {
				if (!(i == 6 && j == 6)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}

	// Print Boolean Matrix
	cout << "\nThe Boolean Matrix of the Relation:" << endl;
	cout << "\n  | ";
	for (int i = 1; i <= set2Len; i++) {
		cout << i << "  ";
	}
	cout << "\n--";
	for (int i = 1; i <= set2Len; i++) {
		cout << "---";
	}
	for (int i = 0; i < set2Len; i++) {
		cout << "\n" << i + 1 << " | ";
		for (int j = 0; j < set2Len; j++) {
			cout << relation2[i][j] << "  ";
		}
	}

	// Calculate Properties
	bool reflexive2 = true;
	bool irreflexive2 = true;
	bool symmetric2 = true;
	bool asymmetric2 = true;
	bool antisymmetric2 = true;

	for (int i = 0; i < set2Len; i++) {
		for (int j = 0; j < set2Len; j++) {
			// Calculate Reflexiveness
			if (i == j && relation2[i][j] != 1) {
				reflexive2 = false;
			}

			// Calculate Irreflexiveness
			if (i == j && relation2[i][j] == 1) {
				irreflexive2 = false;
			}

			// Calculate Symmetry
			if (relation2[i][j] == 1) {
				if (!(relation2[j][i] == 1)) {
					symmetric2 = false;
				}
			}

			// Calculate Antisymmetry
			if (i != j && relation2[i][j] == 1) {
				if ((relation2[j][i] == 1)) {
					antisymmetric2 = false;
				}
			}
		}
	}

	// Calculate Asymmetry
	if (reflexive2 || symmetric2) {
		asymmetric2 = false;
	}

	// Print Properties
	cout << "\n\nThe Properties of the relation:" << endl;
	cout << "Reflexive: ";
	if (reflexive2 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Irreflexive: ";
	if (irreflexive2 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Symmetric: ";
	if (symmetric2 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Asymmetric: ";
	if (asymmetric2 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Antisymmetric: ";
	if (asymmetric2 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}
	

	// FOR SET 3
	int set3Len = sizeof(set3) / sizeof(set3[0]);
	int rel3Len = sizeof(relation3) / sizeof(relation3[0]);

	cout << "\n\n\nSET 3: " << endl;

	// Print Set
	cout << "Set S = { ";
	for (int i = 0; i < set3Len; i++) {
		if (i != set3Len - 1) {
			cout << set3[i] << ", ";
		}
		else {
			cout << set3[i] << " }" << endl;
		}
	}

	// Print Relation List
	cout << "\nRelation R:S [] S = { ";
	for (int i = 0; i < set3Len; i++) {
		for (int j = 0; j < set3Len; j++) {
			if (relation3[i][j] == 1) {
				if (!(i == 6 && j == 6)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}

	// Print Boolean Matrix
	cout << "\nThe Boolean Matrix of the Relation:" << endl;
	cout << "\n  | ";
	for (int i = 1; i <= set3Len; i++) {
		cout << i << "  ";
	}
	cout << "\n--";
	for (int i = 1; i <= set3Len; i++) {
		cout << "---";
	}
	for (int i = 0; i < set3Len; i++) {
		cout << "\n" << i + 1 << " | ";
		for (int j = 0; j < set3Len; j++) {
			cout << relation3[i][j] << "  ";
		}
	}

	// Calculate Properties
	bool reflexive3 = true;
	bool irreflexive3 = true;
	bool symmetric3 = true;
	bool asymmetric3 = true;
	bool antisymmetric3 = true;

	for (int i = 0; i < set3Len; i++) {
		for (int j = 0; j < set3Len; j++) {
			// Calculate Reflexiveness
			if (i == j && relation3[i][j] != 1) {
				reflexive3 = false;
			}

			// Calculate Irreflexiveness
			if (i == j && relation3[i][j] == 1) {
				irreflexive3 = false;
			}

			// Calculate Symmetry
			if (relation3[i][j] == 1) {
				if (!(relation3[j][i] == 1)) {
					symmetric3 = false;
				}
			}

			// Calculate Antisymmetry
			if (i != j && relation3[i][j] == 1) {
				if ((relation3[j][i] == 1)) {
					antisymmetric3 = false;
				}
			}
		}
	}

	// Calculate Asymmetry
	if (reflexive3 || symmetric3) {
		asymmetric3 = false;
	}

	// Print Properties
	cout << "\n\nThe Properties of the relation:" << endl;
	cout << "Reflexive: ";
	if (reflexive3 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Irreflexive: ";
	if (irreflexive3 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Symmetric: ";
	if (symmetric3 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Asymmetric: ";
	if (asymmetric3 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Antisymmetric: ";
	if (asymmetric3 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}
}


