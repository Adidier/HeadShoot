
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
		m_head = m_tail = new SListNode<Datatype>;
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
void LinkedList<Datatype>::Prepend(Datatype p_data)
{
	// Crea un nuevo nodo
	SListNode<Datatype>* newnode = new SListNode<Datatype>;
	newnode->m_data = p_data;
	newnode->m_next = m_head;
	// Coloca la cabeza del nodo y la cola del mismo si es necesario
	m_head = newnode;
	if (m_tail == 0)
		m_tail = m_head;
	m_count++;
}

template<class Datatype>
void LinkedList<Datatype>::RemoveHead()
{
	LinkedList LlamaAlConstructor;
	SListNode<Datatype>* node = 0;
	if (m_head != 0)
	{
		// Hace que al puntador del nodo pase al siguiente.
		node = m_head->m_next;
		// Luego borra la cabeza y crea un apuntador que apunta al nodo
		delete m_head;
		m_head = node;
		// Si la cabeza es nula, entonces acabas de borrar el único nodo en la lista
		// En la lista.  La cola la hace 0
		if (m_head == 0)
			m_tail = 0;
		m_count--;
	}
}

template<class Datatype>
void LinkedList<Datatype>::RemoveTail()
{
	SListNode<Datatype>* node = m_head;
	// Si la lista no está vacía, entonces remueve un nodo
	if (m_head != 0)
	{
		// Si la cabeza is igual que la cola, entonces la lista tiene
		// un nodo y lo estamos removiendo
		if (m_head == m_tail)
		{
			// Borra el nodo y asigna ambos apuntadores a 0
			delete m_head;
			m_head = m_tail = 0;
		}
		else
		{
			// Salta hacia delante hasta que encuentre un nodo justo antes de la cola

			while (node->m_next != m_tail)
				node = node->m_next;
			// Hace que la cola apunte al nodo antes de la cola y borra la cola vieja
			m_tail = node;
			delete node->m_next;
			node->m_next = 0;
		}
		m_count--;
	}
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
SListIterator<Datatype>::SListIterator(LinkedList<Datatype>* p_list, SListNode<Datatype>* p_node)
{
	m_list = p_list;
	m_node = p_node;
}

template<class Datatype>
void SListIterator<Datatype>::Start()
{
	if (m_list != 0)
		m_node = m_list->m_head;
}

template<class Datatype>
void SListIterator<Datatype>::Forth()
{
	if (m_node != 0)
		m_node = m_node->m_next;
}

template<class Datatype>
Datatype & SListIterator<Datatype>::Item()
{
	return m_node->m_data;
}

template<class Datatype>
bool SListIterator<Datatype>::Valid()
{
	return (m_node != 0);
}

template<class Datatype>
SListIterator<Datatype> SListIterator<Datatype>::GetIterator()
{
	return SListIterator<Datatype>(this, m_head);
}

template<class Datatype>
void SListIterator<Datatype>::Insert(SListIterator<Datatype>& p_iterator, Datatype p_data)
{
	// Si el iterador no pertenece a esta lista, entonces no hace nada
	if (p_iterator.m_list != this)
		return;
	if (p_iterator.m_node != 0)
	{
		// Si el iterador es válido, entonces inserta un nodo
		p_iterator.m_node->InsertAfter(p_data);
		// Si el iterador es el nodo de la cola, entonces actualiza el 
		// apuntador de la cola al nuevo nodo
		if (p_iterator.m_node == m_tail)
		{
			m_tail = p_iterator.m_node->m_next;
		}
		m_count++;
	}
	else
	{
		// Si el iterador es inválido, entonces adjunta(append) la información
		Append(p_data);
	}
}

template<class Datatype>
void SListIterator<Datatype>::Remove(SListIterator<Datatype>& p_iterator)
{
	SListNode<Datatype>* node = m_head;
	// Si el iterador no pertenece a esta lista, no hace nada
	if (p_iterator.m_list != this)
		return;
	// Si el nodo es inválido, no hace nada
	if (p_iterator.m_node == 0)
		return;
	if (p_iterator.m_node == m_head)
	{
		// Mueve el iterador hacia delante y borra la cabeza
		p_iterator.Forth();
		LlamaAlConstructor.RemoveHead();
	}
	else
	{
		// Escanea hacia delante a través de la lista hasta que el nodo
		// principal encuentra el nodo que deseas borrar
		while (node->m_next != p_iterator.m_node)
			node = node->m_next;
		// Moueve el iterador hacia delante
		p_iterator.Forth();
		// Si el nodo que estás borrando es la cola, 
		// entonces actualiza el nodo de la cola
		if (node->m_next == m_tail)
		{
			m_tail = node;
		}
		// Borra el nodo
		delete node->m_next;
		// re-linkea la lista
		node->m_next = p_iterator.m_node;
	}
	m_count--;
}