#include "CustomerList.h"

using namespace std;

//Brief: Default Constructor for CustomerList Class
CustomerList::CustomerList() {
#ifdef TESTING
	cout << "CustomerList::CustomerList" << endl;
#endif
	m_pHead = NULL;
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
	Store *temp, *back;

	if (m_pHead == NULL) {
		m_pHead = s;
	}
	else {
		temp = m_pHead;
		back = NULL;
		while ((temp != NULL) && (temp->getStoreID() < s->getStoreID())) {
			back = temp;
			temp = temp->m_pNext;
		}
		if (back == NULL) {
			s->m_pNext = m_pHead;
			m_pHead = s;
		}
		else {
			back->m_pNext = s;
			s->m_pNext = temp;
		}
	}
	return true;
}

Store *CustomerList::removeStore(int ID) {
#ifdef TESTING
	cout << "CustomerList::removeStore" << endl;
#endif
	Store *temp, *back;

	if (m_pHead == NULL) {
		return NULL;
	}

	temp = m_pHead;
	back = NULL;
	while ((temp != NULL) && (ID != temp->getStoreID())) {
		back = temp;
		temp = temp->m_pNext;
	}

	if (temp == NULL) {
		return NULL;
	}
	else if (back == NULL) {
		m_pHead = m_pHead->m_pNext;
		return temp;
	}
	else {
		back->m_pNext = temp->m_pNext;
		return temp;
	}
	return NULL;
}

Store *CustomerList::getStore(int ID) {
#ifdef TESTING
	cout << "CustomerList::getStore" << endl;
#endif
	Store *temp;
	temp = m_pHead;

	while ((temp != NULL) && (ID != temp->getStoreID())) {
		temp = temp->m_pNext;
	}
	if (temp == NULL) {
		return NULL;
	}
	else {
		Store *retStore = new Store();
		*retStore = *temp;
		retStore->m_pNext = NULL;
		return retStore;
	}
}

bool CustomerList::updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip) {
#ifdef TESTING
	cout << "CustomerList::updateStore" << endl;
#endif
	Store *temp;
	temp = m_pHead;

	while ((temp != NULL) && (ID != temp->getStoreID())) {
		temp = temp->m_pNext;
	}
	if (temp == NULL) {
		cout << "The ID: " << ID << "was not found." << endl;
		return false;
	}
	else {
		temp->setStoreName(name);
		temp->setStoreAddress(addr);
		temp->setStoreCity(city);
		temp->setStoreState(st);
		temp->setStoreZip(zip);
	}
	return true;
}

void CustomerList::printStoresInfo() {
#ifdef TESTING
	cout << "CustomerList::printStoresInfo" << endl;
#endif
	Store *temp;
	cout << "Stores Data:\n";
	cout << "ID\tName\tAddress\t\t\t\tCity\t\tState\t\tZip\n";
	if (m_pHead == NULL) {
		cout << "List is currently empty" << endl;
	}
	else {
		temp = m_pHead;
		while (temp != NULL) {
			cout << "Store number " << temp->getStoreID() << ", named " << temp->getStoreName() << ", located at " << temp->getStoreAddress() << ", " << temp->getStoreCity() << ", " << temp->getStoreState() << " " << temp->getStoreZip() << endl;
			temp = temp->m_pNext;
		}
		cout << "\n" << endl;
	}
}