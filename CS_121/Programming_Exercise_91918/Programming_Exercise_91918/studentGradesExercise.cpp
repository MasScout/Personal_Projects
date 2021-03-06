// studentGradesExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	//Declarations
	string firstName;
	string lastName;
	double test1;
	double test2;
	double test3;
	double assignment1;
	double assignment2;
	double assignment3;
	double finalExam;
	double totalPoints;
	double avg;
	string reportCardFile;
	ofstream outFile;

	//Collecting Data from User Inputs
	printf("Please enter your first and last name: ");
	cin >> firstName >> lastName;
	printf("\nPlease enter your 3 test grades, separated by spaces: ");
	cin >> test1 >> test2 >> test3;
	printf("\nPlease enter your 3 assignment grades, separated by spaces: ");
	cin >> assignment1 >> assignment2 >> assignment3;
	printf("\nPlease enter your final exam grade: ");
	cin >> finalExam;

	//Calculations
	totalPoints = test1 + test2 + test3 + assignment1 + assignment2 + assignment3 + finalExam;
	avg = totalPoints / 5.75;

	//Writing to new file
	reportCardFile = firstName.substr(0,1) + "_" + lastName + ".txt";
	printf("Opening Data File...\n");
	outFile.open(reportCardFile.c_str());
	if (!outFile.is_open()) exit(0);
	printf("Data File Opened... Writing to Data File...\n");
	outFile << "***Report Card***" << endl;
	outFile << "Student: " << lastName << ", " << firstName << "\nFinal Average = " << fixed << setprecision(2) << avg << endl;
	printf("Writing Complete... Closing Data File...\n");
	outFile.close();
	if (outFile.is_open()) exit(0);
	printf("Data File Closed...\n");

	return 0;
}

