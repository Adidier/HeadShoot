#ifndef HEAPH_H
#define HEAPH_H

#include "Array.h"

template <class DataType>
class Heap : public Array<DataType>
{
public:
	int m_count;
	int(*m_compare)(DataType, DataType);

	Heap(int p_size, int(*p_compare)(DataType, DataType))
		: Array<DataType>(p_size + 1);

	void Enqueue(DataType p_data);

	void WalkUp(int p_index);

	void Dequeue();

	void WalkDown(int p_index);
};

#include "Heap.cpp"

#endif
