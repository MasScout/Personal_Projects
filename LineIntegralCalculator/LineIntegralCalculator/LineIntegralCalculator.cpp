// LineIntegralCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string f;
	string ri;
	string rj;
	string rk;
	int lowerBound;
	int upperBound;

	cout << "Enter the function f(x,y,z): " << endl;
	cin >> f;
	cout << "Enter the i component of curve r(t): " << endl;
	cin >> ri;
	cout << "Enter the j component of curve r(t): " << endl;
	cin >> rj;
	cout << "Enter the k component of curve r(t): " << endl;
	cin >> rk;
	cout << "Enter the lower bound of t: " << endl;
	cin >> lowerBound;
	cout << "Enter the upper bound of t: " << endl;
	cin >> upperBound;



	return 0;
}

