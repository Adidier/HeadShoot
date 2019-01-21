#ifndef LINKEDLIST_H 
#define LINKEDLIST_H
template<class Datatype>
class SListNode;
template<class Datatype>
class LinkedList;
template<class Datatype>
class LinkedListIter
{
	public:
		LinkedListIter(SListNode<Datatype> *m_node, LinkedList<Datatype> *m_list);
		bool Valid();
		Datatype Item();
		void Forth();
		SListNode *m_node;
		LinkedList *m_list;

};

//Estructura de nodos
//Hago un template para poder crear una lista con cualquier tipo de dato
template<class Datatype>
class SListNode
{
public:
	Datatype m_data; //contiene el dato que se almacenara en un nodo
	SListNode<Datatype>* m_next; //apunta a otra objeto de esta clase 
	void InsertAfter(Datatype p_data);
};
															// Lista Ligada especifica

template<class Datatype>
class LinkedList
{
public:
	//Apuntador al primer nodo
	SListNode<Datatype>* m_head;
	//Apuntador al segundo nodo
	SListNode<Datatype>* m_tail;
	//Entero que indicara el numero total de nodos en la lista
	int m_count;
	
	void Append(Datatype p_data);
	LinkedListIter<Datatype> GetIterator();

	LinkedList();
	~LinkedList();
};
#endif