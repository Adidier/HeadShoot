
#include "LinkedList.h"

//IMPORTANTE: Incluir este cpp en el source del cliente para evitar problemas de LINKER

template<class Datatype>
//Constructor, indica que la lista no tiene nodos y tampoco apunta a ningun nodo
LinkedList<Datatype>::LinkedList()
{
	m_head = 0;
	m_tail = 0;
	m_count = 0;
}

template<class Datatype>
LinkedList<Datatype>::~LinkedList()
{
	// apuntador temporal para iterar desde el principio
	SListNode<Datatype>* itr = m_head;
	// apuntador temporal para apuntar a los siguientes nodos
	SListNode<Datatype>* next;
	// el miembro m_next de itr valdra 0 por lo que itr sera 0, confirmando que todos los nodos han sido borrados
	while (itr != 0)
	{
		// salva el apuntador al siguiente nodo
		next = itr->m_next;
		// borra el nodo actual
		delete itr;
		// convierte el nodo next en el nodo actual
		itr = next;
	}
}

//Append: Agrega un nuevo nodo al final de la lista
template<class Datatype>
void LinkedList<Datatype>::Append(Datatype p_data)
{
	//En caso de que no haya nodos
	if (m_head == 0)
	{
		// crea un nuevo nodo al cual le apuntan la cabeza y la cola
		m_head = m_tail = new SListNode<Datatype>; //Error: attempting to reference a deleted function.
		m_head->m_data = p_data;
	}
	//Si hay nodos 
	else
	{
		// inserta un nuevo nodo despues de la cola y reinicia la cola
		m_tail->InsertAfter(p_data);
		m_tail = m_tail->m_next;
	}
	//Se cuenta el nuevo nodo
	m_count++;
}

template<class Datatype>
void SListNode<Datatype>::InsertAfter(Datatype p_data)
{
	// crea nuevo nodo
	SListNode<Datatype>* newnode = new SListNode<Datatype>;
	newnode->m_data = p_data;
	// nuevo nodo apunta al siguiente nodo
	newnode->m_next = m_next;
	// nodo previo apunta al nuevo nodo
	m_next = newnode;
}

template<class Datatype>
LinkedListIter<Datatype>::LinkedListIter(SListNode<Datatype>* m_node, LinkedList<Datatype> * m_list)
{
	this->m_node = m_node;
	this->m_list = m_list;
}

template<class Datatype>
bool LinkedListIter<Datatype>::Valid()
{
	return (m_node != nullptr)
}

template<class Datatype>
Datatype LinkedListIter<Datatype>::Item()
{
	return m_node->m_data;
}

template<class Datatype>
void LinkedListIter<Datatype>::Forth()
{
	if (m_node != nullptr && m_node->m_next != nullptr) {
		m_node = m_node->m_next;
	}
}


template<class Datatype>
LinkedListIter<Datatype> LinkedList<Datatype>::GetIterator()
{
	return LinkedListIter(m_head, this);
}
