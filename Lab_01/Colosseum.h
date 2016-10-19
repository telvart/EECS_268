/**
*	@file: Colosseum.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.2
*	Purpose: constructing the pokemon, as well as the methods for attacking and the game itself.
*/

#ifndef COLOSSEUM_H
#define COLOSSEUM_H

#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"

class Colosseum
{
	public:
		//@pre none
		//@post a colosseum instance is created and initialized
		//@return none
		Colosseum();

		//@pre pokemon instance and colosseum instance exist
		//@post all member variables of the pokemon class are changed
		//@return none
		void userBuild(Pokemon& p);

		//@pre pokemon and colosseum instances exist
		//@post the m_hp value of the defending pokemon might be changed
		//@return true if defenders m_hp value is reduced to zero, else false
		bool attack(Pokemon& attacker, Pokemon& defender);

		//@pre pokemon and colosseum instances
		//@post a game of pokemon is emulated using the attack method multiple times
		//@return none
		void play(Pokemon& p1, Pokemon& p2);
	private:
		//the dice are used to create random numbers within attack() and play()
		Dice d20;
		Dice d6;
};
#endif
