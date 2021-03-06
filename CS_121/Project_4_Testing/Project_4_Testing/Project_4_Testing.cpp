// Project4.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int playGauntlet(void);
int playCrashSite(void);
int playDrydock(void);
int playComplex(void);
int playAbyss(void);
int playBeacon(void);
int playBlackwater(void);
int playMalta(void);
int playFoldWeapon(void);
int playHarmony(void);
int playTerritory(void);
void describeRoomContents(int roomDesc, int row, int col);
void buildRooms(unsigned int rooms[][4]);
int takeItem(unsigned int rooms[][4], int row, int col, string Object);
bool fightCompletion(unsigned int rooms[][4], int row, int col, string Object);
//void enterToContinue(void);
//int useCommand(string object);

#define DOOR_NORTH 0x00000001
#define DOOR_EAST 0x00000002
#define DOOR_SOUTH 0x00000004
#define DOOR_WEST 0x00000008

#define JUMPKIT 0x00000010
#define RADIO 0x00000020
#define HELMET 0x00000040
#define DATACORE 0x00000080

#define KANE 0x00000100
#define ASH 0x00000200
#define RICHTER 0x00000400
#define VIPER 0x00000800
#define SLONE 0x00001000
#define MILITIA 0x00002000
#define IMC 0x00004000
#define MRVNS 0x00008000

#define DEADLY 0x00010000
#define DANGEROUS 0x00020000
#define HELPFUL 0x00040000
#define HARMLESS 0x00080000

#define EXPEDITION 0x00100000
#define TONE 0x00200000
#define SCORCH 0x00400000
#define BRUTE 0x00800000
#define ION 0x01000000
#define RONIN 0x02000000
#define NORTHSTAR 0x04000000
#define LEGION 0x08000000

//GLOBAL VARIABLES
int iPlayer = 0;
int iRow;
int iCol;
unsigned int typhon[4][4];
string cmdVerb;
string cmdObj;

