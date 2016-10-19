/**
*	@file: Dice.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.2
*	Purpose: creating random numbers for the game to use as dice rolls
*/

#ifndef DICE_H
#define DICE_H

#include <cstdio> /** NULL */
#include <cstdlib> /** srand(), rand() */
#include <ctime> /** time() */


class Dice
{
  public:
	/**
	*  @pre None
	*  @post Creates and initializes a Dice instance
	*  @return Initialzed Dice with 6 sides
	*/
	Dice();

	/**
	*  @pre numSides is 2 or greater
	*  @post Creates and initializes a Dice instance
	*  @return Initialzed Dice with m_numSides initialzed to numSides.
	*/
	Dice(int numSides);

	/**
	*  @pre None
	*  @post Creates and initializes a Dice instance
	*  @return a pseudo-random number from 1 up and including and m_numSides
	*/
	int roll();

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_numSides
	*/
	int getNumSides();

    private:
	int m_numSides;  
    
};
#endif
