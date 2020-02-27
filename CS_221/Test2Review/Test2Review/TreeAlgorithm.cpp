#include "pch.h"
#include <iostream>
#include <string>
#include "TreeAlgorithm.h"


TreeAlgorithm::TreeAlgorithm() {
	root = NULL;
}

TreeAlgorithm::~TreeAlgorithm() {
	ClearTree(root);
	return;
}

void TreeAlgorithm::ClearTree() {

}

bool TreeAlgorithm::isEmpty() {
	return(root == NULL);
}

TreeNode *TreeAlgorithm::SearchTree(int Key) {
	TreeNode *temp;

	temp = root;
	while ((temp != NULL) && (temp->key != Key)) {
		if (Key < temp->key) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	if (temp == NULL) {
		return NULL;
	}
	else {
		return DupNode(temp);
	}
}

bool TreeAlgorithm::Insert(TreeNode *newNode) {
	TreeNode *temp, *back;
	temp = root;
	back = NULL;

	while (temp != NULL) {
		back = temp;
		if (newNode->key < temp->key) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	if (back == NULL) {
		root = newNode;
	}
	else {
		if (newNode->key < back->key) {
			back->left = newNode;
		}
		else {
			back->right = newNode;
		}

	}
	return true;
}

bool TreeAlgorithm::Insert(int Key, float f, int i, char *cA) {
	TreeNode *newNode;

	newNode = new TreeNode();
	newNode->key = Key;
	
	newNode->left = NULL;
	newNode->right = NULL;
}

TreeNode *TreeAlgorithm::Delete(int Key) {

}

void TreeAlgorithm::PrintOne(TreeNode *T) {

}

void TreeAlgorithm::PrintTree() {

}

void TreeAlgorithm::ClearTree(TreeNode *T) {

}

TreeNode *TreeAlgorithm::DupNode(TreeNode *T) {
	TreeNode *dupNode;

	dupNode = new TreeNode();
	*dupNode = *T;
	dupNode->left = NULL;
	dupNode->right = NULL;
	return dupNode;
}

void TreeAlgorithm::PrintAll(TreeNode *T) {

}