#include "Tree.h"
#ifdef TREE_H

template<class DataType>
Tree<DataType>::Tree()
{
	m_parent = 0;
}

template<class DataType>
Tree<DataType>::~Tree()
{
	Destroy();
}

template<class DataType>
void Tree<DataType>::Destroy()
{
	SDoubleLinkedListIterator<Node*> itr = m_children.GetIterator();
	Node * node = 0;
	itr.Start();
	while (itr.Valid())
	{
		node = itr.Item();
		m_children.Remove(itr);
		delete node;
	}
}

template<class DataType>
int Tree<DataType>::Count()
{
	int c = 1;
	SDoubleLinkedListIterator<Node*> itr = m_children.GetIterator();
	for (itr.Start(); itr.Valid(); itr.Forth())
		c += itr.Item()->Count();
	return c;
}

template<class DataType>
void Tree<DataType>::Append(Node * node, DataType data)
{
	if (node != NULL)
	{
		Tree<int>* nodeHijoDerecho = new Tree<int>;
		nodeHijoDerecho->m_parent = node;
		node->m_children.Append(nodeHijoDerecho);
		nodeHijoDerecho->m_data = data;
	}
}

template<class DataType>
void Tree<DataType>::Preorder(Tree<DataType>* p_node, void(*p_process)(Tree<DataType>*))
{
	p_process(p_node);
	DListIterator<Tree<DataType>*> itr = p_node->m_children.GetIterator();
	for (itr.Start(); itr.Valid(); itr.Forth())
		Preorder(itr.Item(), p_process);
}

template<class DataType>
void Tree<DataType>::Postorder(Tree<DataType>* p_node, void(*p_process)(Tree<DataType>*))
{
	DListIterator<Tree<DataType>*> itr = p_node->m_children.GetIterator();
	for (itr.Start(); itr.Valid(); itr.Forth())
		Postorder(itr.Item(), p_process);
	p_process(p_node);
}

template<class DataType>
TreeIterator<DataType>::TreeIterator(Node * p_node)
{
	*this = p_node;
}

template<class DataType>
void TreeIterator<DataType>::operator=(Node * p_node)
{
	m_node = p_node;
	ResetIterator();
}

template<class DataType>
void TreeIterator<DataType>::ResetIterator()
{
	if (m_node != 0)
	{
		m_childitr = m_node->m_children.GetIterator();
	}
	else
	{
		m_childitr.m_list = 0;
		m_childitr.m_node = 0;
	}
}

template<class DataType>
void TreeIterator<DataType>::Up()
{
	if (m_node != 0)
	{
		m_node = m_node->m_parent;
	}
	ResetIterator();
}

template<class DataType>
void TreeIterator<DataType>::Down()
{
	if (m_childitr.Valid())
	{
		m_node = m_childitr.Item();
		ResetIterator();
	}
}

#endif