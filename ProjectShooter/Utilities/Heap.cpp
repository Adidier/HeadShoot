#ifdef HEAP_H

template<class DataType>
Heap<DataType>::Heap(int p_size, int(*p_compare)(DataType, DataType))
{
	m_count = 0;
	m_compare = p_compare;
}

template<class DataType>
void Heap<DataType>::Enqueue(DataType p_data)
{
	m_count++;
	if (m_count >= m_size)
		Resize(m_size * 2);
	m_array[m_count] = p_data;
	WalkUp(m_count);
}

template<class DataType>
void Heap<DataType>::WalkUp(int p_index)
{
	int parent = p_index / 2;
	int child = p_index;
	DataType temp = m_array[child];
	while (parent > 0)
	{
		if (m_compare(temp, m_array[parent]) > 0)
		{
			m_array[child] = m_array[parent];
			child = parent;
			parent /= 2;
		}
		else
			break;
	}
	m_array[child] = temp;
}

template<class DataType>
void Heap<DataType>::Dequeue()
{
	if (m_count >= 1)
	{
		m_array[1] = m_array[m_count];
		WalkDown(1);
		m_count—;
	}
}

template<class DataType>
void Heap<DataType>::WalkDown(int p_index)
{
	int parent = p_index;
	int child = p_index * 2;
	DataType temp = m_array[parent];
	while (child < m_count)
	{
		if (child < m_count - 1)
		{
			if (m_compare(m_array[child], m_array[child + 1]) < 0)
			{
				child++;
			}
		}
		if (m_compare(temp, m_array[child]) < 0)
		{
			m_array[parent] = m_array[child];
			parent = child;
			child *= 2;
		}
		else
			break;
	}
	m_array[parent] = temp;
}

#endif