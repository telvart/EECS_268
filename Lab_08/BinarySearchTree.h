/**
*	@file: BinarySearchTree.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 11/5/15
*	@brief: A Binary Search Tree class, houses real numbers (in this format)
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BSTI.h"
#include "Node.h"


template <typename T>
class BinarySearchTree: public BSTI<T>
{
 public:

	/*
	@pre none
	@post a BinarySearchTree will be created and initialized
	@return none
	*/
	BinarySearchTree();
	/*
	@pre another BinarySearchTree exists
	@post a deep copy of the other BinarySearchTree will be created
	@return none
	*/
	BinarySearchTree(const BinarySearchTree<T>& other);
	/*
	@pre a BinarySearchTree exists
	@post The BinarySearchTree will be deleted to prevent memory leaks
	@return none
	*/
	~BinarySearchTree();
	/*
	@pre a BinarySearchTree exists
	@post A BinarySearchTree will be deep copied into a new one
	@return a pointer the clone of the other tree
	*/
	BSTI<T>* clone();
	/*
	@pre a BinarySearchTree exists
	@post none
	@return true if the BST is empty, otherwise false
	*/
	bool isEmpty() const;
	/*
	@pre a BinarySearchTree exists
	@post the value will be added into the tree
	@return true if the value could be added to the tree, false otherwise
	*/
	bool add(T value);
	/*
	@pre a BinarySearchTree exists
	@post none
	@return true if the value is in the tree, otherwise false
	*/
	bool search(T value) const;
	/*
	@pre a BinarySearchTree exists
	@post none
	@return a vector with the contents of the tree in the order specified
	*/
	std::vector<T> treeToVector(Order order) const;
	void treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec) const;

	void sortedPrint() const;
	void printTree(Order order) const;

 private:
	/*
	@pre a BinarySearchTree exists
	@post adds the value to the correct subtree (left or right) 
	@return true if the value could be added, otherwise false
	*/
	bool add(T value, Node<T>* subtree);
	/*
	@pre a BinarySearchTree exists
	@post the subtree passed in will be deleted
	@return none
	*/
	void deleteTree(Node<T>* subtree);
	/*
	@pre a BinarySearchTree exists
	@post none
	@return true if the value is in the subtree passed in, otherwise false
	*/
	bool search(T value, Node<T>* subtree) const;
	/*
	@pre a BinarySearchTree exists
	@post the numbers in the tree will be printed in the order specified
	@return none
	*/
	void printTree(Node<T>* subtree, Order order) const;
	
	Node<T>* m_root;
};

#include "BinarySearchTree.hpp"
#endif












