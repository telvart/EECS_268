/**
*	@file:
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:
*	@brief:
*/

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root=nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	if (!(other.isEmpty()))	
	{		
		m_root=new Node<T>(*(other.m_root));
	}
	else
	{
		m_root=nullptr;
	}
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteTree(m_root);
}

template <typename T>
BSTI<T>* BinarySearchTree<T>::clone()
{

	BSTI<T>* BST2=new BinarySearchTree<T>(*(this));	
	return ((BSTI<T>*)BST2);
	
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	return (m_root==nullptr);
}

template <typename T>
bool BinarySearchTree<T>::add(T value)
{
	if(isEmpty())
	{
		m_root=new Node<T>;
		m_root->setValue(value);
		return true;
	}
	else
	{
		add(value,m_root);
	}
	return false;
}

template <typename T>
bool BinarySearchTree<T>::search(T value) const
{
	return search(value, m_root);
}

template <typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const
{
	std::vector<T> vec;
	treeToVector(m_root, order, vec);
	return vec;
}

template <typename T>
void BinarySearchTree<T>::treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec) const
{
	if (subtree==nullptr)
	{
		return;
	}
	switch(order)
	{
		case Order::PRE_ORDER:
			vec.push_back(subtree->getValue());
			treeToVector(subtree->getLeft(),order,vec);
			treeToVector(subtree->getRight(),order,vec);
			break;
		case Order::IN_ORDER:
			treeToVector(subtree->getLeft(),order,vec);
			vec.push_back(subtree->getValue());
			treeToVector(subtree->getRight(),order,vec);
			break;
		case Order::POST_ORDER:
			treeToVector(subtree->getLeft(),order,vec);
			treeToVector(subtree->getRight(),order,vec);
			vec.push_back(subtree->getValue());
			break;
	}
}	

template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	if (value < subtree->getValue())
	{
		if (subtree->getLeft() != nullptr)
		{
			add(value,subtree->getLeft());
		}
		else
		{
			Node<T>* temp=new Node<T>;
			temp->setValue(value);
			subtree->setLeft(temp);
			temp->setLeft(nullptr);
			temp->setRight(nullptr);
			return true;
		}
	}
	else if (value >= subtree->getValue())
	{
		if (subtree->getRight() != nullptr)
		{
			add(value,subtree->getRight());
		}
		else
		{
			Node<T>* temp=new Node<T>;
			temp->setValue(value);
			subtree->setRight(temp);
			temp->setLeft(nullptr);
			temp->setRight(nullptr);
			return true;
		}
	}
	return false;
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree)
{
	if (subtree != nullptr)
	{
		deleteTree(subtree->getLeft());
		deleteTree(subtree->getRight());
		delete subtree;
	}
}

template <typename T>
bool BinarySearchTree<T>::search(T value, Node<T>* subtree) const
{
		if (subtree !=nullptr)
		{
			if (value == subtree->getValue())
			{
				return true;
			}
			else if (value < subtree->getValue())
			{
				return search(value, subtree->getLeft());
			}
			else if (value > subtree->getValue())
			{
				return search(value,subtree->getRight());
			}
		}
		else
		{
			return false;
		}
}

template <typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const
{
	if (subtree==nullptr)
	{
		return;
	}
	switch(order)
	{	
		case Order::PRE_ORDER:
			std::cout<<subtree->getValue()<<" ";
			printTree(subtree->getLeft(),order);
			printTree(subtree->getRight(),order);
			break;

		case Order::IN_ORDER:
			printTree(subtree->getLeft(),order);
			std::cout<<subtree->getValue()<<" ";
			printTree(subtree->getRight(),order);
			break;

		case Order::POST_ORDER:
			printTree(subtree->getLeft(),order);
			printTree(subtree->getRight(),order);
			std::cout<<subtree->getValue()<<" ";
			break;
	}
}

template <typename T>
void BinarySearchTree<T>::sortedPrint() const
{
	printTree(IN_ORDER);
}

template <typename T>
void BinarySearchTree<T>::printTree(Order order) const
{
	printTree(m_root,order);
}











