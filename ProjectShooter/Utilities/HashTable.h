#ifndef HASH_TABLE
#define HASH_TABLE
#include "LinkedList.h"
#include <string>




template<class Datatype,class Datatype1>
class HashTable
{
private:
	const int prime{ 101 };

	int m_count;
	LinkedList<Datatype1> *data;
public:
	HashTable();
	Datatype1 Find(Datatype index);
	void Insert(Datatype index, Datatype1 value);
	//void Remove(Datatype index);
	//int Count();

	unsigned long int StringHash(std::string p_string) {
		unsigned long int hash = 0;
		int i;
		for (i = 0; i < p_string.length(); i++)
		{
			hash += ((i + 1) * p_string[i]);
		}
		return hash;
	}
};

#endif // !HASH_TABLE
