#ifdef BINARY_TREE_H

template<class DataType>
BinaryTree<DataType>::BinaryTree()
{
	parent = nullptr;
	leftChild = nullptr;
	rightChild = nullptr;
}

template<class DataType>
BinaryTree<DataType>::~BinaryTree()
{
	if (leftChild)
		delete leftChild;
	leftChild = nullptr;
	if (rightChild)
		delete rightChild;
	rightChild = nullptr;
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
void BinaryTree<DataType>::Preorder(Node  *p_node, void(*p_process)(Node*))
{
	if (p_node != nullptr) {
		p_process(p_node);
		Preorder(p_node->leftChild);
		Preorder(p_node->rightChild);
	}
}

template<class DataType>
void BinaryTree<DataType>::Postorder(Node  *p_node, void(*p_process)(Node*))
{
	if (p_node != nullptr) {
		Postorder(p_node->leftChild);
		Postorder(p_node->rightChild);
		p_process(p_node);
	}
}

template<class DataType>
void BinaryTree<DataType>::Inorder(Node  *p_node, void(*p_process)(Node*))
{
	if (p_node != nullptr) {
		Postorder(p_node->leftChild);
		p_process(p_node);
		Postorder(p_node->rightChild);
	}
}

template<class DataType>
BinarySearchTree<DataType>::BinarySearchTree(int(*p_compare)(DataType, DataType))
{
	m_root = nullptr;
	m_compare = p_compare;
}

template<class DataType>
BinarySearchTree<DataType>::~BinarySearchTree()
{
	if (m_root != 0)
		delete m_root;
}

template<class DataType>
void BinarySearchTree<DataType>::Insert(DataType p_data)
{
	Node* current = m_root;
	if (m_root == nullptr)
	{
		m_root = new Node;
		m_root->m_data = p_data;
	}

	else
	{
		while (current != 0)
		{
			if (m_compare(p_data, current->m_data) < 0)
			{
				if (current->leftChild == 0)
				{
					current->leftChild = new Node;
					current->leftChild->m_data = p_data;
					current->leftChild->parent = current;
					current = 0;
				}
				else
					current = current->leftChild;
			}
			else
			{
				if (current->rightChild == 0)
				{
					current->rightChild = new Node;
					current->rightChild->m_data = p_data;
					current->rightChild->parent = current;
					current = 0;
				}
				else
					current = current->rightChild;
			}
		}
	}
}

#endif