#ifndef STACK_H
#define STACK_H
#include "Utilities/DoubleLinkedList.h"

template <class dataType>
class Stack : public  DoubleLinkedList <dataType>
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
