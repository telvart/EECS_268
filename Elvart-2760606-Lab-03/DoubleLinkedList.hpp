/**
*	@file: DoubleLinkedList.hpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 9.23.15
*	@brief:Implementation of methods declared in DoubleLinkedList.h
*/
#include <iostream>

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_front=nullptr;
	m_back=nullptr;
	m_size=0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Node<T>* traverse;
	while (m_front!=nullptr)
	{
		traverse=m_front->getNext();
		delete m_front;
		m_front=traverse;
	}
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
	return ((m_front==nullptr)&&(m_back==nullptr));
}

template <typename T>
int DoubleLinkedList<T>::size() const
{
	return m_size;
}

template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	Node<T>* temp=new Node<T>;
	temp->setValue(value);
	if (isEmpty())
	{
		temp->setPrevious(nullptr);
		temp->setNext(nullptr);
		m_front=temp;
		m_back=temp;
	}
	else
	{
		temp->setPrevious(nullptr);
		temp->setNext(m_front);
		m_front->setPrevious(temp);
		m_front=temp;
	}
	m_size++;
}

template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
	if (isEmpty())
	{
		pushFront(value);
	}
	else
	{
		Node<T>* temp = new Node<T>;
		temp->setValue(value);

		m_back->setNext(temp);
		temp->setPrevious(m_back);
		temp->setNext(nullptr);
		m_back=temp;
		m_size++;
	}
}

template <typename T>
bool DoubleLinkedList<T>::removeBack()
{
	if (isEmpty())
	{
		return false;
	}
	else if (m_size==1)
	{
		delete m_front;
		m_front=nullptr;
		m_back=nullptr;
		m_size--;
	}
	else
	{
		Node<T>* temp=m_back;
		m_back->getPrevious() ->setNext(nullptr);
		m_back=m_back->getPrevious();
		delete temp;
		m_size--;
	}
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::removeFront()
{
	if (isEmpty())
	{
		return false;
	}
	else if (m_size==1)
	{
		delete m_front;
		m_front=nullptr;
		m_back=nullptr;
		m_size--;
	}
	else
	{
		Node<T>* temp=m_front;
		m_front->getNext() -> setPrevious(nullptr);
		m_front=m_front->getNext();
		delete temp;
		m_size--;
	}
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value)
{
	Node<T>* temp;
	if (isEmpty() || find(value)==nullptr)
	{
		return false;
	}
	else if (m_size==1)
	{
		delete m_front;
		m_front=nullptr;
		m_back=nullptr;
		m_size--;
		return true;
	}	
	else if (find(value)==m_front)
	{	
		removeFront();
		return true;
	}
	else if (find(value)==m_back)
	{
		removeBack();
		return true;
	}
	else
	{
		temp=find(value);
		temp->getPrevious() -> setNext(temp->getNext());
		temp->getNext() -> setPrevious(temp->getPrevious());
		delete temp;
		m_size--;
		return true;
	}
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listvalue, T newvalue) throw (std::runtime_error)
{
	Node<T>* location=find(listvalue);

	if (isEmpty() || location==nullptr)
	{
		throw std::runtime_error("The value is not in the list");
	}
	else if (location==m_front || m_size==1)
	{
		pushFront(newvalue);
	}
	else
	{
		Node<T>* temp = new Node<T>;
		temp->setValue(newvalue);

		location->getPrevious() -> setNext(temp);
		temp->setPrevious(location->getPrevious());
		location->setPrevious(temp);
		temp->setNext(location);
		m_size++;
	}
}

template <typename T>
void DoubleLinkedList<T>::insertBehind(T listvalue, T newvalue) throw (std::runtime_error)
{
	Node<T>* location=find(listvalue);
	if (isEmpty() || location==nullptr)
	{
		throw std::runtime_error("The value is not in the list");
	}
	else if (location==m_back || m_size==1)
	{
		pushBack(newvalue);
	}
	else
	{
		Node<T>* temp=new Node<T>;
		temp->setValue(newvalue);

		temp->setPrevious(location);
		temp->setNext(location->getNext());
		location->getNext() -> setPrevious(temp);
		location->setNext(temp);
		m_size++;
	}
}

template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const
{
	Node<T>* traverse=m_front;
	while (traverse != nullptr)
	{
		if (traverse->getValue()==value)
		{
			return traverse;
		}
		traverse=traverse->getNext();
	}
	return nullptr;
}

template <typename T>
void DoubleLinkedList<T>::printList() const
{
	if (isEmpty())
	{
		std::cout<<"";
	}
	else
	{
		Node<T>* traverse=m_front;
		while (traverse != nullptr)
		{
			std::cout<<traverse->getValue()<<" ";
			traverse=traverse->getNext();
		}
	}
}













