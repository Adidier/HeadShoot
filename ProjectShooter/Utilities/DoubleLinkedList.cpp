#include "DoubleLinkedList.h"

template<class Datatype>
DoubleLinkedList<Datatype>::DoubleLinkedList()
{
	m_head = 0;
	m_tail = 0;
	m_count = 0;
}

template<class Datatype>
DoubleLinkedList<Datatype>::~DoubleLinkedList()
{
	DoubleNode<Datatype>* itr = m_head;
	DoubleNode<Datatype>* next;
	
	while (itr != 0){
		next = itr->m_next;
		delete itr;
		itr = next;
	}
}

template<class Datatype>
void DoubleLinkedList<Datatype>::Append(Datatype p_data)
{
	if (m_head == 0)
	{
		m_head = m_tail = new DoubleNode<Datatype>;
		m_head->m_data = p_data;
	}
	else
	{
		InsertAfter(p_data);
		m_tail = m_tail->m_next;
	}
	m_count++;
}

template<class Datatype>
void DoubleLinkedList<Datatype>::RemoveTail()
{
	if (m_tail != nullptr && m_count >= 2)
	{
		DoubleNode<Datatype>* tail_to_remove = m_tail;
		m_tail = m_tail->m_previous;
		m_tail->m_next = nullptr;
		delete tail_to_remove;
		--m_count;
	}
	return;
}

template<class Datatype>
void DoubleLinkedList<Datatype>::InsertAfter(Datatype p_data)
{
	DoubleNode<Datatype>* newnode = new DoubleNode<Datatype>;
	newnode->m_data = p_data;
	newnode->m_next = nullptr;
	newnode->m_previous = m_tail;
	m_tail->m_next = newnode;
}