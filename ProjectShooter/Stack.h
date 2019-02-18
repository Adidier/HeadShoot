#ifndef STACK_H
#define STACK_H

#include "Utilities/LinkedList.h";

template <class dataType>
class Stack : public LinkedList <dataType>
{
public:

	void push(dataType p_data);
	void pop();
	dataType& top();
	int count();
	Stack();
	~Stack();
};

#include "Stack.cpp"
#endif
