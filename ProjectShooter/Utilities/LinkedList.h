#ifndef LINKEDLIST_H 
#define LINKEDLIST_H
															//Estructura de nodos

//Hago un template para poder crear una lista con cualquier tipo de dato
template<class Datatype>
class SListNode
{
public:
	Datatype m_data; //contiene el dato que se almacenara en un nodo
	SListNode<Datatype>* m_next; //apunta a otra objeto de esta clase 
	SListNode() {}
	void InsertAfter(Datatype p_data);
};
															// Lista Ligada especifica

template<class Datatype>
class LinkedList
{

	//Apuntador al primer nodo
	SListNode<Datatype>* m_head;
	//Apuntador al segundo nodo
	SListNode<Datatype>* m_tail;
	//Entero que indicara el numero total de nodos en la lista
	int m_count;
public:
	void Append(Datatype p_data);
	void Prepend(Datatype p_data);
	void RemoveHead();
	void RemoveTail();

	LinkedList();
	~LinkedList();
};

template<class Datatype>
class SListIterator
{
public:
	SListNode<Datatype>* m_node;
	LinkedList<Datatype>* m_list;

	SListIterator(LinkedList<Datatype> *p_list = 0, SListNode<Datatype> *p_node = 0);

	void Start();
	void Forth();
	Datatype& Item();
	bool Valid();
	SListIterator<Datatype> GetIterator();


	//Inserta un nuevo item después del iterador o del append actual si la info del 
	// iterador es inválido
	void Insert(SListIterator<Datatype>& p_iterator, Datatype p_data);
	void Remove(SListIterator<Datatype>& p_iterator);
};


#include"LinkedList.cpp"

#endif