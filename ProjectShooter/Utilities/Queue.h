#ifndef QUEUE_H
#define QUEUE_H

#include "DoubleLinkedList.h";

template<class Datatype>
class Queue : public DoubleLinkedList<Datatype>
{
public:
	void Enqueue(Datatype p_data);
	void Dequeue();
	Datatype Front();
	int Count();
	Queue();
	~Queue();
};

#include "Queue.cpp":

#endif

