#ifndef DOUBLELL_H 
#define DOUBLELL_H

template<class Datatype>
class SDoubleLinkedListIterator;

template<class Datatype>
class DoubleNode
{
public:
	Datatype m_data;
	DoubleNode<Datatype>* m_next;
	DoubleNode<Datatype>* m_previous;
	
};


template<class Datatype>
class DoubleLinkedList
{
public:
	DoubleNode<Datatype>* m_head;
	DoubleNode<Datatype>* m_tail;
	int m_count;

	void Append(Datatype p_data);
	void InsertAfter(Datatype p_data);
	void RemoveTail();

	DoubleLinkedList();
	~DoubleLinkedList();

	SDoubleLinkedListIterator<Datatype> GetIterator()
	{
		return SDoubleLinkedListIterator<Datatype>(this, m_head);
	}

};

template<class Datatype>
class SDoubleLinkedListIterator
{
public:
	DoubleNode<Datatype>* m_node;
	DoubleLinkedList<Datatype>* m_list;

	SDoubleLinkedListIterator(DoubleLinkedList<Datatype> *p_list = 0, DoubleNode<Datatype> *p_node = 0);

	void Start();
	void Forth();
	Datatype& Item();
	bool Valid();


	//Inserta un nuevo item después del iterador o del append actual si la info del 
	// iterador es inválido
};

template<class Datatype>
SDoubleLinkedListIterator<Datatype>::SDoubleLinkedListIterator(DoubleLinkedList<Datatype>* p_list, DoubleNode<Datatype>* p_node)
{
	m_list = p_list;
	m_node = p_node;
}


template<class Datatype>
void SDoubleLinkedListIterator<Datatype>::Start()
{
	if (m_list != 0)
		m_node = m_list->m_head;
}

template<class Datatype>
void SDoubleLinkedListIterator<Datatype>::Forth()
{
	if (m_node != 0)
		m_node = m_node->m_next;
}

template<class Datatype>
Datatype & SDoubleLinkedListIterator<Datatype>::Item()
{
	return m_node->m_data;
}

template<class Datatype>
bool SDoubleLinkedListIterator<Datatype>::Valid()
{
	return (m_node != 0);
}



#include"DoubleLinkedList.cpp"
#endif