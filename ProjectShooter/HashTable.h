#pragma once
#include "Utilities/LinkedList.h"
#include <string>

unsigned long int StringHash(std::string p_string) {
	unsigned long int hash = 0;
	int i;
	for (i = 0; i < p_string.length(); i++)
	{
		hash += ((i + 1) * p_string[i]);
	}
	return hash;
}

template<class Datatype, class Datatype1>
class HashTable
{
private:
	const int prime{ 101 };
	int m_count;
	LinkedList<Datatype1> data[101];
public:
	HashTable();
	//HasTableNode Find(Datatype index);
	void Insert(Datatype index, Datatype1 valude);
	void Find(Datatype index);
	//void Remove(Datatype index);
	//int count()
	~HashTable();
};