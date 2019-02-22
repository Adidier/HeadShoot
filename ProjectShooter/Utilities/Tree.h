#ifndef TREE_H
#define TREE_H

#include "DoubleLinkedList.h"

template<class DataType>
class Tree
{
public:
	 typedef Tree<DataType> Node;
	 DataType m_data;
	 Node * m_parent;
	 DoubleLinkedList<Node*> m_children;

	 Tree();
	 ~Tree();

	 void Destroy();	 
	 int Count();

	 void Append(Node * node, DataType data);
	 void Preorder(Tree<DataType>* p_node, void(*p_process)(Tree<DataType>*));
	 void Postorder(Tree<DataType>* p_node, void(*p_process)(Tree<DataType>*));
};


template<class DataType>
class TreeIterator
{
public:
	typedef Tree<DataType> Node;
	Node * m_node;
	SDoubleLinkedListIterator<Node*> m_childitr;

	TreeIterator(Node* p_node = 0);

	void operator= (Node* p_node);

	void ResetIterator();
	void Up();
	void Down();
};

#include "Tree.cpp"

#endif