int main()
{
	//Initialize Variables
	int iNumRow;
	int iNumCol;
	int roomTest = 0xFFFFFFFF;
	int i, j = 0;
	int endRow = 3;
	int endCol = 3;
	bool embarkStatus = false;

	//BUILD ROOMS TO 0 VALUES
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
	printf("JUMPKIT, TAKE EXPEDITION, etc.). If you encounter deadly characters, you will be \n");
	printf("prompted to battle them with on screen prompts. These characters require certain \n");
	printf("titan loadouts to be defeated. You may quit the game at any time by \n");
	printf("typing QUIT GAME. Good luck, have fun!\n\n");
	//END INSTRUCTIONS

	//cout << "You are currently on row " << iRow << ", column " << iCol << endl;

	cout << "Press the Enter key to begin ";
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

			if ((iRow == endRow) && (iCol == endCol)) {
				if ((iPlayer & JUMPKIT) && (iPlayer & RADIO) && (iPlayer & HELMET) && (iPlayer & DATACORE)) {
					cout << "Well done! You've beaten the IMC and saved millions of people.\n" << endl;
					cout << "Take a break... You've earned it." << endl;
					quitChoice = 'y';
				}
				else {
					cout << "You don't have all the required items yet, keep hunting!" << endl;
				}
			}
		}

		//TAKE LOGIC
		else if (cmdVerb == "TAKE") {
			int takeVal = takeItem(typhon, iRow, iCol, cmdObj);
			if (takeVal) {
				iPlayer |= takeVal;
				cout << "You are now carrying " << cmdObj << endl;
			}
			else {
				cout << "You cannot take " << cmdObj << " from this location." << endl;
			}
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
int playGauntlet(void) {
	cout << "The Gauntlet: Training Simulation, beginning of game" << endl;	
	return 0;
}

int playCrashSite(void) {
	cout << "Crash Site: Location of the James MacAllen crash landing" << endl;
	return 0;
}

int playDrydock(void) {
	printf("Drydock: Sewage processing facility\n");
	return 0;
}

int playComplex(void) {
	printf("Complex: A research complex of unknown use\n");
	return 0;
}

int playAbyss(void) {
	printf("The Abyss: A massive simulation dome building complex\n");
	return 0;
}

int playBeacon(void) {
	printf("The Beacon: An IMC interstellar beacon\n");
	return 0;
}

int playBlackwater(void) {
	printf("Blackwater Canal: IMC shipping port\n");
	return 0;
}

int playMalta(void) {
	printf("The Malta: Airborne battle fought on and around the IMC Malta while chasing the IMC Draconis\n");
	return 0;
}

int playFoldWeapon(void) {
	printf("The Fold Weapon: IMC firing station\n");
	return 0;
}

int playHarmony(void) {
	printf("Harmony: Militia Headquarters, Final Room of the game\n");
	return 0;
}

int playTerritory(void) {
	printf("Uncharted Territory: An Unexplored and Uninhabited region of Typhon\n\n");
	return 0;
}

//DECIDES WHICH ROOM ^^^ TO PRINT
void describeRoomContents(int roomDesc, int row, int col) {
	switch (row) {
	case 0:
		switch (col) {
		case 0:
			playGauntlet();
			break;
		case 1:
			playCrashSite();
			break;
		case 2:
			playTerritory();
			break;
		case 3:
			playDrydock();
			break;
		}
		break;
	case 1:
		switch (col) {
		case 0:
			playTerritory();
			break;
		case 1:
			playComplex();
			break;
		case 2:
			playTerritory();
			break;
		case 3:
			playTerritory();
			break;
		}
		break;
	case 2:
		switch (col) {
		case 0:
			playAbyss();
			break;
		case 1:
			playTerritory();
			break;
		case 2:
			playBeacon();
			break;
		case 3:
			playTerritory();
			break;
		}
		break;
	case 3:
		switch (col) {
		case 0:
			playBlackwater();
			break;
		case 1:
			playMalta();
			break;
		case 2:
			playFoldWeapon();
			break;
		case 3:
			playHarmony();
			break;
		}
		break;
	}

	string loadout;
	unsigned int rooms[4][4];

	//CREATURE, DOOR, AND OBJECT DESCRIPTIONS
	
	//ITEM DESCRIPTIONS
	if (roomDesc & EXPEDITION) {
		cout << "Titan Loadout Found: EXPEDITION" << endl;
		cout << "Default Kit - Chaingun, Rocket Pods, Electric Smoke, and Vortex Shield." << endl;
	}
	if (roomDesc & TONE) {
		cout << "Titan Loadout Found: TONE" << endl;
		cout << "Tracking Kit - 40mm Cannon, Rocket Salvo for Lockons, Sonar Pulse, and Particle Wall." << endl;
	}
	if (roomDesc & SCORCH) {
		cout << "Titan Loadout Found: SCORCH" << endl;
		cout << "Fire Kit - Thermite Launcher, Gas Canisters, Firewall, and Flame Shield." << endl;
	}
	if (roomDesc & BRUTE) {
		cout << "Titan Loadout Found: BRUTE" << endl;
		cout << "Flying Kit - Quad Cannon, Rocket Pods, Hover, and Vortex Shield." << endl;
	}
	if (roomDesc & ION) {
		cout << "Titan Loadout Found: ION" << endl;
		cout << "Energy Kit - Splitter Rifle, Laser Shot, Laser Tripwire, and Vortex Shield." << endl;
	}
	if (roomDesc & RONIN) {
		cout << "Titan Loadout Found: RONIN" << endl;
		cout << "Melee Kit - Leadwall Shotgun, Arc Wave, Phase Dash, and Sword Block." << endl;
	}
	if (roomDesc & NORTHSTAR) {
		cout << "Titan Loadout Found: NORTHSTAR" << endl;
		cout << "Flying Kit - Particle Cannon, Cluster Missile, Hover, and Tether Traps." << endl;
	}
	if (roomDesc & LEGION) {
		cout << "Titan Loadout Found: LEGION" << endl;
		cout << "Heavy Kit - Heavy Machine Gun, Power Shot, Long/Short Range Mode, and Gun Shield." << endl;
	}

	//DANGER LEVEL FOR DEADLY (BECAUSE IT LOOKS BETTER HERE)
	if (roomDesc & DEADLY) {
		cout << "A deadly enemy is ahead - upgraded Titan Loadout is recommended" << endl;
	}
	
	//ENEMIES
	if (roomDesc & KANE) {
		cout << "Kane has come down to kick you out. He seems particularly susceptible to 40mm rounds..." << endl;
		if (iPlayer & TONE) {
			cout << "Which loadout would you like to use? ";
			cin >> loadout;
			transform(loadout.begin(), loadout.end(), loadout.begin(), ::toupper);
			while (loadout != "TONE") {
				cout << loadout << " wasn't very effective, try another one!" << endl;
				cout << "Which loadout would you like to use? ";
				cin >> loadout;
			}
			cout << "Congrats, you defeated Kane!" << endl;
			fightCompletion(typhon, iRow, iCol, loadout);
		}
		else {
			cout << "You don't have the required loadout!" << endl;
		}
	}
	if (roomDesc & ASH) {
		cout << "Ash is blocking your way out of the building facility. Flying around her seems to be very effective..." << endl;
		if ((iPlayer & BRUTE) || (iPlayer & NORTHSTAR)) {
			cout << "Which loadout would you like to use? ";
			cin >> loadout;
			transform(loadout.begin(), loadout.end(), loadout.begin(), ::toupper);
			while (loadout != "BRUTE") {
				cout << loadout << " wasn't very effective, try another one!" << endl;
				cout << "Which loadout would you like to use? ";
				cin >> loadout;
			}
			cout << "Congrats, you defeated Ash!" << endl;
			fightCompletion(typhon, iRow, iCol, loadout);
		}
		else {
			cout << "You don't have the required loadout!" << endl;
		}
	}
	if (roomDesc & RICHTER) {
		cout << "Richter doesn't like you messing with his beacon. A few well placed sword strikes should do the trick..." << endl;
		if (iPlayer & RONIN) {
			cout << "Which loadout would you like to use? ";
			cin >> loadout;
			transform(loadout.begin(), loadout.end(), loadout.begin(), ::toupper);
			while (loadout != "RONIN") {
				cout << loadout << " wasn't very effective, try another one!" << endl;
				cout << "Which loadout would you like to use? ";
				cin >> loadout;
			}
			cout << "Congrats, you defeated Richter!" << endl;
			fightCompletion(typhon, iRow, iCol, loadout);
		}
		else {
			cout << "You don't have the required loadout!" << endl;
		}
	}
	if (roomDesc & VIPER) {
		cout << "Viper's got you in the pipe, and is about to introduce you to the ground. A chaingun might be easiest..." << endl;
		if (iPlayer & EXPEDITION) {
			cout << "Which loadout would you like to use? ";
			cin >> loadout;
			transform(loadout.begin(), loadout.end(), loadout.begin(), ::toupper);
			while (loadout != "EXPEDITION") {
				cout << loadout << " wasn't very effective, try another one!" << endl;
				cout << "Which loadout would you like to use? ";
				cin >> loadout;
			}
			cout << "Congrats, you defeated Viper!" << endl;
			fightCompletion(typhon, iRow, iCol, loadout);
		}
		else {
			cout << "You don't have the required loadout!" << endl;
		}
	}
	if (roomDesc & SLONE) {
		cout << "Slone is protecting the Fold Weapon and you need to get past her. Dropping a few gas canisters at her feet will get the job done..." << endl;
		if (iPlayer & SCORCH) {
			cout << "Which loadout would you like to use? ";
			cin >> loadout;
			transform(loadout.begin(), loadout.end(), loadout.begin(), ::toupper);
			while (loadout != "SCORCH") {
				cout << loadout << " wasn't very effective, try another one!" << endl;
				cout << "Which loadout would you like to use? ";
				cin >> loadout;
			}
			cout << "Congrats, you defeated Slone!" << endl;
			fightCompletion(typhon, iRow, iCol, loadout);
		}
		else {
			cout << "You don't have the required loadout!" << endl;
		}
	}

	if (roomDesc & MILITIA) {
		cout << "Militia troops detected ahead..." << endl;
	}
	if (roomDesc & HELPFUL) {
		cout << "These are friendly, and may be of assistance to you" << endl;
	}

	if (roomDesc & IMC) {
		cout << "IMC troops detected ahead..." << endl;
	}
	if (roomDesc & DANGEROUS) {
		cout << "These are dangerous, proceed with caution" << endl;
	}

	if (roomDesc & MRVNS) {
		cout << "MRVNs detected ahead..." << endl;
	}	
	if (roomDesc & HARMLESS) {
		cout << "These do nothing but stand there and look pretty" << endl;
	}

	//TREASURE ITEMS
	if (roomDesc & JUMPKIT) {
		cout << "You can see Lastimosa's JUMPKIT - it is yours now. Use it well." << endl;
	}
	if (roomDesc & RADIO) {
		cout << "Kane's Helmet RADIO is still intact. It will provide us with enemy information" << endl;
	}
	if (roomDesc & HELMET) {
		cout << "You can see Anderson's HELMET protruding through the ceiling." << endl;
	}
	if (roomDesc & DATACORE) {
		cout << "BT's DATACORE has become detached. Retrieve it - it is your only chance of survival." << endl;
	}
	
	//DOORS
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
	rooms[0][0] = DOOR_EAST | MILITIA | HELPFUL; //GAUNTLET 
	rooms[0][1] = DOOR_EAST | DOOR_SOUTH | DOOR_WEST | IMC | DANGEROUS | JUMPKIT | EXPEDITION; //CRASH SITE
	rooms[0][2] = DOOR_EAST | DOOR_SOUTH | DOOR_WEST | TONE; //UNCHARTED TERRITORY
	rooms[0][3] = DOOR_SOUTH | DOOR_WEST | KANE | DEADLY | RADIO; //DRYDOCK
	rooms[1][0] = DOOR_EAST | DOOR_SOUTH | BRUTE; //UNCHARTED TERRITORY
	rooms[1][1] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST | IMC | DANGEROUS | HELMET | ION; //COMPLEX
	rooms[1][2] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST; //UNCHARTED TERRITORY
	rooms[1][3] = DOOR_NORTH | DOOR_SOUTH | DOOR_WEST | SCORCH; //UNCHARTED TERRITORY
	rooms[2][0] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | MRVNS | HARMLESS | ASH | DEADLY; //ABYSS
	rooms[2][1] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST | RONIN; //UNCHARTED TERRITORY
	rooms[2][2] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST | IMC | DANGEROUS | RICHTER | DEADLY; //BEACON
	rooms[2][3] = DOOR_NORTH | DOOR_SOUTH | DOOR_WEST | LEGION; //UNCHARTED TERRITORY
	rooms[3][0] = DOOR_NORTH | DOOR_EAST | IMC | DANGEROUS | MILITIA | HELPFUL | NORTHSTAR; //BLACKWATER CANAL
	rooms[3][1] = DOOR_NORTH | DOOR_EAST | DOOR_WEST | IMC | DANGEROUS | VIPER | DEADLY; //THE MALTA
	rooms[3][2] = DOOR_NORTH | DOOR_EAST | DOOR_WEST | IMC | DANGEROUS | SLONE | DEADLY | DATACORE; //FOLD WEAPON
	rooms[3][3] = DOOR_NORTH | DOOR_WEST; //HARMONY
}

//TAKE ITEMS FUNCTION
int takeItem(unsigned int rooms[][4], int row, int col, string Object) {
	if ((Object == "JUMPKIT") && (rooms[row][col] & JUMPKIT)) {
		rooms[row][col] ^= JUMPKIT;
		return JUMPKIT;
	}
	else if ((Object == "RADIO") && (rooms[row][col] & RADIO)) {
		rooms[row][col] ^= RADIO;
		return RADIO;
	}
	else if ((Object == "HELMET") && (rooms[row][col] & HELMET)) {
		rooms[row][col] ^= HELMET;
		return HELMET;
	}
	else if ((Object == "DATACORE") && (rooms[row][col] & DATACORE)) {
		rooms[row][col] ^= DATACORE;
		return DATACORE;
	}
	else if ((Object == "EXPEDITION") && (rooms[row][col] & EXPEDITION)) {
		rooms[row][col] ^= EXPEDITION;
		return EXPEDITION;
	}
	else if ((Object == "TONE") && (rooms[row][col] & TONE)) {
		rooms[row][col] ^= TONE;
		return TONE;
	}
	else if ((Object == "SCORCH") && (rooms[row][col] & SCORCH)) {
		rooms[row][col] ^= SCORCH;
		return SCORCH;
	}
	else if ((Object == "BRUTE") && (rooms[row][col] & BRUTE)) {
		rooms[row][col] ^= BRUTE;
		return BRUTE;
	}
	else if ((Object == "ION") && (rooms[row][col] & ION)) {
		rooms[row][col] ^= ION;
		return ION;
	}
	else if ((Object == "RONIN") && (rooms[row][col] & RONIN)) {
		rooms[row][col] ^= RONIN;
		return RONIN;
	}
	else if ((Object == "NORTHSTAR") && (rooms[row][col] & NORTHSTAR)) {
		rooms[row][col] ^= NORTHSTAR;
		return NORTHSTAR;
	}
	else if ((Object == "LEGION") && (rooms[row][col] & LEGION)) {
		rooms[row][col] ^= LEGION;
		return LEGION;
	}
	return 0;
}

bool fightCompletion(unsigned int rooms[][4], int row, int col, string Object) {
	if ((Object == "TONE") && (rooms[row][col] & KANE)) {
		rooms[row][col] ^= KANE;
		//return KANE;
		return true;
	}
	else if ((Object == "BRUTE") && (rooms[row][col] & ASH)) {
		rooms[row][col] ^= ASH;
		return ASH;
	}
	else if ((Object == "RONIN") && (rooms[row][col] & RICHTER)) {
		rooms[row][col] ^= RICHTER;
		return RICHTER;
	}
	else if ((Object == "EXPEDITION") && (rooms[row][col] & VIPER)) {
		rooms[row][col] ^= VIPER;
		return VIPER;
	}
	else if ((Object == "SCORCH") && (rooms[row][col] & SLONE)) {
		rooms[row][col] ^= SLONE;
		return SLONE;
	}
	else {
		return 0;
	}
}

/*void enterToContinue(void) {
	cout << "Press the Enter key to continue ";
	getc(stdin);
	cout << "" << endl;
}*/

/*int useCommand(string object) {
	if (object == "EXPEDITION"){
		return 1;
	}
	else if (object == "TONE") {
		return 2;
	}
	else if (object == "SCORCH") {
		return 3;
	}
	else if (object == "BRUTE") {
		return 4;
	}
	else if (object == "ION") {
		return 5;
	}
	else if (object == "RONIN") {
		return 6;
	}
	else if (object == "NORTHSTAR") {
		return 7;
	}
	else if (object == "LEGION") {
		return 8;
	}
	else {
		cout << "That is not a valid loadout. Please try again." << endl;
	}
}*/