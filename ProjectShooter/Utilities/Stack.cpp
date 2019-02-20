#ifdef STACK_H

template<class Datatype>
void Stack<Datatype>::push(Datatype p_data)
{
	Append(p_data);
}

template<class Datatype>
void Stack<Datatype>::pop()
{
	RemoveTail();
}

template<class Datatype>
Datatype& Stack<Datatype>::top()
{
	return m_tail->m_data;
}

template<class Datatype>
int Stack<Datatype>::Count()
{
	return m_count;
}

template <class Datatype>
Stack <Datatype>::Stack()
{
}

template <class Datatype>
Stack <Datatype>::~Stack()
{
}

#endif