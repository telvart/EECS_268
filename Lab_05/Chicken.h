/**     @name: Chicken.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.7.15
*	@brief: A more specialized FarmAnimal that has variables unique to chickens
*/ 

#ifndef CHICKEN_H
#define CHICKEN_H
#include "FarmAnimal.h"

class Chicken: public FarmAnimal
{

 public:
	/*
	@pre: none
	@post: a Chicken instance will be created, m_name will be Chicken and m_sound will be Cluck
	@return: none
	*/
	Chicken();

 protected:

	/*
	@pre: a Chicken instance exists
	@post: none
	@return: the current value of m_eggs
	*/
	int getEggs() const;
	/*
	@pre: a Chicken instance exists
	@post: m_eggs will be changed to the parameter
	@return: none
	*/
	void setEggs(int Eggs);


	int m_eggs;
};

#endif
