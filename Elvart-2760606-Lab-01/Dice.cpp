/**
*	@file: Dice.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.2
*	Purpose: implementation of methods in the dice class.
*/

#include "Dice.h"

Dice::Dice() 
{ 
	m_numSides = 6;
	/** initialize random seed: */
	srand (time(NULL));//Old C style NULL
}


Dice::Dice(int numSides)
{
	m_numSides = numSides;
	/** initialize random seed: */
	srand (time(NULL));//Old C style NULL
}


int Dice::getNumSides()
{
	return(m_numSides);
}

int Dice::roll()
{
	
	/** Get back a pseudo-random number */
	return(rand()%m_numSides + 1);
}
