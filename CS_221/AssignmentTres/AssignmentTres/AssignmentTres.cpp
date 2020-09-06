// AssignmentTres.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CustomerList.h"
#include "Store.h"
#include "EmployeeDatabase.h"

int main()
{
	EmployeeDatabase *database = new EmployeeDatabase();
	EmployeeRecord *record = new EmployeeRecord();
	EmployeeRecord *getRecord = new EmployeeRecord();
	EmployeeRecord *delrecord = new EmployeeRecord();

	char fileLoc[16] = "Prog3Data.txt";

	cout << "Building Database" << endl;
	database->buildDatabase(fileLoc);
	database->printEmployeeRecords();

	cout << "\nTesting Search Function" << endl;
	getRecord = database->getEmployee(1234);
	cout << "Searching for Employee 5678...";
	if (getRecord != NULL) {
		cout << " Found Employee: " << record->m_sLastName << ", " << record->m_sFirstName << endl;
	}
	else {
		cout << " Employee Not Found." << endl;
	}
	record = database->getEmployee(9999);
	cout << "Searching for Employee 9999...";
	if (record != NULL) {
		cout << " Found Employee: " << record->m_sLastName << ", " << record->m_sFirstName << endl;
	}
	else {
		cout << " Employee Not Found." << endl;
	}

	cout << "\nTesting Delete Function" << endl;
	database->removeEmployee(1234);
	database->printEmployeeRecords();

	cout << "\nTesting Add Function" << endl;
	database->addEmployee(getRecord);
	database->printEmployeeRecords();
	
	database->destroyTree(database->m_pRoot);

	database->printEmployeeRecords();

	cout << endl << endl;
	/*char storeName[32] = "UAH";
	char storeAddress[32] = "301 Sparkman Drive";
	char storeCity[32] = "Huntsville";
	char storeState[32] = "Alabama";
	char storeZip[32] = "35508";
	Store firstStore(10, storeName, storeAddress, storeCity, storeState, storeZip);
	Store secondStore(20, storeName, storeAddress, storeCity, storeState, storeZip);
	Store thirdStore(30, storeName, storeAddress, storeCity, storeState, storeZip);
	Store fourthStore(40, storeName, storeAddress, storeCity, storeState, storeZip);

	CustomerList list;

	list.addStore(&firstStore);
	list.addStore(&secondStore);
	list.addStore(&thirdStore);
	list.addStore(&fourthStore);

	cout << "Initail Four Stores" << endl;
	list.printStoresInfo();

	char storeNameTwo[32] = "Baker";
	char storeAddressTwo[32] = "3500 Airport Rd";
	char storeCityTwo[32] = "Mobile";
	char storeStateTwo[32] = "Alabama";
	char storeZipTwo[32] = "36608";
	list.updateStore(20, storeNameTwo, storeAddressTwo, storeCityTwo, storeStateTwo, storeZipTwo);
	cout << "Change store 20 to baker" << endl;
	list.printStoresInfo();

	Store halfthStore(5, storeName, storeAddress, storeCity, storeState, storeZip);
	Store twoandahalfStore(25, storeName, storeAddress, storeCity, storeState, storeZip);
	Store twentyninthStore(2900, storeName, storeAddress, storeCity, storeState, storeZip);
	list.addStore(&halfthStore);
	list.addStore(&twoandahalfStore);
	list.addStore(&twentyninthStore);
	list.removeStore(30);
	cout << "Add store 5, 25, 2900; remove 30" << endl;
	list.printStoresInfo();

	Store dummyStore;
	dummyStore = *list.getStore(20);
	list.removeStore(20);
	cout << "Remove 20" << endl;
	list.printStoresInfo();
	list.addStore(&dummyStore);
	cout << "Theoretically Add 20 back in" << endl;
	list.printStoresInfo();*/
}