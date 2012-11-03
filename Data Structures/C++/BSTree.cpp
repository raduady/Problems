#include "BSTree.hpp"
#include<iostream>


BTreeNode* BSTree::Add(int elem, BTreeNode* node)
{
	if(node == NULL) {
		node = new BTreeNode(elem);
	} else if (elem < node -> info) {
		node -> left = Add(elem, node -> left);
	} else {
		node -> right = Add(elem, node -> right);
	}

	return node;
}

void BSTree::PrintInorder(BTreeNode* node, int sp) const
{
	if(node == NULL) {
		return;
	} else {
		PrintInorder(node -> left, sp + 1);
		for(int i = 0; i < sp; ++i) {
			std::cout << " ";
		}
		std::cout << node -> info << std::endl;
		PrintInorder(node -> right, sp + 1);
	}
}

void BSTree::delAll(BTreeNode* node) {
	if(node == NULL) {
		return;
	} else {
		delAll(node -> left);
		delAll(node -> right);

		delete node;
	}
}
