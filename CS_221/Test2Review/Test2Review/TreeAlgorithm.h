#pragma once

struct TreeNode {
	int key;
	float fValue;
	int iValue;
	char cArray[7];
	TreeNode *left;
	TreeNode *right;
};
class TreeAlgorithm {
private:
	TreeNode *root;

public:
	TreeAlgorithm();
	~TreeAlgorithm();
	void ClearTree();
	bool isEmpty();
	TreeNode *SearchTree(int Key);
	bool Insert(TreeNode *newNode);
	bool Insert(int Key, float f, int i, char *cA);
	TreeNode *Delete(int Key);
	void PrintOne(TreeNode *T);
	void PrintTree();

private:
	void ClearTree(TreeNode *T);
	TreeNode *DupNode(TreeNode *T);
	void PrintAll(TreeNode *T);
};

