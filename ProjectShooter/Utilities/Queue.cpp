#ifdef STACK_H

template<class Datatype>
void Queue<Datatype>::Enqueue(Datatype p_data)
{
	Append(p_data);
}

template<class Datatype>
void Queue<Datatype>::Dequeue()
{
	RemoveHead();
}

template<class Datatype>
Datatype Queue<Datatype>::Front()
{
	return m_head->m_data;
}

template<class Datatype>
int Queue<Datatype>::Count()
{
	return m_count;
}

template<class Datatype>
Queue<Datatype>::Queue()
{
}

template<class Datatype>
Queue<Datatype>::~Queue()
{
}

#endif 