#include "stdafx.h"
#include "CustomerList.h"

using namespace std;

//Brief: Default Constructor for CustomerList Class
CustomerList::CustomerList() {
#ifdef TESTING
	cout << "CustomerList::CustomerList" << endl;
#endif
}

//Brief: Destructor for CustomerList Class
CustomerList::~CustomerList() {
#ifdef TESTING
	cout << "CustomerList::~CustomerList" << endl;
#endif
}

bool CustomerList::addStore(Store *s) {
#ifdef TESTING
	cout << "CustomerList::addStore" << endl;
#endif
	return true;
}

Store *CustomerList::removeStore(int ID) {
#ifdef TESTING
	cout << "CustomerList::removeStore" << endl;
#endif
	return NULL;
}

Store *CustomerList::getStore(int ID) {
#ifdef TESTING
	cout << "CustomerList::getStore" << endl;
#endif
	return NULL;
}

bool CustomerList::updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip) {
#ifdef TESTING
	cout << "CustomerList::updateStore" << endl;
#endif
	return true;
}

void CustomerList::printStoresInfo() {
#ifdef TESTING
	cout << "CustomerList::printStoresInfo" << endl;
#endif

}