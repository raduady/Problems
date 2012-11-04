#include "BSTree.hpp"
#include<iostream>
#include<stack>



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

void BSTree::PrintInorderRec(BTreeNode* node, int sp) const
{
	if(node == NULL) {
		return;
	} else {
		PrintInorderRec(node -> left, sp + 1);
		for(int i = 0; i < sp; ++i) {
			std::cout << " ";
		}
		std::cout << node -> info << std::endl;
		PrintInorderRec(node -> right, sp + 1);
	}
}

void BSTree::PrintInorderSt() const
{
	std::stack<BTreeNode*> st;
	BTreeNode* cNode;
	bool rev = false;
	st.push(this -> root);

	while(!st.empty()) {
		cNode = st.top();	

		if(rev == false && cNode -> left != NULL) {
			st.push(cNode -> left);
		} else {
			st.pop();
			std::cout << cNode -> info << std::endl;
			if (cNode -> right != NULL) {
				rev = false;
				st.push(cNode -> right);
			} else {
				rev = true;
			}
		}
	}
}

void BSTree::PrintPreorderRec(BTreeNode* node, int sp) const
{
	if(node == NULL) {
		return;
	} else {
		for(int i = 0; i < sp; ++i) {
			std::cout << " ";
		}
		std::cout << node -> info << std::endl;
		PrintPreorderRec(node -> left, sp + 1);
		PrintPreorderRec(node -> right, sp + 1);
	}
}

void BSTree::PrintPostorderRec(BTreeNode* node, int sp) const
{
	if(node == NULL) {
		return;
	} else {
		PrintPostorderRec(node -> left, sp + 1);
		PrintPostorderRec(node -> right, sp + 1);
		for(int i = 0; i < sp; ++i) {
			std::cout << " ";
		}
		std::cout << node -> info << std::endl;
	}
}

void BSTree::PrintPostorderSt() const
{
	std::stack<BTreeNode*> st;
	std::stack<bool> topped;
	BTreeNode* cNode;

	st.push(this -> root);
	topped.push(false);
	while(!st.empty()) {
		cNode = st.top();
		if (topped.top() == true) {
			st.pop();
			topped.pop();
			std::cout << cNode -> info << std::endl;
		} else {
			topped.pop();
			topped.push(true);
			if (cNode -> right != NULL) {
				st.push(cNode -> right);	
				topped.push(false);
			}
			if (cNode -> left != NULL) {
				st.push(cNode -> left);	
				topped.push(false);
			}
		}
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
