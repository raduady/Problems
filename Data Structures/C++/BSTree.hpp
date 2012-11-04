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
	void PrintInorderRec() const { PrintInorderRec(this -> root, 0); }
	void PrintInorderSt() const;
	void PrintPreorderRec() const { PrintInorderRec(this -> root, 0); }
	void PrintPostorderRec() const { PrintPostorderRec(this -> root, 0); }
	void PrintPostorderSt() const;
	void delAll(BTreeNode* node);

private:
	void PrintInorderRec(BTreeNode* node, int sp) const;
	void PrintPreorderRec(BTreeNode* node, int sp) const;
	void PrintPostorderRec(BTreeNode* node, int sp) const;
	BTreeNode* Add(int elem, BTreeNode* node);
};

#endif
