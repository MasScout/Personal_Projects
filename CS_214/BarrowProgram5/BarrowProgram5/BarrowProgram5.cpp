/*******************************************************************
* CS214-05 Programming Assignment
* File: BarrowProgram5.cpp
* Author: Mason Barrow
* Desc: Computation time calculator for certain orders of magnitude (Big-O Notation).
* Date: November 1, 2020
*
* I attest that this program is entirely my own work
*******************************************************************/

#include <iostream>

#define ROWS 7

double timestep;
int iterationLow;
int iterationMiddle;
int iterationHigh;

void timeConversion(double entry);
int factorial(int n);

using namespace std;

int main() {
	cout << "Computation time calculator for given algorithms.\n";
	cout << "\nPlease enter calculation time: ";
	cin >> timestep;
	cout << "Please enter Low iteration count: ";
	cin >> iterationLow;
	cout << "Please enter Middle iteration count: ";
	cin >> iterationMiddle;
	cout << "Please enter High iteration count: ";
	cin >> iterationHigh;

	unsigned long long int factLow;
	unsigned long long int factMiddle;
	unsigned long long int factHigh;

	cout << endl;
	for (int row = 0; row < ROWS; row++) {
		switch (row) {
		case 0:
			cout << "\nlog(n)\t\t";
			timeConversion(timestep * log(iterationLow));
			timeConversion(timestep * log(iterationMiddle));
			timeConversion(timestep * log(iterationHigh));
			cout << endl;
			break;
		case 1:
			cout << "n\t\t";
			timeConversion(timestep * (iterationLow));
			timeConversion(timestep * (iterationMiddle));
			timeConversion(timestep * (iterationHigh));
			cout << endl;
			break;
		case 2:
			cout << "n*log(n)\t";
			timeConversion(timestep * iterationLow * log(iterationLow));
			timeConversion(timestep * iterationMiddle * log(iterationMiddle));
			timeConversion(timestep * iterationHigh * log(iterationHigh));
			cout << endl;
			break;
		case 3:
			cout << "n^2\t\t";
			timeConversion(timestep * pow(iterationLow, 2));
			timeConversion(timestep * pow(iterationMiddle, 2));
			timeConversion(timestep * pow(iterationHigh, 2));
			cout << endl;
			break;
		case 4:
			cout << "n^3\t\t";
			timeConversion(timestep * pow(iterationLow, 3));
			timeConversion(timestep * pow(iterationMiddle, 3));
			timeConversion(timestep * pow(iterationHigh, 3));
			cout << endl;
			break;
		case 5:
			cout << "n!\t\t";
			factLow = factorial(iterationLow);
			if (factLow >= 3.1536*pow(10, 12)) {
				factMiddle = factLow;
				factHigh = factLow;
			}
			else {
				factMiddle = factorial(iterationMiddle);
				factHigh = factorial(iterationHigh);
			}
			timeConversion(timestep * factLow);
			timeConversion(timestep * factMiddle);
			timeConversion(timestep * factHigh);
			cout << endl;
			break;
		case 6:
			cout << "2^n\t\t";
			timeConversion(timestep * pow(2, iterationLow));
			timeConversion(timestep * pow(2, iterationMiddle));
			timeConversion(timestep * pow(2, iterationHigh));
			cout << endl;
		default:
			break;
		}
	}
}

void timeConversion(double entry) {
	if (entry >= 60) {
		entry = entry / 60;								// To minutes
		if (entry >= 60) {
			entry = entry / 60;							// To hours
			if (entry >= 24) {
				entry = entry / 24;						// To days
				if (entry >= 365) {
					entry = entry / 365;				// To years
					if (entry >= 100) {
						entry = entry / 100;			// To centuries
						if (entry >= 1000) {
							cout << "Greater than 1,000 Centuries\t";
						}
						else {
							cout << entry << " centuries\t";
						}
					}
					else {
						cout << entry << " years\t\t\t";
					}
				}
				else {
					cout << entry << " days\t\t\t";
				}
			}
			else {
				cout << entry << " hours\t\t\t";
			}
		}
		else {
			cout << entry << " minutes\t\t\t";
		}
	}
	else {
		//cout << entry << " seconds\t";
		printf("%.6f seconds\t\t", entry);
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