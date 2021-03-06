// Arrays_Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//DEFINE DIMENSIONS FOR EASY USE
#define LAYER 2
#define ROW 4
#define COLUMN 8


int main()
{
	//INITIALIZE ARRAY AND DIMENSION VALUES
	int main_array[LAYER][ROW][COLUMN];
	int x, y, z = 0;
	int value = 0;
	
	//THREE FOR LOOPS FOR THREE DIMENSIONS
	for (x = 0; x < LAYER; x++) {
		for (y = 0; y < ROW; y++) {
			for (z = 0; z < COLUMN; z++) {
				value = (x + 1)*(y + 1)*(z + 1);
				cout << "Main_Array[" << x << "][" << y << "][" << z << "] = " << value << endl;
			}
		}
	}
	
	return 0;
}

