/**
*	@file: Node.hpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 9.23.15
*	@brief: Implementation of methods declared in Node.h
*/

template <typename T>
Node<T>::Node()
{
	m_value=T();
	m_next=nullptr;
	m_previous=nullptr;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next=next;
}

template <typename T>
void Node<T>::setPrevious(Node<T>* prev)
{
	m_previous=prev;
}

template <typename T>
void Node<T>::setValue(T value)
{
	m_value=value;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return m_next;
}

template <typename T>
Node<T>* Node<T>::getPrevious()
{
	return m_previous;
}

template <typename T>
T Node<T>::getValue()
{
	return m_value;
}
