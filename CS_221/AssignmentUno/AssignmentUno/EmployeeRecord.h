//Mason Barrow
//Programming Assignment One
//CS 221-01
//02/04/2020
//Employee Record Header File: EmployeeRecord Class Declaration

#pragma once

#include <iostream>

//#define TESTING

//Define Class
class EmployeeRecord {
public:
	EmployeeRecord();
	EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal);
	~EmployeeRecord();
	int getID();
	void setID(int ID);
	void getName(char *fName, char *lName);
	void setName(char *fName, char *lName);
	void getDept(int& d);
	void setDept(int d);
	void getSalary(double *sal);
	void setSalary(double sal);
	void printRecord();
private:
	int m_iEmployeeID;
	char m_sLastName[32];
	char m_sFirstName[32];
	int m_iDeptID;
	double m_dSalary;
};