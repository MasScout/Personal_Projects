// Programming_Assignment_2.cpp : Defines the entry point for the console application.
// CS 121 Programming Assignment 2
// File: Programming_Assignment_2.cpp
// Author: Mason Barrow
// Desc: Calculates the users weight on 10 different bodies in the solar system based on user inputted weight and planet choice.
// Date: 10/14/2018

// I attest that this program is entirely my own work.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	//INITIALIZATIONS
	float weightFactors[10] = { .4155, .8975, 1, .166, .3507, 2.5374, 1.0677, .8947, 1.1794, .0899 };
	string planetNames[10] = { "MERCURY", "VENUS", "EARTH", "MOON", "MARS", "JUPITER", "SATURN", "URANUS", "NEPTUNE", "PLUTO" };
	string planetChoice;
	string quitChoice = "YES";
	int planetNumber = 0;
	int i = 0;
	int weight = 0;
	int planetLogic = 0;

	printf("Welcome to the Interplanetary Weight Calculator.\n");
	
	//REPEAT UNTIL USER WANTS TO STOP
	while (quitChoice == "YES" || quitChoice == "Y") {
		printf("Please enter your weight in pounds: ");
		cin >> weight;
		
		printf("Which planet would you like to calculate?	");
		cin >> planetChoice;
		transform(planetChoice.begin(), planetChoice.end(), planetChoice.begin(), ::toupper);
			
		//LOOP TO STEP THROUGH ARRAY OF PLANET NAMES AND FACTORS
		for (i = 0; i <= 10; i) {
			if (planetChoice == planetNames[i]) {
				planetNumber = i;
				break;
			}
			else if (i == 10) {
				cout << planetChoice << " is not a valid option, please try again." << endl;
				i = 0;
				cin >> planetChoice;
				transform(planetChoice.begin(), planetChoice.end(), planetChoice.begin(), ::toupper);
			}
			else {
				i++;
			}
		}

		//CALCULATIONS AND OUTPUT STATEMENT
		weight = weight * weightFactors[planetNumber];
		cout << "\nYou would weigh " << weight << " pounds on " << planetChoice << endl;

		//GO AGAIN LOGIC FOR MAIN LOOP
		printf("\n\nWould you like to measure any more planets or weights? ");
		cin >> quitChoice;
		transform(quitChoice.begin(), quitChoice.end(), quitChoice.begin(), ::toupper);
	}

	return 0;
}

