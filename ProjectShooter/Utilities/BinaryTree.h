#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "DoubleLinkedList.h"

template<class DataType>
class BinaryTree
{
public:
	typedef BinaryTree<DataType> Node;
	DataType m_data;
	Node *parent;
	Node *leftChild;
	Node *rightChild;

	static void Preorder(Node  *p_node, void(*p_process)(Node*));
	static void Postorder(Node* p_node, void(*p_process)(Node*));
	static void Inorder(Node  *p_node, void(*p_process)(Node*));
	int Count();

	BinaryTree();
	~BinaryTree();
};

template<class DataType>
class BinarySearchTree
{
public:
	typedef BinaryTree<DataType> Node;
	Node* m_root;
	int(*m_compare)(DataType, DataType);

	BinarySearchTree(int(*p_compare)(DataType, DataType));
	~BinarySearchTree();

	void Insert(DataType p_data);
};

#include "BinaryTree.cpp";

#endif