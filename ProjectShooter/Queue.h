#pragma once
template<class dataType>
class Queue //: public Array<dataType>
{
public:
	int m_front;
	int m_count;
	Queue(int p_size);// : List<dataType>(p_size);
	bool Enqueue(dataType p_data);
	void Dequeue();
	dataType Front();
	int Count();
	~Queue();
};

