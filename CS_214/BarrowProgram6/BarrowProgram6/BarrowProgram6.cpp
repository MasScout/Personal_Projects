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

char intToCharConversion(int number);

int main()
{
	// Declare Sets
	int set1[4] = { 1, 2, 3, 4 };
	int set2[6] = { 1, 3, 5, 15, 30, 60 };
	char set3[5] = { 'a','b','c','d','e' };
	int set4[6] = { 1, 2, 3, 4, 5, 6 };

	// Declare Relations
	int relation1[4][4] = {
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
		1,1,1,1};
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
	cout << "Relation R:S [] S = { ";
	for (int i = 0; i < set1Len; i++) {
		for (int j = 0; j < set1Len; j++) {
			if (relation1[i][j] == 1) {
				if (!(i == set1Len-1 && j == set1Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }\n" << endl;
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
	bool transitive1 = true;
	bool poset1 = false;
	bool equivalence1 = false;

	int reflexiveClosure1[7][7] = {
	1,0,1,1,0,0,0,
	0,1,0,0,0,0,1,
	1,0,1,1,0,0,0,
	1,0,1,1,0,0,0,
	0,0,0,0,1,1,0,
	0,0,0,0,1,1,0,
	0,1,0,0,0,0,1 };

	int symmetricClosure1[7][7] = {
	1,0,1,1,0,0,0,
	0,1,0,0,0,0,1,
	1,0,1,1,0,0,0,
	1,0,1,1,0,0,0,
	0,0,0,0,1,1,0,
	0,0,0,0,1,1,0,
	0,1,0,0,0,0,1 };

	int transitiveClosure1[7][7] = {
	1,0,1,1,0,0,0,
	0,1,0,0,0,0,1,
	1,0,1,1,0,0,0,
	1,0,1,1,0,0,0,
	0,0,0,0,1,1,0,
	0,0,0,0,1,1,0,
	0,1,0,0,0,0,1 };

	for (int i = 0; i < set1Len; i++) {
		for (int j = 0; j < set1Len; j++) {
			// Calculate Reflexiveness
			if (i == j && relation1[i][j] != 1) {
				reflexive1 = false;
				reflexiveClosure1[i][j] = 1;
			}

			// Calculate Irreflexiveness
			if (i == j && relation1[i][j] == 1) {
				irreflexive1 = false;
			}
			
			// Calculate Symmetry
			if (relation1[i][j] == 1) {
				if (!(relation1[j][i] == 1)) {
					symmetric1 = false;
					symmetricClosure1[i][j] = 1;
				}
			}

			// Calculate Antisymmetry
			if (i != j && relation1[i][j] == 1) {
				if ((relation1[j][i] == 1)) {
					antisymmetric1 = false;
				}
			}

			// Calculate Transivity
			if (relation1[i][j] == 1) {
				for (int k = 0; k < set1Len; k++) {
					if (relation1[j][k] && !relation1[i][k]) {
						transitive1 = false;
					}
				}
			}
		}
	}

	// Calculate Asymmetry
	if (reflexive1 || symmetric1) {
		asymmetric1 = false;
	}

	// Calculate Partial Ordering
	if (reflexive1 && antisymmetric1 && transitive1) {
		poset1 = true;
	}

	// Calculate Equivalence Relation
	if (reflexive1 && symmetric1 && transitive1) {
		equivalence1 = true;
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
	if (antisymmetric1 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Transitive: ";
	if (transitive1 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Partial Ordering: ";
	if (poset1 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}
	
	cout << "Equivalence Relation: ";
	if (equivalence1 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "\nThe reflexive closure set for R is: ";
	for (int i = 0; i < set1Len; i++) {
		for (int j = 0; j < set1Len; j++) {
			if (reflexiveClosure1[i][j] == 1) {
				if (!(i == set1Len - 1 && j == set1Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}

	cout << "The symmetric closure set for R is: ";
	for (int i = 0; i < set1Len; i++) {
		for (int j = 0; j < set1Len; j++) {
			if (symmetricClosure1[i][j] == 1) {
				if (!(i == set1Len - 1 && j == set1Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}

	cout << "The transitive closure set for R is: ";
	for (int k = 0; k < set1Len; k++) {
		for (int i = 1; i <= set1Len; i++) {
			for (int j = 1; j <= set1Len; j++) {
				transitiveClosure1[i][j] = transitiveClosure1[i][j] || (transitiveClosure1[i][k + 1] && transitiveClosure1[k + 1][j]);
			}
		}
	}
	for (int i = 0; i < set1Len; i++) {
		for (int j = 0; j < set1Len; j++) {
			if (transitiveClosure1[i][j] == 1) {
				if (!(i == set1Len - 1 && j == set1Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
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
	cout << "Relation R:S [] S = { ";
	for (int i = 0; i < set2Len; i++) {
		for (int j = 0; j < set2Len; j++) {
			if (relation2[i][j] == 1) {
				if (!(i == set2Len - 1 && j == set2Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }\n" << endl;
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
	bool transitive2 = true;
	bool poset2 = false;
	bool equivalence2 = false;

	int reflexiveClosure2[6][6] = {
		1,1,1,1,1,1,
		0,1,0,1,1,1,
		0,0,1,1,1,1,
		0,0,0,1,1,1,
		0,0,0,0,1,1,
		0,0,0,0,0,1 };

	int symmetricClosure2[6][6] = {
		1,1,1,1,1,1,
		0,1,0,1,1,1,
		0,0,1,1,1,1,
		0,0,0,1,1,1,
		0,0,0,0,1,1,
		0,0,0,0,0,1 };

	int transitiveClosure2[6][6] = {
		1,1,1,1,1,1,
		0,1,0,1,1,1,
		0,0,1,1,1,1,
		0,0,0,1,1,1,
		0,0,0,0,1,1,
		0,0,0,0,0,1 };

	for (int i = 0; i < set2Len; i++) {
		for (int j = 0; j < set2Len; j++) {
			// Calculate Reflexiveness
			if (i == j && relation2[i][j] != 1) {
				reflexive2 = false;
				reflexiveClosure2[i][j] = 1;
			}

			// Calculate Irreflexiveness
			if (i == j && relation2[i][j] == 1) {
				irreflexive2 = false;
			}

			// Calculate Symmetry
			if (relation2[i][j] == 1) {
				if (!(relation2[j][i] == 1)) {
					symmetric2 = false;
					symmetricClosure2[i][j] = 1;
				}
			}

			// Calculate Antisymmetry
			if (i != j && relation2[i][j] == 1) {
				if ((relation2[j][i] == 1)) {
					antisymmetric2 = false;
				}
			}

			// Calculate Transivity
			if (relation2[i][j] == 1) {
				for (int k = 0; k < set2Len; k++) {
					if (relation2[j][k] && !relation2[i][k]) {
						transitive2 = false;
					}
				}
			}
		}
	}

	// Calculate Asymmetry
	if (reflexive2 || symmetric2) {
		asymmetric2 = false;
	}

	// Calculate Partial Ordering
	if (reflexive2 && antisymmetric2 && transitive2) {
		poset2 = true;
	}

	// Calculate Equivalence Relation
	if (reflexive2 && symmetric2 && transitive2) {
		equivalence2 = true;
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
	if (antisymmetric2 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Transitive: ";
	if (transitive2 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Partial Ordering: ";
	if (poset2 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Equivalence Relation: ";
	if (equivalence2 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}
	
	cout << "\nThe reflexive closure set for R is: ";
	for (int i = 0; i < set2Len; i++) {
		for (int j = 0; j < set2Len; j++) {
			if (reflexiveClosure2[i][j] == 1) {
				if (!(i == set2Len - 1 && j == set2Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}

	cout << "The symmetric closure set for R is: ";
	for (int i = 0; i < set2Len; i++) {
		for (int j = 0; j < set2Len; j++) {
			if (symmetricClosure2[i][j] == 1) {
				if (!(i == set2Len - 1 && j == set2Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}

	cout << "The transitive closure set for R is: ";
	for (int k = 0; k < set2Len; k++) {
		for (int i = 1; i <= set2Len; i++) {
			for (int j = 1; j <= set2Len; j++) {
				transitiveClosure2[i][j] = transitiveClosure2[i][j] || (transitiveClosure2[i][k + 1] && transitiveClosure2[k + 1][j]);
			}
		}
	}
	for (int i = 0; i < set2Len; i++) {
		for (int j = 0; j < set2Len; j++) {
			if (transitiveClosure2[i][j] == 1) {
				if (!(i == set2Len - 1 && j == set2Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
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
	cout << "Relation R:S [] S = { ";
	for (int i = 0; i < set3Len; i++) {
		for (int j = 0; j < set3Len; j++) {
			if (relation3[i][j] == 1) {
				if (!(i == set3Len - 1 && j == set3Len - 1)) {
					cout << "(" << intToCharConversion(i + 1) << "," << intToCharConversion(j + 1) << "), ";
				}
				else {
					cout << "(" << intToCharConversion(i + 1) << "," << intToCharConversion(j + 1) << ") }\n" << endl;
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
	bool transitive3 = true;
	bool poset3 = false;
	bool equivalence3 = false;

	int reflexiveClosure3[5][5] = {
		1,1,0,0,0,
		0,0,1,0,0,
		0,0,0,0,1,
		0,0,0,1,1,
		0,0,0,1,0 };

	int symmetricClosure3[5][5] = {
		1,1,0,0,0,
		0,0,1,0,0,
		0,0,0,0,1,
		0,0,0,1,1,
		0,0,0,1,0 };

	int transitiveClosure3[5][5] = {
		1,1,0,0,0,
		0,0,1,0,0,
		0,0,0,0,1,
		0,0,0,1,1,
		0,0,0,1,0 };

	for (int i = 0; i < set3Len; i++) {
		for (int j = 0; j < set3Len; j++) {
			// Calculate Reflexiveness
			if (i == j && relation3[i][j] != 1) {
				reflexive3 = false;
				reflexiveClosure3[i][j] = 1;
			}

			// Calculate Irreflexiveness
			if (i == j && relation3[i][j] == 1) {
				irreflexive3 = false;
			}

			// Calculate Symmetry
			if (relation3[i][j] == 1) {
				if (!(relation3[j][i] == 1)) {
					symmetric3 = false;
					symmetricClosure3[i][j] = 1;
				}
			}

			// Calculate Antisymmetry
			if (i != j && relation3[i][j] == 1) {
				if ((relation3[j][i] == 1)) {
					antisymmetric3 = false;
				}
			}

			// Calculate Transivity
			if (relation3[i][j] == 1) {
				for (int k = 0; k < set3Len; k++) {
					if (relation3[j][k] && !relation3[i][k]) {
						transitive3 = false;
					}
				}
			}
		}
	}

	// Calculate Asymmetry
	if (reflexive3 || symmetric3) {
		asymmetric3 = false;
	}

	// Calculate Partial Ordering
	if (reflexive3 && antisymmetric3 && transitive3) {
		poset3 = true;
	}

	// Calculate Equivalence Relation
	if (reflexive3 && symmetric3 && transitive3) {
		equivalence3 = true;
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
	if (antisymmetric3 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Transitive: ";
	if (transitive3 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Partial Ordering: ";
	if (poset3 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Equivalence Relation: ";
	if (equivalence3 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "\nThe reflexive closure set for R is: ";
	for (int i = 0; i < set3Len; i++) {
		for (int j = 0; j < set3Len; j++) {
			if (reflexiveClosure3[i][j] == 1) {
				if (!(i == set3Len - 1 && j == set3Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}

	cout << "The symmetric closure set for R is: ";
	for (int i = 0; i < set3Len; i++) {
		for (int j = 0; j < set3Len; j++) {
			if (symmetricClosure3[i][j] == 1) {
				if (!(i == set3Len - 1 && j == set3Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}

	cout << "\nThe transitive closure set for R is: ";
	for (int k = 0; k < set3Len; k++) {
		for (int i = 1; i <= set3Len; i++) {
			for (int j = 1; j <= set3Len; j++) {
				transitiveClosure3[i][j] = transitiveClosure3[i][j] || (transitiveClosure3[i][k + 1] && transitiveClosure3[k + 1][j]);
			}
		}
	}
	for (int i = 0; i < set3Len; i++) {
		for (int j = 0; j < set3Len; j++) {
			if (transitiveClosure3[i][j] == 1) {
				if (!(i == set3Len - 1 && j == set3Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }" << endl;
				}
			}
		}
	}



	// FOR SET 4
	int set4Len = sizeof(set4) / sizeof(set4[0]);
	int rel4Len = sizeof(relation4) / sizeof(relation4[0]);

	cout << "\n\n\nSET 4: " << endl;

	// Print Set
	cout << "Set S = { ";
	for (int i = 0; i < set4Len; i++) {
		if (i != set4Len - 1) {
			cout << set4[i] << ", ";
		}
		else {
			cout << set4[i] << " }" << endl;
		}
	}

	// Print Relation List
	cout << "Relation R:S [] S = { ";
	for (int i = 0; i < set4Len; i++) {
		for (int j = 0; j < set4Len; j++) {
			if (relation4[i][j] == 1) {
				if (!(i == set4Len - 1 && j == set4Len - 1)) {
					cout << "(" << i + 1 << "," << j + 1 << "), ";
				}
				else {
					cout << "(" << i + 1 << "," << j + 1 << ") }\n" << endl;
				}
			}
		}
	}

	// Print Boolean Matrix
	cout << "\nThe Boolean Matrix of the Relation:" << endl;
	cout << "\n  | ";
	for (int i = 1; i <= set4Len; i++) {
		cout << i << "  ";
	}
	cout << "\n--";
	for (int i = 1; i <= set4Len; i++) {
		cout << "---";
	}
	for (int i = 0; i < set4Len; i++) {
		cout << "\n" << i + 1 << " | ";
		for (int j = 0; j < set4Len; j++) {
			cout << relation4[i][j] << "  ";
		}
	}

	// Calculate Properties
	bool reflexive4 = true;
	bool irreflexive4 = true;
	bool symmetric4 = true;
	bool asymmetric4 = true;
	bool antisymmetric4 = true;
	bool transitive4 = true;
	bool poset4 = false;
	bool equivalence4 = false;

	for (int i = 0; i < set4Len; i++) {
		for (int j = 0; j < set4Len; j++) {
			// Calculate Reflexiveness
			if (i == j && relation4[i][j] != 1) {
				reflexive4 = false;
			}

			// Calculate Irreflexiveness
			if (i == j && relation4[i][j] == 1) {
				irreflexive4 = false;
			}

			// Calculate Symmetry
			if (relation4[i][j] == 1) {
				if (!(relation4[j][i] == 1)) {
					symmetric4 = false;
				}
			}

			// Calculate Antisymmetry
			if (i != j && relation4[i][j] == 1) {
				if ((relation4[j][i] == 1)) {
					antisymmetric4 = false;
				}
			}

			// Calculate Transivity
			if (relation4[i][j] == 1) {
				for (int k = 0; k < set4Len; k++) {
					if (relation4[j][k] && !relation4[i][k]) {
						transitive4 = false;
					}
				}
			}
		}
	}

	// Calculate Asymmetry
	if (reflexive4 || symmetric4) {
		asymmetric4 = false;
	}

	// Calculate Partial Ordering
	if (reflexive4 && antisymmetric4 && transitive4) {
		poset4 = true;
	}

	// Calculate Equivalence Relation
	if (reflexive4 && symmetric4 && transitive4) {
		equivalence4 = true;
	}

	// Print Properties
	cout << "\n\nThe Properties of the relation:" << endl;
	cout << "Reflexive: ";
	if (reflexive4 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Irreflexive: ";
	if (irreflexive4 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Symmetric: ";
	if (symmetric4 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Asymmetric: ";
	if (asymmetric4 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Antisymmetric: ";
	if (antisymmetric4 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Transitive: ";
	if (transitive4 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Partial Ordering: ";
	if (poset4 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	cout << "Equivalence Relation: ";
	if (equivalence4 == true) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}
}

char intToCharConversion(int number) {
	switch (number) {
	case(1):
		return 'a';
	case(2):
		return 'b';
	case(3):
		return 'c';
	case(4):
		return 'd';
	case(5):
		return 'e';
	default:
		break;
	}
}
