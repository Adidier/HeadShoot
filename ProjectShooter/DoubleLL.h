#ifndef DOUBLELL_H 
#define DOUBLELL_H

template<class Datatype>
class SDoubleLL
{
public:
	Datatype m_data;
	SDoubleLL<Datatype>* m_next;
	SDoubleLL<Datatype>* m_previous;
	void InsertAfter(Datatype p_data);
};


template<class Datatype>
class DoubleLL
{
public:
	SDoubleLL<Datatype>* m_head;
	SDoubleLL<Datatype>* m_tail;
	int m_count;

	void Append(Datatype p_data);

	DoubleLL();
	~DoubleLL();
};
#endif