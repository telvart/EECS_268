/**     @name:AnimalPen.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.7.15
*	@brief: A specialized stack that holds FarmAnimal pointers
*/ 

#ifndef ANIMALPEN_H
#define ANIMALPEN_H

#include "Stack.h"
#include "FarmAnimal.h"

class AnimalPen: public Stack<FarmAnimal*>
{
 public:
	/*
	@pre: none
	@post: an AnimalPen will be created and initialized
	@return: none
	*/
	AnimalPen();
	/*
	@pre: none
	@post: all FarmAnimal(s) in the pen will be released
	@return: none
	*/
	~AnimalPen();
	/*
	@pre: an AnimalPen instance exists
	@post: a FarmAnimal pointer will be added to the pen
	@return: none
	*/
	void addAnimal(FarmAnimal* animal);
	/*
	@pre: an AnimalPen instance exists
	@post: none
	@return: a pointer to the animal at the top of the stack
	@throws: PVE if it is attempted on an empty list
	*/
	FarmAnimal* peekAtNextAnimal();
	/*
	@pre: an AnimalPen instance exists
	@post: the FarmAnimal at the top of the stack will be removed
	@return: none
	@throw: PVE if attempted while the AnimalPen is empty
	*/
	void releaseAnimal();
	/*
	@pre: an AnimalPen instance exists
	@post: none
	@return: true if the AnimalPen is empty, false otherwise
	*/
	bool isPenEmpty();
};
#endif



