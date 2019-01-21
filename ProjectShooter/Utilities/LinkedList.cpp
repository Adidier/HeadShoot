#include "pch.h"
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
	DListNode<Datatype>* itr = m_head;
	// apuntador temporal para apuntar a los siguientes nodos
	DListNode<Datatype>* next;
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
		m_head = m_tail = new DListNode<Datatype>;
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
void DListNode<Datatype>::InsertAfter(Datatype p_data)
{
	// crea nuevo nodo
	DListNode<Datatype>* newnode = new DListNode<Datatype>;
	newnode->m_data = p_data;
	// nuevo nodo apunta al siguiente nodo
	newnode->m_next = m_next;
	// nodo previo apunta al nuevo nodo
	m_next = newnode;
}

template<class Datatype>
void DListNode<Datatype>::Insert(int posicion, Datatype p_data)
{
	int conteo = 0;
	DListNode<Datatype>* n_node = new DListNode<Datatype>;
	DListNode<Datatype>* siguiente;
	DListNode<Datatype>* previo;

	n_node->m_data = p_data;
	n_node = n_head;

	while (conteo != posicion)
	{
		if (conteo > 0)
		{
			if (conteo == 1)
				previo = m_head;

			else
				previo = n_node->m_previous;
		}

		n_node = siguiente;
		siguiente = n_node->m_next;

		n_node->m_previous = previo;
		previo->m_next = n_node;

		++conteo;
	}

	if (conteo != 0)
	{
		n_node->m_next = siguiente;
		siguiente->m_previous = n_node
	}
}

// No se tiene que llamar esta funcion, solo eviya error de linker
void TemporaryFunction()
{
	LinkedList<int> TempObj;
	DListNode<int> TempObj1;
}
