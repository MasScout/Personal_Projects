// BasicLogicHackathon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#define LINES 155
#define COLUMNS 11

using namespace std;


int main()
{
	string genomeData[156][11] = {};
		
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
	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 11; j++) {
			walk1[i][j] = genomeData[i][j];
		}
	}
	string walk2[23][11] = {};
	for (int i = 23; i < 46; i++) {
		for (int j = 0; j < 11; j++) {
			walk2[i][j] = genomeData[i][j];
		}
	}
	string walk3[23][11] = {};
	for (int i = 46; i < 69; i++) {
		for (int j = 0; j < 11; j++) {
			walk3[i][j] = genomeData[i][j];
		}
	}
	string walk4[23][11] = {};
	for (int i = 69; i < 92; i++) {
		for (int j = 0; j < 11; j++) {
			walk4[i][j] = genomeData[i][j];
		}
	}
	string walk5[23][11] = {};
	for (int i = 92; i < 115; i++) {
		for (int j = 0; j < 11; j++) {
			walk5[i][j] = genomeData[i][j];
		}
	}
	string walk6[23][11] = {};
	for (int i = 115; i < 138; i++) {
		for (int j = 0; j < 11; j++) {
			walk6[i][j] = genomeData[i][j];
		}
	}
	string walk7[23][11] = {};
	for (int i = 138; i < 155; i++) {
		for (int j = 0; j < 11; j++) {
			walk7[i][j] = genomeData[i][j];
		}
	}
	return 0;
}

