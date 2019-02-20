#include "HashTable.h"

template<class Datatype, class Datatype1>
HashTable<Datatype, Datatype1>::HashTable(){
	data = new LinkedList<Datatype1>[prime];
}

//template<class Datatype, class Datatype1>
//HashTable<Datatype, Datatype1>::Insert(Datatype index, Datatype1 value) {
//	int position = index % 101;
//	data[position]->Append(value);
//}
//
//template<class Datatype, class Datatype1>
//HashTable<Datatype,>::Find(Datatype index) {
//	int position = index % 101;
//	SListIterator<Datatype1> iter(data[position]);
//	for (iter.Start(); iter.Item() != null; iter.Forth()){
//	}
//}

template<class Datatype, class Datatype1>
HashTable<Datatype, Datatype1>::~HashTable() {

}