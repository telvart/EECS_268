/**     @name:
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:
*	@brief:
*/ 

#include "FarmAnimal.h"

FarmAnimal::FarmAnimal()
{
	m_name="unset";
	m_sound="unset";
}



std::string FarmAnimal::getName() const
{
	return m_name;
}


std::string FarmAnimal::getSound() const
{
	return m_sound;
}


void FarmAnimal::setName(std::string name)
{
	m_name=name;
}


void FarmAnimal::setSound(std::string sound)
{
	m_sound=sound;
}
