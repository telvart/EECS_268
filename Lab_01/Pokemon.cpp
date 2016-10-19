/**
*	@file: Pokemon.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.2
*	Purpose: implementation of methods for the pokemon class
*/

#include "Pokemon.h"

Pokemon::Pokemon()
{
	m_hp=0;
	m_attackLevel=0;
	m_defenseLevel=0;
	m_name="";
}

void Pokemon::reduceHP(int amount)
{
	if (amount>= m_hp)
	{
		m_hp=0;
	}
	else
	{
		m_hp=m_hp-amount;
	}
}

void Pokemon::setHP(int newhp)
{
	m_hp=newhp;
}

void Pokemon::setAttackLevel(int newattacklevel)
{
	m_attackLevel=newattacklevel;
}

void Pokemon::setDefenseLevel(int newdefenselevel)
{
	m_defenseLevel=newdefenselevel;
}

void Pokemon::setName(std::string newname)
{
	m_name=newname;
}

const int Pokemon::getHP()
{
	return m_hp;
}

const int Pokemon::getAttackLevel()
{
	return m_attackLevel;
}

const int Pokemon::getDefenseLevel()
{
	return m_defenseLevel;
}

const std::string Pokemon::getName()
{
	return m_name;
}
