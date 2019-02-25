#pragma once

template<class DataType>
class BinaryTree
{
public:
	DataType data;
	typedef BinaryTree<DataType> Node;
	Node *parent;
	Node *leftChild;
	Node *rightChild;	

	BinaryTree();
	~BinaryTree();
	void Append(Node *);
	int Count();
	static void Destroy(Node *);
	static void Preorder(Node *);
	static void Postorder(Node *, void (func*)(Node * node));
	static void Inorder(Node *);
};

template<class DataType>
void BinaryTree<DataType>::Preorder(Node * node)
{
	if (node != nullptr)
	{
		std::cout << node->data << std::endl;
		Preorder(node->leftChild);
		Preorder(node->rightChild);
	}
	
}

template<class DataType>
void BinaryTree<DataType>::Postorder(Node * node, void (func*)(Node * node))
{
	if (node != nullptr)
	{
		Postorder(node->leftChild);
		Postorder(node->rightChild);
		std::cout << node->data << std::endl;
	}
}

template<class DataType>
void BinaryTree<DataType>::Inorder(Node * node)
{
	if (node == nullptr)
		return;
	Inorder(node->leftChild);
	std::cout << node->data << std::endl;
	Inorder(node->rightChild);
}

template<class DataType>
BinaryTree<DataType>::BinaryTree()
{
	parent = nullptr;
	leftChild = nullptr;
	rightChild = nullptr;
}

//TODO delete all the child nodes
template<class DataType>
BinaryTree<DataType>::~BinaryTree()
{
}

template<class DataType>
int BinaryTree<DataType>::Count()
{
	int c = 1;
	if (leftChild)
		c += leftChild->Count();
	if (rightChild)
		c += rightChild->Count();
	return c;
}


template<class DataType>
void BinaryTree<DataType>::Destroy(Node *node)
{
	if (node == nullptr)
		return;
	if (node->leftChild)
	{
		node->leftChild->Destroy(node->leftChild);
		node->leftChild = nullptr;
	}
	if (node->rightChild)
	{
		node->rightChild->Destroy(node->rightChild);
		node->rightChild = nullptr;
	}
	delete node;
	node = nullptr;
}

//if (leftChild)
//delete leftChild;
//leftChild = 0;
//if (rightChild)
//delete rightChild;
//rightChild = 0;
//
//
//










