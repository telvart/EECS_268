/**
*	@file: Pokemon.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.2
*	Purpose: representation of a pokemon with different variables that change depending on the game
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
class Pokemon
{
    public:
  


	//@pre:none
	//@post: Creates an initialized pokemon instance
	//@return nothing
        Pokemon();

	//@pre pokemon instance exist
	//@post reduces the instances m_HP value
	//@return none. it is a void
        void reduceHP(int amount);

	//@pre pokemon instance exists
	//@post changes the pokemons m_hp value
	//@return none
        void setHP(int newhp);

	//@pre pokemon instance exists
	//@post pokemons m_attackLevel is changed
	//@return none
        void setAttackLevel(int newattacklevel);

	//@pre pokemon isntance exists
	//@post pokemons m_defenseLevel is changed
	//@return none
        void setDefenseLevel(int newdefenselevel);

	//@pre pokemon instance exists
	//@post pokemons m_name is changed
	//@return none
        void setName(std::string newname);

	//@pre pokemon instance exists
	//@post none
	//@return the pokemons current m_HP value
        const int getHP();

	//@pre pokemon instance exists
	//@post none
	//@return the pokemons current m_attackLevel
        const int getAttackLevel();

	//@pre pokemon instance exists
	//@post none
	//@return the pokemons current m_defenseLevel
        const int getDefenseLevel();

	//@pre pokemon instance exists
	//@post none
	//@return the pokemons current m_Name
        const std::string getName();
        
    private:
        
        int m_hp;
        int m_attackLevel;
        int m_defenseLevel;
        std::string m_name;
};
#endif
