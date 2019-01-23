#include "DoubleLL.h"

template<class Datatype>
DoubleLL<Datatype>::DoubleLL()
{
	m_head = 0;
	m_tail = 0;
	m_count = 0;
}

template<class Datatype>
DoubleLL<Datatype>::~DoubleLL()
{
	SDoubleLL<Datatype>* itr = m_head;
	SDoubleLL<Datatype>* next;
	SDoubleLL<Datatype>* previous;
	
	while (itr != 0)
	{
		next = itr->m_next;
		previous = itr->m_previous;
		delete itr;
		itr = next;
	}
}

template<class Datatype>
void DoubleLL<Datatype>::Append(Datatype p_data)
{
	if (m_head == 0)
	{
		m_head = m_tail = new SDoubleLL<Datatype>;
		m_head->m_data = p_data;
	}
	else
	{
		m_tail->InsertAfter(p_data);
		m_tail = m_tail->m_next;
	}
	m_count++;
}

template<class Datatype>
void SDoubleLL<Datatype>::InsertAfter(Datatype p_data)
{
	SDoubleLL<Datatype>* newnode = new SListNode<Datatype>;
	newnode->m_data = p_data;
	newnode->m_next = m_next;
	newnode->m_previous = m_previous;
	m_previous = newnode;
	m_next = newnode;
}