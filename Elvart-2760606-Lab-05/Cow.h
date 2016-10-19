/**     @name:Cow.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.7.15
*	@brief: A more specialized FarmAnimal with members unique to cows
*/ 

#ifndef COW_H
#define COW_H
#include "FarmAnimal.h"
class Cow: public FarmAnimal
{
 public:
	/*
	@pre: none
	@post: a Cow instance will be created and its name and sound will be Cow and Moo respectively
	@return: none
	*/
	Cow();
	/*
	@pre: a Cow instance exists
	@post: none
	@return: the current value of m_milkProduced
	*/
	double getMilkProduced() const;
	/*
	@pre: a Cow instance exists
	@post: m_milkProduced will be changed to the parameter
	@return: none
	*/
	void setMilkProduced(double gallons);
 protected:
	double m_milkProduced;
};
#endif
