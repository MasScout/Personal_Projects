#pragma once

#include "Store.h"

class CustomerList
{
public:
	CustomerList();
	~CustomerList();
	bool addStore(Store *s);
	Store *removeStore(int ID);
	Store *getStore(int ID);
	bool updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip);
	void printStoresInfo();
private:
	Store * m_pHead;
};

