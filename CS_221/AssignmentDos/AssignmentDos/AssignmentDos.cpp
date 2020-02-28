// AssignmentDos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"
#include "CustomerList.h"
#include "Store.h"


int main()
{
	char storeName[32] = "UAH";
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
	list.printStoresInfo();
}


