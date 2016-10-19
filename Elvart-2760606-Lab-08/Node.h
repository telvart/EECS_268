/**
*	@file: Node.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 11/4/15
*	@brief: A container to hold values and point to other nodes, set up for BinarySearchTrees
*/


#ifndef NODE_H
#define NODE_H
template <typename T>
class Node
{
 public:

	/*
	@pre none
	@post a Node instance is created and initialized
	@return none
	*/
	Node();
	/*
	@pre atleast 1 other instance of node exists
	@post the new node will become a deep copy of the node passed in, including its children
	@return none
	*/
	Node(const Node<T>& other);
	/*
	@pre a node exists
	@post none
	@return the current value of m_value
	*/
	T getValue();
	/*
	@pre a node exists
	@post none
	@return the current state of m_left
	*/
	Node<T>* getLeft();
	/*
	@pre a node exists
	@post none
	@return the current state of m_right
	*/
	Node<T>* getRight();
	/*
	@pre a node exists
	@post m_value will be set to the parameter
	@return none
	*/
	void setValue(T value);
	/*
	@pre a node exists
	@post m_left will be set to the parameter
	@return none
	*/
	void setLeft(Node<T>* left);
	/*
	@pre a node exists
	@post m_right will be set to the parameter
	@return none
	*/
	void setRight(Node<T>* right);

 private:
	Node<T>* m_left;
	Node<T>* m_right;
	T m_value;

};

#include "Node.hpp"
#endif
