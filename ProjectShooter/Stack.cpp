#include "Stack.h"


template<class dataType>
void Stack<dataType>::push(dataType p_data)
{
	Append(p_data);
}

template <class dataType>
Stack <dataType>::Stack()
{
}

template <class dataType>
Stack <dataType>::~Stack()
{
}
