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
void describeRoomContents(int roomDesc, int row, int col);
void buildRooms(unsigned int rooms[][4]);

#define DOOR_NORTH 0x00000001
#define DOOR_EAST 0x00000002
#define DOOR_SOUTH 0x00000004
#define DOOR_WEST 0x00000008

#define PILOT_JUMPKIT 0x00000010
#define KANE_HELMET 0x00000020
#define ANDERSON_HELMET 0x00000040
#define BT_DATA_CORE 0x00000080

#define LASTIMOSA 0x00000100
#define BRIGGS 0x00000200
#define MILITIA_INFANTRY 0x00000400
#define MILITIA_TITANS 0x00000800
#define MRVNS 0x00001000
#define IMC_INFANTRY 0x00002000
#define IMC_TITANS 0x00004000
#define MERCENARIES 0x00008000

#define DEADLY 0x00010000
#define DANGEROUS 0x00020000
#define HELPFUL 0x00040000
#define HARMLESS 0x00080000

int main()
{
	//Initialize Variables
	string cmdVerb;
	string cmdObj;
	int iRow;
	int iCol;
	int iNumRow;
	int iNumCol;
	int roomTest = 0xFFFFFFFF;
	unsigned int typhon[4][4];
	int i, j = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			typhon[i][j] = 0;
		}
	}
	buildRooms(typhon);

	iRow = 0; //Start at row 0
	iCol = 0; //Start at column 0
	iNumRow = 4; //4 rows on board
	iNumCol = 4; //4 columns on board

	char quitChoice = 'n'; //Confirmation for quiting the game

	//BEGIN INSTRUCTIONS
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
	printf("prompted to battle them with on screen prompts. You may quit the game at any time by \n");
	printf("typing QUIT GAME. Good luck, have fun!\n\n");
	//END INSTRUCTIONS

	//cout << "You are currently on row " << iRow << ", column " << iCol << endl;

	cout << "Press the Enter key to begin";
	getc(stdin);
	cout << "" << endl;
	describeRoomContents(typhon[0][0], 0, 0);

	//BEGIN GAME LOOP
	while (quitChoice == 'n') {
		//ACTION COMMAND
		cout << "\nWhat would you like to do? ";
		cin >> cmdVerb >> cmdObj;
		cout << endl;

		//CAPITALIZE USER INPUT
		transform(cmdVerb.begin(), cmdVerb.end(), cmdVerb.begin(), ::toupper);
		transform(cmdObj.begin(), cmdObj.end(), cmdObj.begin(), ::toupper);


		//GO LOGIC
		if (cmdVerb == "GO") {
			if (cmdObj == "NORTH") {
				if (typhon[iRow][iCol] & DOOR_NORTH) {
					iRow--;
					cout << "GOING NORTH\n" << endl;
					describeRoomContents(typhon[iRow][iCol], iRow, iCol);
					
				}
				else {
					cout << "You can't go north from this sector" << endl;
				}

			}
			else if (cmdObj == "EAST") {
				if (typhon[iRow][iCol] & DOOR_EAST) {
					iCol++;
					cout << "GOING EAST\n" << endl;
					describeRoomContents(typhon[iRow][iCol], iRow, iCol);
					
				}
				else {
					cout << "You can't go east from this sector" << endl;
				}

			}
			else if (cmdObj == "SOUTH") {
				if (typhon[iRow][iCol] & DOOR_SOUTH) {
					iRow++;
					cout << "GOING SOUTH\n" << endl;
					describeRoomContents(typhon[iRow][iCol], iRow, iCol);
				}
				else {
					cout << "You can't go south from this sector" << endl;
				}

			}
			else if (cmdObj == "WEST") {
				if (typhon[iRow][iCol] & DOOR_WEST) {
					iCol--;
					cout << "GOING WEST\n" << endl;
					describeRoomContents(typhon[iRow][iCol], iRow, iCol);
					
				}
				else {
					cout << "You can't go West from this sector" << endl;
				}

			}
			else {
				cout << "Please enter a valid direction (ie. NORTH, EAST, SOUTH, WEST)" << endl;
			}
		}

		//TAKE LOGIC
		else if (cmdVerb == "TAKE") {
			cout << "There is nothing to take yet" << endl;
		}

		//QUIT LOGIC
		else if (cmdVerb == "QUIT") {
			cout << "Are you sure you want to quit? (y/n)" << endl;
			cin >> quitChoice;
			if (quitChoice == 'y') {
				quitChoice = 'y';
				return 0;
			}
			else if (quitChoice == 'n') {
				exit;
			}
			else {
				cout << quitChoice << " is not a valid option, please select y or n" << endl;
			}
		}

		//UNKNOWN VERB LOGIC
		else {
			cout << cmdVerb << " is not a valid option, please enter GO, TAKE, or QUIT" << endl;
		}
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

//BASIC ROOM DESCRIPTION FUNCTIONS
int printGauntletDescription(void) {
	printf("The Gauntlet: Training simulation, beginning of the game\n");
	return 0;
}

int printCrashSiteDescription(void) {
	printf("Crash Site: Location of the James MacAllen crash landing\n");
	return 0;
}

int printDrydockDescription(void) {
	printf("Drydock: Sewage processing facility\n");
	return 0;
}

int printComplexDescription(void) {
	printf("Complex: A research complex of unknown use\n");
	return 0;
}

int printAbyssDescription(void) {
	printf("The Abyss: A massive simulation dome building complex\n");
	return 0;
}

int printBeaconDescription(void) {
	printf("The Beacon: An IMC interstellar beacon\n");
	return 0;
}

int printBlackwaterDescription(void) {
	printf("Blackwater Canal: IMC shipping port\n");
	return 0;
}

int printMaltaDescription(void) {
	printf("The Malta: Airborne battle fought on and around the IMC Malta while chasing the IMC Draconis\n");
	return 0;
}

int printFoldWeaponDescription(void) {
	printf("The Fold Weapon: IMC firing station\n");
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

//DECIDES WHICH ROOM ^^^ TO PRINT
void describeRoomContents(int roomDesc, int row, int col) {
	switch (row) {
		case 0 :
			switch (col) {
				case 0:
					printGauntletDescription();
					break;
				case 1:
					printCrashSiteDescription();
					break;
				case 2:
					printTerritoryDescription();
					break;
				case 3:
					printDrydockDescription();
					break;	
			}
			break;
		case 1:
			switch (col) {
				case 0:
					printTerritoryDescription();
					break;
				case 1:
					printComplexDescription();
					break;
				case 2:
					printTerritoryDescription();
					break;
				case 3:
					printTerritoryDescription();
					break;
			}
			break;
		case 2:
			switch (col) {
				case 0:
					printAbyssDescription();
					break;
				case 1:
					printTerritoryDescription();
					break;
				case 2:
					printBeaconDescription();
					break;
				case 3:
					printTerritoryDescription();
					break;
			}
			break;
		case 3:
			switch (col) {
				case 0:
					printBlackwaterDescription();
					break;
				case 1:
					printMaltaDescription();
					break;
				case 2:
					printFoldWeaponDescription();
					break;
				case 3:
					printHarmonyDescription();
					break;
			}
			break;
	}

	//CREATURE, DOOR, AND OBJECT DESCRIPTIONS
	if (roomDesc & LASTIMOSA) {
		cout << "You can see Captain Lastimosa ahead" << endl;
	}
	if (roomDesc & BRIGGS) {
		cout << "You can see Commander Briggs ahead" << endl;
	}
	if (roomDesc & MILITIA_INFANTRY) {
		cout << "Militia Infantry detected ahead" << endl;
	}
	if (roomDesc & MILITIA_TITANS) {
		cout << "Militia Titans detected ahead" << endl;
	}
	if (roomDesc & MRVNS) {
		cout << "You can see MRVNs up ahead" << endl;
	}
	if (roomDesc & IMC_INFANTRY) {
		cout << "IMC Infantry detected ahead" << endl;
	}
	if (roomDesc & IMC_TITANS) {
		cout << "IMC Titans detected ahead" << endl;
	}
	if (roomDesc & MERCENARIES) {
		cout << "Mercenaries detected ahead" << endl;
	}
	
	if (roomDesc & DEADLY) {
		cout << "These are deadly - upgraded Titan Loadout is recommended" << endl;
	}
	if (roomDesc & DANGEROUS) {
		cout << "These are dangerous, proceed with caution" << endl;
	}
	if (roomDesc & HELPFUL) {
		cout << "These are friendly, and may be of assistance to you" << endl;
	}
	if (roomDesc & HARMLESS) {
		cout << "These do nothing but stand there and look pretty" << endl;
	}

	if (roomDesc & PILOT_JUMPKIT) {
		cout << "You can see Lastimosa's Jumpkit - it is yours now. Use it well." << endl;
	}
	if (roomDesc & KANE_HELMET) {
		cout << "Kane's Helmet is still intact. Its radio will provide us with enemy information" << endl;
	}
	if (roomDesc & ANDERSON_HELMET) {
		cout << "You can see Anderson's Helmet protruding through the ceiling." << endl;
	}
	if (roomDesc & BT_DATA_CORE) {
		cout << "BT's Data Core has become detached. Retrieve it - it is your only chance of survival." << endl;
	}

	if (roomDesc & DOOR_NORTH) {
		cout << "You may go North" << endl;
	}
	if (roomDesc & DOOR_EAST) {
		cout << "You may go East" << endl;
	}
	if (roomDesc & DOOR_SOUTH) {
		cout << "You may go South" << endl;
	}
	if (roomDesc & DOOR_WEST) {
		cout << "You may go West" << endl;
	}
}

//BUILD ALL ROOMS FUNCTION
void buildRooms(unsigned int rooms[][4]) {
	rooms[0][0] = DOOR_EAST | LASTIMOSA | HELPFUL; //GAUNTLET 
	rooms[0][1] = DOOR_EAST | DOOR_SOUTH | DOOR_WEST | IMC_INFANTRY | DANGEROUS | PILOT_JUMPKIT; //CRASH SITE
	rooms[0][2] = DOOR_EAST | DOOR_SOUTH | DOOR_WEST; //UNCHARTED TERRITORY
	rooms[0][3] = DOOR_SOUTH | DOOR_WEST | IMC_INFANTRY | DANGEROUS | MILITIA_INFANTRY | HELPFUL| MERCENARIES | DEADLY | KANE_HELMET; //DRYDOCK
	rooms[1][0] = DOOR_EAST | DOOR_SOUTH; //UNCHARTED TERRITORY
	rooms[1][1] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST | IMC_INFANTRY | DANGEROUS | ANDERSON_HELMET; //COMPLEX
	rooms[1][2] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST; //UNCHARTED TERRITORY
	rooms[1][3] = DOOR_NORTH | DOOR_SOUTH | DOOR_WEST; //UNCHARTED TERRITORY
	rooms[2][0] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | MRVNS | HARMLESS; //ABYSS
	rooms[2][1] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST; //UNCHARTED TERRITORY
	rooms[2][2] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST | IMC_INFANTRY | DANGEROUS | MERCENARIES | DEADLY; //BEACON
	rooms[2][3] = DOOR_NORTH | DOOR_SOUTH | DOOR_WEST; //UNCHARTED TERRITORY
	rooms[3][0] = DOOR_NORTH | DOOR_EAST | IMC_TITANS | DANGEROUS | MILITIA_TITANS | HELPFUL | BRIGGS | HELPFUL; //BLACKWATER CANAL
	rooms[3][1] = DOOR_NORTH | DOOR_EAST | DOOR_WEST | IMC_INFANTRY | DANGEROUS | MERCENARIES | DEADLY; //THE MALTA
	rooms[3][2] = DOOR_NORTH | DOOR_EAST | DOOR_WEST | IMC_INFANTRY | DANGEROUS | IMC_TITANS | DANGEROUS | MERCENARIES | DEADLY | BT_DATA_CORE; //FOLD WEAPON
	rooms[3][3] = DOOR_NORTH | DOOR_WEST; //HARMONY
}
