//Mason Barrow
//Programming Assignment One
//CS 221-01
//02/04/2020
//Employee Record Source File: EmployeeRecord Class Definition

#include "stdafx.h"
#include "EmployeeRecord.h"

using namespace std;

//Brief: Default Constructor
EmployeeRecord::EmployeeRecord() {
#ifdef TESTING
	cout << "Default Constructor" << endl;
#endif
	m_iEmployeeID = 0;
	strcpy(m_sLastName, "");
	strcpy(m_sFirstName, "");
	m_iDeptID = 0;
	m_dSalary = 0.0;

	m_pCustomerList = new CustomerList;
}

//Brief: Parameterized Constructor
EmployeeRecord::EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal) {
#ifdef TESTING
	cout << "Constructor" << endl;
#endif
	m_iEmployeeID = ID;
	strcpy(m_sLastName, lName);
	strcpy(m_sFirstName, fName);
	m_iDeptID = dept;
	m_dSalary = sal;

	m_pCustomerList = new CustomerList;
}

//Brief: Destructor
EmployeeRecord::~EmployeeRecord() {
#ifdef TESTING
	cout << "Destructor" << endl;
#endif
	delete m_pCustomerList;
}

//Brief: Function to return employee ID
int EmployeeRecord::getID() {
#ifdef TESTING
	cout << "getID" << endl;
#endif
	return m_iEmployeeID;
}

//Brief: Function to set m_iEmployeeID private variable as argument
void EmployeeRecord::setID(int ID) {
#ifdef TESTING
	cout << "setID: " << ID << endl;
#endif
	m_iEmployeeID = ID;
}

//Brief: Function to copy private variables into function argument variables
void EmployeeRecord::getName(char *fName, char *lName) {
#ifdef TESTING
	cout << "getName" << endl;
#endif
	strcpy(lName, m_sLastName);
	strcpy(fName, m_sFirstName);
}

//Brief: Function to copy function argument variables into private variables
void EmployeeRecord::setName(char *fName, char *lName) {
#ifdef TESTING
	cout << "setName" << endl;
#endif
	strcpy(m_sLastName, lName);
	strcpy(m_sFirstName, fName);
}

//Brief: Function to set function argument variable as m_iDeptID
int EmployeeRecord::getDept() {
#ifdef TESTING
	cout << "getDept" << endl;
#endif
	return m_iDeptID;
}

//Brief: Function to set m_iDeptID as function argument variable
void EmployeeRecord::setDept(int d) {
#ifdef TESTING
	cout << "setDept" << endl;
#endif
	m_iDeptID = d;
}

//Brief: Function to set function argument variable as m_dSalary
double EmployeeRecord::getSalary() {
#ifdef TESTING
	cout << "getSalary" << endl;
#endif
	return m_dSalary;
}

//Brief: Function to set m_dSalary as function argument variable
void EmployeeRecord::setSalary(double sal) {
#ifdef TESTING
	cout << "setSalary" << endl;
#endif	
	m_dSalary = sal;
}

//Brief: Function to display all Employee Information
void EmployeeRecord::printRecord() {
#ifdef TESTING
	cout << "printRecord" << endl;
#endif
	cout << "Employee ID: " << m_iEmployeeID << endl;
	cout << "Employee Name: " << m_sLastName << ", " << m_sFirstName << endl;
	cout << "Employee Dept: " << m_iDeptID << endl;
	cout << "Employee Salary: " << m_dSalary << endl;
}

CustomerList *EmployeeRecord::getCustomerList() {
	return m_pCustomerList;
}