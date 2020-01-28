#include "stdafx.h"
#include "EmployeeRecord.h"

using namespace std;

EmployeeRecord::EmployeeRecord() {
	cout << "Default Constructor" << endl;
	m_iEmployeeID = 0;
	strcpy(m_sLastName, "");
	strcpy(m_sFirstName, "");
	m_iDeptID = 0;
	m_dSalary = 0.0;
}

EmployeeRecord::EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal) {
	cout << "Constructor" << endl;
	m_iEmployeeID = ID;
	strcpy(m_sLastName, lName);
	strcpy(m_sFirstName, fName);
	m_iDeptID = dept;
	m_dSalary = sal;
}

EmployeeRecord::~EmployeeRecord() {
	cout << "Destructor" << endl;
}

int EmployeeRecord::getID() {
	cout << "getID" << endl;
	return 0;
}

void EmployeeRecord::setID(int ID) {
	cout << "setID" << endl;
}

void EmployeeRecord::getName(char *fName, char *lName) {
	cout << "getName" << endl;
}


void EmployeeRecord::setName(char *fName, char *lName) {
	cout << "setName" << endl;
}

void EmployeeRecord::getDept(int& d) {
	cout << "getDept" << endl;
}

void EmployeeRecord::setDept(int d) {
	cout << "setDept" << endl;
}

void EmployeeRecord::getSalary(double *sal) {
	cout << "getSalary" << endl;
}

void EmployeeRecord::setSalary(double sal) {
	cout << "setSalary" << endl;
}

void EmployeeRecord::printRecord() {
	cout << "printRecord" << endl;
}