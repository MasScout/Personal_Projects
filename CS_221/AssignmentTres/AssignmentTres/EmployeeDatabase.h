//Mason Barrow
//Programming Assignment Three
//CS 221-01
//03/27/2020
//Employee Database Header File: EmployeeDatabase Class Declaration

#pragma once

#include <iostream>
#include <fstream>
#include "EmployeeRecord.h"

class EmployeeDatabase {
public:
	EmployeeDatabase();
	~EmployeeDatabase();
	bool addEmployee(EmployeeRecord *e);
	EmployeeRecord *getEmployee(int ID);
	EmployeeRecord *removeEmployee(int ID);
	void printEmployeeRecords();
	bool buildDatabase(char *dataFile);

private:
	void printEmployeeRecords(EmployeeRecord *rt);
	void destroyTree(EmployeeRecord *rt);
	bool getNextLine(char *line, int lineLen);

	EmployeeRecord *m_pRoot;
	ifstream inFile;

	friend int main();
};

