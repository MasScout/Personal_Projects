// BasicLogicHackathon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

#define LINES 155
#define COLUMNS 11

using namespace std;

int getRandomNumber();
//string walkInit(string genomeData[155][11]);

int main()
{
	string genomeData[156][11] = {};
	int value;
		
	ifstream fileNames[11];
	for (int i = 0; i < COLUMNS; i++) {
		ostringstream filename;
		filename << "myData" << i << ".txt";
		fileNames[i].open(filename.str());
		if (!fileNames[i].is_open()) exit(0);
		for (int line = 0; line < LINES; line++) {
			getline(fileNames[i], genomeData[line][i]);
		}
	}
	
	string walk1[23][11] = {};
	int k = 0;
	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 11; j++) {
			walk1[k][j] = genomeData[i][j];
		}
		k++;
	}

	string walk2[23][11] = {};
	k = 0;
	for (int i = 23; i < 46; i++) {
		for (int j = 0; j < 11; j++) {
			walk2[k][j] = genomeData[i][j];
		}
		k++;
	}
	
	string walk3[23][11] = {};
	k = 0;
	for (int i = 46; i < 69; i++) {
		for (int j = 0; j < 11; j++) {
			walk3[k][j] = genomeData[i][j];
		}
		k++;
	}
	
	string walk4[23][11] = {};
	k = 0;
	for (int i = 69; i < 92; i++) {
		for (int j = 0; j < 11; j++) {
			walk4[k][j] = genomeData[i][j];
		}
		k++;
	}

	string walk5[23][11] = {};
	k = 0;
	for (int i = 92; i < 115; i++) {
		for (int j = 0; j < 11; j++) {
			walk5[k][j] = genomeData[i][j];
		}
		k++;
	}

	string walk6[23][11] = {};
	k = 0;
	for (int i = 115; i < 138; i++) {
		for (int j = 0; j < 11; j++) {
			walk6[k][j] = genomeData[i][j];
		}
		k++;
	}
	
	string walk7[23][11] = {};
	k = 0;
	for (int i = 138; i < 155; i++) {
		for (int j = 0; j < 11; j++) {
			walk7[k][j] = genomeData[i][j];
		}
		k++;
	}
	for (int i = 15; i < 137; i = i + 25) {
		for (int j = 0; j < 11; j++) {
			walk7[k][j] = genomeData[i][j];
		}
		k++;
	}
	//walkInit(genomeData[LINES][COLUMNS]);
	
	srand((unsigned int)(time(NULL)));
	
	value = getRandomNumber();
	cout << value;

	return 0;
}


int getRandomNumber() {
	int value;
	value = rand() % 6 + 1;
	return value;
}

/*string walkInit(string genomeData[155][11]) {
	//Initialize various walk functions
	string walk1[23][11] = {};
	int k = 0;
	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 11; j++) {
			walk1[k][j] = genomeData[i][j];
		}
		k++;
	}
	string walk2[23][11] = {};
	k = 0;
	for (int i = 23; i < 46; i++) {
		for (int j = 0; j < 11; j++) {
			walk2[k][j] = genomeData[i][j];
		}
		k++;
	}
	string walk3[23][11] = {};
	for (int i = 46; i < 69; i++) {
		for (int j = 0; j < 11; j++) {
			walk3[k][j] = genomeData[i][j];
		}
		k++;
	}
	string walk4[23][11] = {};
	for (int i = 69; i < 92; i++) {
		for (int j = 0; j < 11; j++) {
			walk4[k][j] = genomeData[i][j];
		}
		k++;
	}
	string walk5[23][11] = {};
	for (int i = 92; i < 115; i++) {
		for (int j = 0; j < 11; j++) {
			walk5[k][j] = genomeData[i][j];
		}
		k++;
	}
	string walk6[23][11] = {};
	for (int i = 115; i < 138; i++) {
		for (int j = 0; j < 11; j++) {
			walk6[k][j] = genomeData[i][j];
		}
		k++;
	}
	string walk7[23][11] = {};
	for (int i = 138; i < 155; i++) {
		for (int j = 0; j < 11; j++) {
			walk7[k][j] = genomeData[i][j];
		}
		k++;
	}
	for (int i = 15; i < 137; i = i + 25) {
		for (int j = 0; j < 11; j++) {
			walk7[k][j] = genomeData[i][j];
		}
		k++;
	}

	return walk1[23][11];
	return walk2[23][11];
	return walk3[23][11];
	return walk4[23][11];
	return walk5[23][11];
	return walk6[23][11];
	return walk7[23][11];
}*/