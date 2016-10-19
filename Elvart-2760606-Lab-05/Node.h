/**
*	@file: Node.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 9.23.15
*	@brief: A container capable of storing most types, used in the Stack class
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{

  public:
	/*
	@pre None
	@post A node is created and initialized
	@return none
	*/
	Node();
	/*
	@pre a node exists
	@post m_next will change to the parameter
	@return none
	*/
	void setNext(Node<T>* next);
	/*
	@pre a node exists
	@post m_value will change to the parameter depending on the type instsantiated with
	@return none
	*/
	void setValue(T value);
	/*
	@pre a node exists
	@post none
	@return the current value of m_next
	*/
	Node<T>* getNext();
	/*
	@pre a node exists and its value has been set
	@post none
	@return the current value of m_value
	*/
	T getValue();

  private:

	T m_value;
	Node<T>* m_next;	
};

#include "Node.hpp"
#endif
