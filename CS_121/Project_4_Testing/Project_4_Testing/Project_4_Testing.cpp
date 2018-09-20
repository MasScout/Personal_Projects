// Project4.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <stdio.h>


int main()
{
	//Initializations
	char ContinueChoice; //Anytime player chooses to continue the game, call this variable
	int PlayerLocation; //Set up 4x4 grid labled 1-16 from top left to bottom right

	
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

	//Ready to Begin?
	ContinueChoice = 'y';
	printf("Are you ready to begin? (y/n)\t");
	scanf_s(&ContinueChoice, '%c');
	if (ContinueChoice = 'n') {
		printf("\nBye!\n\n");
	}
	else if(ContinueChoice = 'y') {
		//All code goes here
		printf("\nHere we go, Rifleman\n\n");
	}
	else {
		printf("\nInvalid choice, try again!\n");
	}

	return 0;
}

