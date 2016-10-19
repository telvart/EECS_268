/**
*	@file: Node.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.14
*	@brief: A container to be used in a list or other data structures, capable of storing ints
*/
#ifndef NODE_H
#define NODE_h

class Node
{
 public:
	/*
	@pre none
	@post a node is created and initialized
	@return none
	*/
	Node();
	/*
	@pre a node exists
	@post the m_value of the node is changed to the parameter val
	@return none
	*/
	void setValue(int val);
	/*
	@pre 2 nodes exist
	@post the Node* m_next is changed to the parameter next
	@return none
	*/
	void setNext(Node* next);
	/*
	@pre a node exists
	@post none
	@return the current value of m_value for the node
	*/	
	int getValue() const;
	/*
	@pre a node exists
	@post none
	@return either nullptr or a pointer to the next node in the list
	*/
	Node* getNext() const;

 private:
	int m_value;
	Node* m_next;
};

#endif
