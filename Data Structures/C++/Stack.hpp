#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
#include<exception>

struct StackEmptyException : public std::exception
{
	const char * what() const throw()
	{
		return "Stack is empty";
	}
};

struct SNode
{
	int info;
	SNode* next;

	SNode(int info) : info(info), next(NULL) {}
};

class Stack
{
	SNode* head;

public:
	Stack() : head(NULL) {}
	virtual ~Stack();
	void Push(int elem);
	int Pop();
	int Top() const;
	bool Empty() const { return ((this -> head) == NULL); };
};

#endif 
