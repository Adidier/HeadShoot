#ifndef STACK_H
#define STACK_H

#include "DoubleLinkedList.h";

template <class Datatype>
class Stack : public DoubleLinkedList<Datatype>
{
public:

	void push(Datatype p_data);
	void pop();
	Datatype top();
	int Count();
	Stack();
	~Stack();
};

#include "Stack.cpp"
#endif
