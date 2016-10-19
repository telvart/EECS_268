/**     @name:Stack.hpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:9.31.15
*	@brief:Implementation of methods declared in Stack.h
*/ 

#include <iostream>

template <typename T>
Stack<T>::Stack()
{
	m_size=0;
	m_top=nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return (m_top==nullptr);
}

template <typename T>
void Stack<T>::push(const T newEntry)
{
	Node<T>* temp=new Node<T>;
	temp->setValue(newEntry);

	if (isEmpty())
	{
		m_top=temp;
		temp->setNext(nullptr);	
	}
	else
	{
		temp->setNext(m_top);
		m_top=temp;
	}
	m_size++;
}

template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
	if(isEmpty())
	{
		throw PreconditionViolationException("Attempted pop on an empty list");
	}
	else if(m_size==1)
	{
		delete m_top;
		m_top=nullptr;
	}
	else
	{
		Node<T>* temp=m_top;
		m_top=m_top->getNext();
		delete temp;
	}
	m_size--;
}

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if (isEmpty())
	{
		throw PreconditionViolationException("Peek attempted on an empty stack");
	}
	else
	{
		return (m_top->getValue());
	}
}

template <typename T>
int Stack<T>::size() const
{
	return m_size;
}

template <typename T>
void Stack<T>::print() const
{
	if (isEmpty())
	{
		std::cout<<"";
	}
	else
	{
		Node<T>* traverse=m_top;
		while (traverse!=nullptr)
		{
			std::cout<<traverse->getValue()<<" ";
			traverse=traverse->getNext();
		}
	}
}
















