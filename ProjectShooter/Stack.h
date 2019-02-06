#pragma once
#include "Utilities/DoubleLinkedList.h"

template <class dataType>
class Stack : public  DoubleLinkedList <dataType>
{
public:

	void push(dataType p_data);

	Stack();
	~Stack();
};

