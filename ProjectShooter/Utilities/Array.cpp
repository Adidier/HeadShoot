#ifdef ARRAY_H

template<class Datatype>
Array<Datatype>::Array(int p_size)
{
	m_array = new Datatype[p_size];
	m_size = p_size;
}

template<class Datatype>
Array<Datatype>::~Array()
{
	if (m_array != 0)
		delete[] m_array;
	m_array = 0;
}

template<class Datatype>
void Array<Datatype>::Resize(int p_size)
{
	Datatype * newarray = new Datatype[p_size];
	if (newarray == 0)
		return;
	int min;
	if (p_size < m_size)
		min = p_size;
	else
		min = m_size;
	int index;
	for (index = 0; index < min; index++)
		newarray[index] = m_array[index];
	m_size = p_size;
	if (m_array != 0)
		delete[] m_array;
	m_array = newarray;
}

template<class Datatype>
Datatype & Array<Datatype>::operator[](int p_index)
{
	return m_array[p_index];
}

template<class Datatype>
Array<Datatype>::operator Datatype*()
{
	return m_array;
}

template<class Datatype>
void Array<Datatype>::Insert(Datatype p_item, int p_index)
{
	int index;
	for (index = m_size - 1; index > p_index; index—)
		m_array[index] = m_array[index - 1];
	m_array[p_index] = p_item;
}

template<class Datatype>
void Array<Datatype>::Remove(int p_index)
{
	int index;
	for (index = p_index + 1; index < m_size; index++)
		m_array[index - 1] = m_array[index];
}

template<class Datatype>
int Array<Datatype>::Size()
{
	return m_size;
}



#endif