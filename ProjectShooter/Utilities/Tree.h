#pragma once
#include "DoubleLinkedList.h"




template<class DataType>
class Tree
{

public:
	 typedef Tree<DataType> Node;
	 DataType m_data;
	 Node * m_parent;
	 DoubleLinkedList<Node*> m_children;


	 Tree()
	 {
		 m_parent = 0;
	 }
	 ~Tree()
	 {
		 Destroy();
	 }
	 template<class DataType>
	 void Destroy()
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
	 int Count()
	 {
		 int c = 1;
		 DoubleLinkedList<Node*> itr = m_children.GetIterator();
		 for (itr.Start(); itr.Valid(); itr.Forth())
			 c += itr.Item()->Count();
		 return c;
	 }
};


template<class DataType>
class TreeIterator
{
public:
	typedef Tree<DataType> Node;
	Node * m_node;
	SDoubleLinkedListIterator<Node*> m_childitr;

	TreeIterator(Node* p_node = 0)
	{
		*this = p_node;
	}

	void operator= (Node* p_node)
	{
		m_node = p_node;
		ResetIterator();
	}

	void ResetIterator()
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

	void Up()
	{
		if (m_node != 0)
		{
			m_node = m_node->m_parent;
		}
		ResetIterator();
	}

	void Down()
	{
		if (m_childitr.Valid())
		{
			m_node = m_childitr.Item();
			ResetIterator();
		}
	}
};