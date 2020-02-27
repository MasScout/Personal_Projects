#pragma once

#include <iostream>

struct ListItem {
	int key;
	float theData;
	ListItem *next;
};

class ListAlgorithms {
private:
	ListItem *head;

public:
	ListAlgorithms();
	~ListAlgorithms();
	void ClearList();
	bool Insert(int key, float f);
	ListItem *Delete(int key);
	ListItem *Search(int key);
	int ListLength();
	bool isEmpty();
	bool isFull();
	void PrintList();
};

