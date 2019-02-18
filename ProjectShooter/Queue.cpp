#include "pch.h"
#include "Queue.h"

template<class dataType>
Queue<dataType>::Queue(int p_size)
{
	m_front = 0;
	m_count = 0;
}

template<class dataType>
bool Queue<dataType>::Enqueue(dataType p_data)
{
	//if (m_size != m_count)
	//{
	//	m_array[(m_count + m_front) % m_size] = p_data;
	//	m_count++;
	//	return true;
	//}
	return false;
}

template<class dataType>
void Queue<dataType>::Dequeue()
{
	//if (m_count > 0)
	//{
	//	m_count--;
	//	m_front++;
	//	if (m_front == m_size)
	//		m_front = 0;
	//}
}

template<class dataType>
dataType Queue<dataType>::Front()
{
	return nullptr;// m_array[m_front];
}

template<class dataType>
int Queue<dataType>::Count()
{
	return m_count;
}

template<class dataType>
Queue<dataType>::~Queue()
{
}
