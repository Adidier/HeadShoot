#ifndef DOUBLELL_H 
#define DOUBLELL_H


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
};

#include"DoubleLinkedList.cpp"
#endif