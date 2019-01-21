#ifndef LINKEDLIST_H 
#define LINKEDLIST_H
															//Estructura de nodos

//Hago un template para poder crear una lista con cualquier tipo de dato
template<class Datatype>
class DListNode
{
public:
	Datatype m_data; //contiene el dato que se almacenara en un nodo
	DListNode<Datatype>* m_previous; //apunta al objeto previo de esta clase 
	SListNode<Datatype>* m_next; //apunta a otra objeto de esta clase 
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

	LinkedList();
	~LinkedList();

	void Insert(int posicion, Datatype p_data);
};


#endif

