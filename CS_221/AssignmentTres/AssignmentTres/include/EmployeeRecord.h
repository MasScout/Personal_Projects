//Mason Barrow
//Programming Assignment Three
//CS 221-01
//03/27/2020
//Employee Record Header File: EmployeeRecord Class Declaration

#pragma once

#include <iostream>
#include "CustomerList.h"

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
	int getDept();
	void setDept(int d);
	double getSalary();
	void setSalary(double sal);
	void printRecord();
	void removeCustomerList();
	void destroyCustomerList();

	CustomerList *getCustomerList();
	EmployeeRecord *m_pLeft;
	EmployeeRecord *m_pRight;

private:
	int m_iEmployeeID;
	char m_sLastName[32];
	char m_sFirstName[32];
	int m_iDeptID;
	double m_dSalary;

	CustomerList *m_pCustomerList;

	friend class EmployeeDatabase;
	friend int main();
};