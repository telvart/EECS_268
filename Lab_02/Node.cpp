/**
*	@file: Node.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.14
*	@brief: Implementation of methods for the Node class
*/
#include "Node.h"

Node::Node()
{
	m_value=0;
	m_next=nullptr;
}

void Node::setValue(int val)
{
	m_value=val;
}

void Node::setNext(Node* next)
{
	m_next=next;
}

int Node::getValue() const
{
	return m_value;
}

Node* Node::getNext() const
{
	return m_next;
}
