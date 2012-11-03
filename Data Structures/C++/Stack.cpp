#include "Stack.hpp"
#include <iostream>

void Stack::Push(int elem)
{
	if(Empty()) {
		this -> head = new SNode(elem);
	} else {
		SNode *node = new SNode(elem);
		node -> next = this -> head;
		this -> head = node;		
	}
}

int Stack::Top() const
{
	if(Empty()) {
		throw StackEmptyException();
	} else {
		return this -> head -> info;
	}
}

int Stack::Pop()
{
	if(Empty()) {
		throw StackEmptyException();
	} else {
		SNode *node;
		int res;
		node = this -> head;
		this -> head = node -> next;
		res = node -> info;
		delete node;
		return res;
	}
}

Stack::~Stack()
{
	while(!Empty()) {
		Pop();
	}
}
