// AssignmentUno.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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

