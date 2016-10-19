/**     @name:Stack.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:9.31.15
*	@brief: Inherits from StackInterface.h, it is a stack capable of housing any type
*/ 

#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"

template <typename T>
class Stack: public StackInterface<T>
{

public:
	/*
	@pre none
	@post a stack will be created and initialized
	@return none
	*/
	Stack();
	/*
	@pre none
	@post all the nodes in the stack will be deallocated 
	@return none
	*/
	~Stack();
	/*
	@pre none
	@post none
	@return true if the stack is empty, otherwise false
	*/
	bool isEmpty() const;
	/*
	@pre none
	@post a node will be added to the stack that contains the value newEntry
	@return none
	*/
	void push(const T newEntry);
	/*
	@pre none
	@post the node at the top of the stack will be removed
	@return none
	@throws PVE if pop is attempted on an empty stack
	*/
	void pop() throw(PreconditionViolationException);
	/*
	@pre none
	@post none
	@return the value in the node at the top of the stack
	@throws PVE if peek is attempted on an empty stack
	*/
	T peek() const throw(PreconditionViolationException);
	/*
	@pre none
	@post none
	@return the current value of m_size
	*/
	int size() const;
	/*
	@pre T is able to be printed to the console
	@post all values in the stack will be printed seperated by spaces
	@return none
	*/
	void print() const;

protected:

	Node<T>* m_top;
	int m_size;	
};

#include "Stack.hpp"
#endif

