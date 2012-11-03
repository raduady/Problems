#ifndef BSTREE_HPP
#define BSTREE_HPP

#include<iostream>

struct BTreeNode
{
	int info;
	BTreeNode* left;
	BTreeNode* right;
	
	BTreeNode(int info) : info(info), left(NULL), right(NULL) {}
};

class BSTree
{
	BTreeNode* root;

public:
	BSTree() : root(NULL) {};
	virtual ~BSTree() { delAll(this -> root); }

	void Add(int elem) { this -> root = Add(elem, this -> root); }
	void PrintInorder() const { PrintInorder(this -> root, 0); }
	void delAll(BTreeNode* node);

private:
	void PrintInorder(BTreeNode* node, int sp) const;
	BTreeNode* Add(int elem, BTreeNode* node);
};

#endif
