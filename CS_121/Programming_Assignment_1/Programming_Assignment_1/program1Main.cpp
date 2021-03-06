// CS 121 Programming Assignment 1
// Programming_Assignment_1.cpp : Defines the entry point for the console application.
// Author: Mason Barrow
// This program compares Stirling's Approximation to direct factorial calculations.
// Submitted: 9/23/18

// I attest that this program is entirely my own work.

#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	//Declarations
	double stirlingCalculation;
	double directCalculation;
	double difference;

	//Direct Calculation and Print of 15!
	directCalculation = (1.0)*(2.0)*(3.0)*(4.0)*(5.0)*6.0*7.0*8.0*9.0*10.0*11.0*12.0*13.0*14.0*15.0;
	cout << "The Direct Calculation of 15! = " << directCalculation << endl;

	//Stirling Approximations and Print of 15!
	stirlingCalculation = (exp(-15))*(pow(15, 15))*(sqrt(2 * 3.141592 * 15));
	cout << "The Stirling Calculation of 15! = " << stirlingCalculation << endl;

	//Calculate and print the difference between the Direct Calculation and Stirling Approximation
	difference = directCalculation - stirlingCalculation;
	cout << "The Difference between the calculations is = " << difference << endl;
	return 0;
}

