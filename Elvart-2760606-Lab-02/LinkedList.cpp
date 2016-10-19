/**
*	@file: LinkedList.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.14
*	@brief: Implementation of the LinkedList class and it's methods
*/
#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_front=nullptr;
	m_size=0;
}

LinkedList::~LinkedList()
{
	Node* traverse;
	while (m_front!=nullptr)
	{
		traverse=m_front->getNext();
		delete m_front;
		m_front=traverse;
	}
}

bool LinkedList::isEmpty() const
{
	return(m_front==nullptr);
}

int LinkedList::size() const
{
	return m_size;
}

bool LinkedList::search(int value)
{
	Node* temp=m_front;
	while (temp!=nullptr)
	{
		if (temp->getValue()==value)
		{
			return true;
		}
		temp=temp->getNext();
	}
	return false;
}

void LinkedList::printList() const
{
	if(isEmpty())
	{
		std::cout<<"";
	}
	else
	{
		Node* traverse=m_front;
		while (traverse!=nullptr)
		{
			std::cout<<traverse->getValue()<<" ";
			traverse=traverse->getNext();
		}
	}
}

void LinkedList::addBack(int value)
{
	if (isEmpty())
	{
		addFront(value);
	}
	else
	{
		Node* traverse=m_front;
		while (traverse->getNext()!=nullptr)
		{
			traverse=traverse->getNext();
		}
		Node* temp=new Node();
		temp->setValue(value);
		traverse->setNext(temp);
		m_size++;
	}
}

void LinkedList::addFront(int value)
{
	if (isEmpty())
	{
                m_front=new Node();
		m_front->setNext(nullptr);
		m_front->setValue(value);
	}
	else
	{
		Node* temp=new Node();
		temp->setNext(m_front);
		m_front=temp;
		m_front->setValue(value);
	}
	m_size++;
}

bool LinkedList::removeBack()
{
	if (isEmpty())
	{
		return false;
	}
	else if (m_size==1)
	{
		removeFront();
	}
	else
	{
		Node* traverse=m_front;
		Node* temp; //temp is needed to look at node before the last
		while (traverse->getNext()!=nullptr)
		{
			temp=traverse;
			traverse=temp->getNext();
		}
		temp->setNext(nullptr);
		delete traverse;
		m_size--;	
	}
	return true;
}

bool LinkedList::removeFront()
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		Node* temp=m_front;
		m_front=m_front->getNext();
		delete temp;
		m_size--;
		return true;
	}
}
