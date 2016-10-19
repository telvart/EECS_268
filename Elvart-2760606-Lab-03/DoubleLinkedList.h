/**
*	@file: DoubleLinkedList.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:9.23.15
*	@brief:A List capable of storing any type (mostly), each node is doublely linked to two others
*/

#include "Node.h"
#include <stdexcept>

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H


template <typename T>
class DoubleLinkedList
{
  public:
	/*
	@pre none
	@post a DoubleLinkedList instance will be created and initialized
	@return none
	*/
	DoubleLinkedList();
	/*
	@pre none
	@post every node in the the list will be deleted to prevent memory leaks
	@return none
	*/
	~DoubleLinkedList();
	/*
	@pre a DLL exists
	@post none
	@return true if the list is empty, false otherwise
	*/
	bool isEmpty() const;
	/*
	@pre DLL exists
	@post none
	@return the current value of m_size
	*/
	int size() const;
	/*
	@pre DLL exists
	@post a node is added to the front of the list that contains the value of the parameter
	@return none
	*/
	void pushFront(T value);
	/*
	@pre DLL exists
	@post a node is added to the back of the list that contains the value of the parameter
	@return none
	*/
	void pushBack(T value);
	/*
	@pre DLL exists
	@post the back node will be deleted from the list
	@return true if a node could be deleted, otherwise false
	*/
	bool removeBack();
	/*
	@pre DLL exists
	@post the front node will be deleted from the list
	@return true if a node could be deleted, otherwise false
	*/
	bool removeFront();
	/*
	@pre DLL exists
	@post if a node containg the parameter is in the list, it will be removed
	@return true if the node existed and was deleted, otherwise false
	*/
	bool remove(T value);
	/*
	@pre DLL exists
	@post a node will be inserted ahead of the node containing listvalue containing newvalue
	@return true if the listvalue was in the list and a node could be added
	@throws std::runtime_error if the listvalue wasnt in the list and newvalue wasnt added
	*/
	void insertAhead(T listvalue, T newvalue) throw (std::runtime_error);
	/*
	@pre DLL exists
	@post a node will be inserted behind the node containing listvalue containing newvalue
	@return true if the newvalue could be added behind a listvalue
	@throws std::runtime_error if listvalue wasnt in the list and newvalue wasnt added 
	*/
	void insertBehind(T listvalue, T newvalue) throw (std::runtime_error);
	/*
	@pre DLL exists
	@post none
	@return a pointer to the node that contains the parameter, otherwise nullptr
	*/
	Node<T>* find(T value) const;
	/*
	@pre DLL exists
	@post every element in the list will be printed to the consoel
	@return none
	*/
	void printList() const;

  private:

	Node<T>* m_front;
	Node<T>* m_back;
	int m_size;
};

#include "DoubleLinkedList.hpp"
#endif

