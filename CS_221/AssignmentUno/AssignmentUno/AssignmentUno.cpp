// AssignmentUno.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
#include "EmployeeRecord.h"

using namespace std;

int main()
{
	EmployeeRecord employeeRecord;

	char lastName[32] = "Barrow";
	char firstName[32] = "Mason";

	int empID;
	char empLast[32];
	char empFirst[32];
	int empDept;
	double empSal;

	employeeRecord.setID(12345);
	empID = employeeRecord.getID();

	employeeRecord.setName(firstName, lastName);
	employeeRecord.getName(empFirst, empLast);

	employeeRecord.setDept(123);
	employeeRecord.getDept(empDept);

	employeeRecord.setSalary(50000);
	employeeRecord.getSalary(&empSal);

#ifdef TESTING
	if (empID != 12345) {
		cout << "ID not consistent" << endl;
	}
#endif
	//employeeRecord.printRecord();

	EmployeeRecord record(1234, firstName, lastName, 13, 550000.0);
	record.printRecord();

    return 0;
}

*/

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include "EmployeeRecord.h"

using namespace std;

int main(void)
{
	int id;
	char fName[32], lName[32];
	int d;
	double sal;

	cout << "========================================================================\n";
	cout << "                   TEST OF PROGRAMMING ASSIGNMENT 1\n";
	cout << "========================================================================\n\n";

	cout << "Instantiating an EmployeeRecord object using default constructor.\n";
	cout.flush();
	EmployeeRecord *rec1 = new EmployeeRecord();
	cout << "Setting data in record: \n\tID=100 \n\tLast Name=Doe \n\tFirst Name=John "
		<< "\n\tDept=42 \n\tSalary=$65,000\n";
	rec1->setID(100);
	rec1->setName((char *)"John", (char *)"Doe");
	rec1->setDept(42);
	rec1->setSalary(65000);
	cout << "...done\n";
	cout.flush();

	// Test getID()
	cout << "Testing getID(). ";
	id = rec1->getID();
	cout << "Result = " << id << "\n";
	if (id == 100)
		cout << "getID appears to work.\n";
	else
		cout << "Failed to retrieve correct employee ID.\n";

	// Test getName()
	cout << "Testing getName(). ";
	rec1->getName(fName, lName);
	cout << "Result = " << fName << " " << lName << "\n";
	if ((strcmp(fName, "John") == 0) && (strcmp(lName, "Doe") == 0))
		cout << "getName appears to work.\n";
	else
		cout << "Failed to retrieve correct employee name.\n";

	// Test getDept()
	cout << "Testing getDept(). ";
	rec1->getDept(d);
	cout << "Result = " << d << "\n";
	if (d == 42)
		cout << "getDept appears to work.\n";
	else
		cout << "Failed to retrieve correct employee department.\n";

	// Test getSalary()
	cout << "Testing getSalary(). ";
	rec1->getSalary(&sal);
	cout << "Result = " << sal << "\n";
	if (sal == 65000)
		cout << "getSalary appears to work.\n";
	else
		cout << "Failed to retrieve correct employee salary.\n";

	cout << "Calling printRecord() function.\n\n";
	rec1->printRecord();
	cout << "\n\n";

	cout << "========================================================================\n\n";
	cout << "Instantiating an EmployeeRecord object using parameterized constructor,\n";
	cout << "and setting data in record: \n\tID=101\n\tLast Name=Smith\n\tFirst Name=Jane "
		<< "\n\tDept=44\n\tSalary=$65,500\n";
	EmployeeRecord *rec2 = new EmployeeRecord(101, (char *)"Jane", (char *)"Smith", 44, 65500);

	// Test getID()
	cout << "Testing getID(). ";
	id = rec2->getID();
	cout << "Result = " << id << "\n";
	if (id == 101)
		cout << "getID seems to work when parameterized constructor is used.\n";
	else
		cout << "Failed to retrieve correct Id of 101 in rec2\n";

	// Test getName()
	cout << "Testing getName(). ";
	rec2->getName(fName, lName);
	cout << "Result = " << fName << " " << lName << "\n";
	if ((strcmp(fName, "Jane") == 0) && (strcmp(lName, "Smith") == 0))
		cout << "getName seems to work when parameterized constructor is used.\n";
	else
		cout << "Failed to retrieve correct name of Jane Smith in rec2\n";

	// Test getDept()
	cout << "Testing getDept(). ";
	rec2->getDept(d);
	cout << "Result = " << d << "\n";
	if (d == 44)
		cout << "getDept seems to work when parameterized constructor is used.\n";
	else
		cout << "Failed to retrieve correct department of 44 in rec2\n";

	// Test getSalary()
	cout << "Testing getSalary(). ";
	rec2->getSalary(&sal);
	cout << "Result = " << sal << "\n";
	if (sal == 65500)
		cout << "getSalary seems to work when parameterized constructor is used.\n";
	else
		cout << "\nFailed to retrieve correct salary of 65500 in rec2\n";

	cout << "Calling printRecord() function.\n\n";
	rec2->printRecord();
	cout << "\n\n";
	cout << "========================================================================\n";
	cout << "========================================================================\n\n";
	cout << "Press Enter to continue...";
	system("pause");
	return 0;
}