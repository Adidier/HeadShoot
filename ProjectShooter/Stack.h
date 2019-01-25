#pragma once
#include "Utilities/DoubleLinkedList.h"

template <class dataType>
class Stack : public  DoubleLinkedList <dataType>
{
public:


	Stack();
	~Stack();
};

