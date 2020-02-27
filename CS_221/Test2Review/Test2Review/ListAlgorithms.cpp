#include "pch.h"
#include "ListAlgorithms.h"


ListAlgorithms::ListAlgorithms() {
	head = NULL;
}


ListAlgorithms::~ListAlgorithms() {
	ClearList();
}

void ListAlgorithms::ClearList() {

}

bool ListAlgorithms::Insert(int key, float f) {
	ListItem *temp, *back, *newNode;

	newNode = new ListItem;
	if (newNode == NULL) return false;
	newNode->key = key;
	newNode->theData = f;
	newNode->next = NULL; //IMPORTANT

	if (isEmpty()) {
		head = newNode;
	}
	else {
		temp = head;
		back = NULL;
		while ((temp != NULL) && (temp->key < key)) {
			back = temp;
			temp = temp->next;
		}
		if (back == NULL) {
			newNode->next = head;
			head = newNode;
		}
		else {
			back->next = newNode;
			newNode->next = temp;
		}
	}
	return true;
}

ListItem *ListAlgorithms::Delete(int key) {
	ListItem *temp, *back;

	if (isEmpty()) return NULL;

	temp = head;
	back = NULL;
	while ((temp != NULL) && (key != temp->key)) {
		back = temp;
		temp = temp->next;
	}

	if (temp == NULL) return NULL;
	else if (back == NULL) {
		head = head->next;
		return temp;
	}
	else {
		back->next = temp->next;
		return temp;
	}
	return NULL;
}

ListItem *ListAlgorithms::Search(int key) {
	ListItem *temp;		//Temporary pointer
	temp = head;		//Point to head of list

	//While not null and while not the key
	while ((temp != NULL) && (key != temp->key)) {
		temp = temp->next;	//Go next
	}

	if (temp == NULL) {
		return NULL;
	}
	else {
		ListItem *retItem = new ListItem(); //Dynamically create new more permanent pointer to return
		*retItem = *temp;					//Copy entire structure
		retItem->next = NULL;				//Set the next to NULL
		return retItem;						//return the duplicate node
	}
}

int ListAlgorithms::ListLength() {

}

bool ListAlgorithms::isEmpty() {
	return (head == NULL);
}

bool ListAlgorithms::isFull() {
	return true;
}

void ListAlgorithms::PrintList() {

}