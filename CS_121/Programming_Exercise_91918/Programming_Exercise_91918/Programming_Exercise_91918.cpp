// Programming_Exercise_91918.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
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

	printf("Please enter your first and last name: ");
	scanf_s("%s %s", firstName, lastName);
	printf("\nPlease enter your 3 test grades, separated by spaces: ");
	scanf_s("%lf %lf %lf", test1, test2, test3);
	printf("\nPlease enter your 3 assignment grades, separated by spaces: ");
	scanf_s("%lf %lf %lf", assignment1, assignment2, assignment3);
	printf("\nPlease enter your final exam grade: ");
	scanf_s("%lf", finalExam);

	totalPoints = test1 + test2 + test3 + assignment1 + assignment2 + assignment3 + finalExam;
	avg = totalPoints / 5.75;

	printf("Student: %s, %s\nFinal Average = %f", lastName, firstName, avg);
	return 0;
}

