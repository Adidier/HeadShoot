#ifdef STACK_H



template<class dataType>
void Stack<dataType>::push(dataType p_data)
{
	this->Append(p_data);
}

template<class dataType>
void Stack<dataType>::pop()
{
	this->RemoveTail();
}

template<class dataType>
dataType& Stack<dataType>::top()
{
	return this->m_tail->m_data;
}

template<class dataType>
int Stack<dataType>::count()
{
	return this->m_count;
}

template <class dataType>
Stack <dataType>::Stack()
{
}

template <class dataType>
Stack <dataType>::~Stack()
{
}

#endif