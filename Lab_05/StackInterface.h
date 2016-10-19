/**     @name:StackInterface.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:9.31.15
*	@brief: Acts as a contract that all inheriting classes must fulfill, outline of a stack data structure that can hoouse any type.
*/ 

#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

#include "PreconditionViolationException.h"

template <typename T>
class StackInterface
{

 public:
	/*
	@pre definitionless destructor
	@post must be defined later on in an inherited class
	@return none
	*/
	virtual ~StackInterface() {};
	/*
	@pre none
	@post none
	@return true if the stack is empty, otherwise false
	*/
	virtual bool isEmpty() const = 0;
	/*
	@pre none
	@post a node will be added to the stack that contains the value newEntry
	@return none
	*/
	virtual void push(const T newEntry) = 0;
	/*
	@pre none
	@post the node at the top of the stack will be removed
	@return none
	@throws PVE if pop is attempted on an empty stack
	*/
	virtual void pop() throw(PreconditionViolationException) = 0;
	/*
	@pre none
	@post none
	@return the value in the node at the top of the stack
	@throws PVE if peek is attempted on an empty stack
	*/
	virtual T peek() const throw(PreconditionViolationException) = 0;
	/*
	@pre none
	@post none
	@return the current value of m_size
	*/
	virtual int size() const = 0;
	/*
	@pre T is able to be printed to the console
	@post all values in the stack will be printed seperated by spaces
	@return none
	*/
	virtual void print() const = 0;
};
#endif

