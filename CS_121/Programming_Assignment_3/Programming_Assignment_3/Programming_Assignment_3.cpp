// Programming_Assignment_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

//INITIALIZE FUNCTIONS
void SayYouWon();
void SayYouLost();
bool CheckGuess(int playerGuess, int value);
int GetRandomNumber();

int main()
{
	srand((unsigned int)(time(NULL)));
	
	//INITIALIZE VARIABLES
	int value;
	int playerGuess;
	int wins = 0;
	int losses = 0;
	char quitChoice = 'y';

	cout << "Welcome to the Guessing Game! You will have 20 tries to guess a number 1-100, and you will be helped by hints along the way.\n" << endl;

	//MAIN LOOP TO RUN WHILE USER WANTS TO KEEP GOING
	while (quitChoice == 'y') {

		value = GetRandomNumber();

		//LOGIC FOR NUMBER OF TRIES THE PLAYER GETS
		for (int i = 1; i <= 20; i++) {
			cout << "\nEnter your Guess: ";
			cin >> playerGuess;
			//LOGIC FOR IF THE PLAYER GETS IT RIGHT
			if (CheckGuess(playerGuess, value) == true) {
				SayYouWon();
				cout << "It took you " << i << " tries." << endl;
				wins++;
				break;
			}
			//LOGIC FOR IF THE PLAYER DOESN'T GET IT RIGHT IN 20 TRIES
			else if (i == 19 && CheckGuess(playerGuess, value) == false) {
				SayYouLost();
				losses++;
				break;
			}
		}
				
		cout << "Would you like to play again? (y/n) ";
		cin >> quitChoice;
	}
	
	cout << "You have " << wins << " wins and " << losses << " losses." << endl;
	

    return 0;
}

//FUNCTION TO PRINT RANDOM WIN MESSAGE
void SayYouWon() {
	int value = rand() % 4 + 1;
	switch (value) {
		case 1:
			cout << "Great Guessing!" << endl;
			break;
		case 2:
			cout << "Congrats, You Won!" << endl;
			break;
		case 3:
			cout << "Winner Winner Chicken Dinner!" << endl;
			break;
		case 4:
			cout << "You Got It, Suberb Job!" << endl;
			break;
	}
}

//FUNCTION TO PRINT RANDOM LOSE MESSAGE
void SayYouLost() {
	int value = rand() % 3 + 1;
	switch (value) {
		case 1:
			cout << "Better luck next time." << endl;
			break;
		case 2:
			cout << "Mission Failed - we'll get 'em next time." << endl;
			break;
		case 3:
			cout << "Tough loss, good try." << endl;
			break;
	}
}

//FUNCTION TO GIVE HINT DEPENDING ON THE ACCURACY OF THE GUESS
bool CheckGuess(int playerGuess, int value) {
	if (playerGuess == value) {
		return true;
	}
	else if (abs(playerGuess - value) <= 1) {
		cout << "You're burning up!" << endl;
		return false;
	}
	else if (abs(playerGuess - value) <= 5 && abs(playerGuess - value) > 1) {
		cout << "Getting Hotter!" << endl;
		return false;
	}
	else if (abs(playerGuess - value) <= 10 && abs(playerGuess - value) > 5) {
		cout << "Warmer..." << endl;
		return false;
	}
	else if (abs(playerGuess - value) <= 25 && abs(playerGuess - value) > 10) {
		cout << "Pretty cold." << endl;
		return false;
	}
	else if (abs(playerGuess - value) <= 99 && abs(playerGuess - value) > 25) {
		cout << "Are you even trying?" << endl;
		return false;
	}
	else {
		cout << "The number is 1 - 100, your's is not. Try again.";
		return false;
	}
}

//RANDOM NUMBER FUNCTION
int GetRandomNumber() {
	int value;
	value = rand() % 100 + 1;
	return value;
}

