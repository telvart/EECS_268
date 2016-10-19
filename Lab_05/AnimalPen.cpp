/**     @name:AnimalPen.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.7.15
*	@brief: Implementation of methods declared in AnimalPen.h
*/ 

#include "AnimalPen.h"

AnimalPen::AnimalPen()
{
}


AnimalPen::~AnimalPen()
{
	while (!isPenEmpty())
	{
		releaseAnimal();
	}
}


void AnimalPen::addAnimal(FarmAnimal* animal)
{
	push(animal);
}

FarmAnimal* AnimalPen::peekAtNextAnimal()
{
	return peek();
}

void AnimalPen::releaseAnimal()
{
	pop();
}

bool AnimalPen::isPenEmpty()
{
	return isEmpty();
}
