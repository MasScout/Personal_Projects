// Project4.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>

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

	cout << "You are currently on row " << iRow << ", column " << iCol << endl;

	//Action Command
	cout << "\nWhat would you like to do? ";
	cin >> cmdVerb >> cmdObj;
	cout << endl;

	cout << cmdVerb.substr(0, 3) << "ing " << cmdObj << endl;

	//Begin Room Descriptions
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
	//End Room Descriptions

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





