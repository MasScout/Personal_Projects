// Project4.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int printGauntletDescription(void);
int printCrashSiteDescription(void);
int printDrydockDescription(void);
int printComplexDescription(void);
int printAbyssDescription(void);
int printBeaconDescription(void);
int printBlackwaterDescription(void);
int printMaltaDescription(void);
int printFoldWeaponDescription(void);
int printHarmonyDescription(void);
int printTerritoryDescription(void);

int main()
{
	//Initialize Variables
	string cmdVerb;
	string cmdObj;
	int iRow;
	int iCol;
	int iNumRow;
	int iNumCol;

	iRow = 0; //Start at row 0
	iCol = 0; //Start at column 0
	iNumRow = 4; //4 rows on board
	iNumCol = 4; //4 columns on board

	char quitChoice = '!'; //Confirmation for quiting the game

	//Begin Instructions
	printf("You will begin in the training simulation where you will learn the basics of movement, \n");
	printf("combat, and NPC interactions. From there, you will enter the next “room” after the crash \n");
	printf("landing on Typhon. Once this room is completed, you may move freely between most \n");
	printf("other rooms. The only exceptions are; you must complete all titan combat/movement \n");
	printf("rooms before you enter The Fold Weapon, and you must obtain all treasure items before \n");
	printf("travelling to Harmony. Each room will possibly have a creature, a treasure item, another \n");
	printf("item, or any combination. There will be 8 creatures (harmless and dangerous), 4 treasure \n");
	printf("items, and 8 other items. The player’s goal is to move through all the rooms until they \n");
	printf("have gathered all 4 treasure items. To move through the rooms, use the GO command \n");
	printf("(GO NORTH, GO SOUTH, etc.) and acquire items using the TAKE command (TAKE \n");
	printf("JUMPKIT, TAKE CARBINE, etc.). If you encounter dangerous characters, you will be \n");
	printf("prompted to battle them with on screen prompts. Good luck, have fun!\n\n");
	//End Instructions

	//cout << "You are currently on row " << iRow << ", column " << iCol << endl;

	cout << "Press the Enter key to begin";
	getc(stdin);
	cout << "" << endl;
	printGauntletDescription();

	//Action Command
	cout << "\nWhat would you like to do? ";
	cin >> cmdVerb >> cmdObj;
	cout << endl;

	//Force the user input to be capitalized
	transform(cmdVerb.begin(), cmdVerb.end(), cmdVerb.begin(), ::toupper);
	transform(cmdObj.begin(), cmdObj.end(), cmdObj.begin(), ::toupper);

	//Go Logic
	if (cmdVerb == "GO") {
		if (cmdObj == "NORTH") {
			if (iRow > 0) {
				iRow--;
				cout << "GOING NORTH" << endl;
			}
			else {
				cout << "You can't go north from this sector" << endl;
			}
			
		}
		else if (cmdObj == "EAST") {
			if (iCol < (iNumCol - 1)) {
				iCol++;
				cout << "GOING EAST" << endl;
			}
			else {
				cout << "You can't go east from this sector" << endl;
			}
			
		}
		else if (cmdObj == "SOUTH") {
			if (iRow < (iNumRow - 1)) {
				iRow++;
				cout << "GOING SOUTH" << endl;
			}
			else {
				cout << "You can't go south from this sector" << endl;
			}
			
		}
		else if (cmdObj == "WEST") {
			if (iCol > 0) {
				iCol--;
				cout << "GOING WEST" << endl;
			}
			else {
				cout << "You can't go West from this sector" << endl;
			}
			
		}
		else {
			cout << "Please enter a valid direction (ie. NORTH, EAST, SOUTH, WEST)" << endl;
		}
	}
	
	//Take Logic
	else if (cmdVerb == "TAKE") {
		cout << "There is nothing to take yet" << endl;
	}

	//Quit Logic
	else if (cmdVerb == "QUIT") {
		cout << "Are you sure you want to quit? (y/n)" << endl;
		cin >> quitChoice;
		if (quitChoice == 'y') {
			return 0;
		}
		else if (quitChoice == 'n') {
			exit;
		}
		else {
			cout << quitChoice << " is not a valid option, please select y or n" << endl;
		}
	}

	//Unknown Verb Logic
	else {
		cout << cmdVerb << " is not a valid option, please enter GO, TAKE, or QUIT" << endl;
	}

	//cout << cmdVerb.substr(0, 3) << "ING " << cmdObj << endl;

	/*Begin Room Descriptions
	printGauntletDescription();
	printCrashSiteDescription();
	printDrydockDescription();
	printComplexDescription();
	printAbyssDescription();
	printBeaconDescription();
	printBlackwaterDescription();
	printMaltaDescription();
	printFoldWeaponDescription();
	printHarmonyDescription();
	printTerritoryDescription();
	//End Room Descriptions*/

	return 0;
}

int printGauntletDescription(void) {
	printf("The Gauntlet: Training simulation, beginning of the game\n");
	return 0;
}

int printCrashSiteDescription(void) {
	printf("Crash Site: Location of the James MacAllen crash landing, infantry combat\n");
	return 0;
}

int printDrydockDescription(void) {
	printf("Drydock: Sewage processing facility, close quarters combat, titan combat\n");
	return 0;
}

int printComplexDescription(void) {
	printf("Complex: A research complex of unknown use, pilot movement\n");
	return 0;
}

int printAbyssDescription(void) {
	printf("The Abyss: A massive simulation dome building complex, titan combat, pilot movement\n");
	return 0;
}

int printBeaconDescription(void) {
	printf("The Beacon: An IMC interstellar beacon, pilot movement and combat\n");
	return 0;
}

int printBlackwaterDescription(void) {
	printf("Blackwater Canal: IMC shipping port, titan combat\n");
	return 0;
}

int printMaltaDescription(void) {
	printf("The Malta: Airborne battle fought on and around the IMC Malta while chasing the IMC Draconis, pilot combat\n");
	return 0;
}

int printFoldWeaponDescription(void) {
	printf("The Fold Weapon: IMC firing station, pilot movement, titan movement\n");
	return 0;
}

int printHarmonyDescription(void) {
	printf("Harmony: Militia Headquarters, Final Room of the game\n");
	return 0;
}

int printTerritoryDescription(void) {
	printf("Uncharted Territory: An Unexplored and Uninhabited region of Typhon\n\n");
	return 0;
}





