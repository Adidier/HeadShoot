#ifndef ARRAY_H
#define ARRAY_H

template <class Datatype>
class Array
{
public:
	Datatype * m_array;
	int m_size;

	Array(int p_size);

	~Array();

	void Resize(int p_size);

	Datatype & operator[] (int p_index);

	operator Datatype* ();

	void Insert(Datatype p_item, int p_index);

	void Remove(int p_index);

	int Size();
};

#include "Array.cpp"

#endif
