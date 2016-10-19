/**
*	@file: LinkedList.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.14
*	@brief:A Singly-Linked list data structure to hold ints, has some simple methods to manipulate the list
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList
{
 public:
	/*
	@pre none
	@post a LinkedList is created and initialized
	@return none
	*/
	LinkedList();
	/*
	@pre a LinkedList exists
	@post every node in the list is deleted to prevent memory leaks
	@return none
	*/
	~LinkedList();
	/*
'	@pre a LinkedList exists
	@post none
	@return true if the list has no values, otherwise false
	*/
	bool isEmpty() const;
	/*
	@pre a LinkedList exists
	@post none
	@return the current value of m_size, (number of elements in the list)
	*/
	int size() const;
	/*
	@pre a LinkedList exists
	@post none
	@return true if the parameter is in the list, otherwise false
	*/
	bool search(int value);
	/*
	@pre a LinkedList exists
	@post each value in the list is printed to the console.
		if empty, "The list is empty" will be printed
	@return none
	*/
	void printList() const;
	/*
	@pre a LinkedList exists
	@post the parameter is added to the end of the list
	@return none
	*/
	void addBack(int value);
	/*
	@pre a LinkedList exists
	@post the parameter is added to the front of the list
	@return none
	*/
	void addFront(int value);
	/*
	@pre a LinkedList exists
	@post the node at the end of the list will be removed
	@return true if a node could be deleted, otherwise false
	*/
	bool removeBack();
	/*
	@pre a LinkedList exists
	@post the node at the front of the list will be removed
	@return true if a node could be deleted, otherwise false
	*/
	bool removeFront();
 private:
	Node* m_front;
	int m_size;
};

#endif
