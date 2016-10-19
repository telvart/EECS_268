/**
*	@file:BSTI.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 11/4/15
*	@brief: Acts as a contract for the BinarySearchTree class to implement
*/

#ifndef BSTI_H
#define BSTI_H

#include <vector>

enum Order
{
	PRE_ORDER,IN_ORDER,POST_ORDER
};


template <typename T>
class BSTI
{
public:
	virtual ~BSTI(){};
	virtual BSTI<T>* clone()=0;
	virtual bool isEmpty() const=0;
	virtual bool add(T value)=0;
	virtual bool search(T value) const=0;
	virtual void printTree(Order order) const=0;
	virtual void sortedPrint()const=0;
	virtual std::vector<T> treeToVector(Order order) const = 0;

};

#endif
