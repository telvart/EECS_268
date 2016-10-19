/**     @name:
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:
*	@brief:
*/ 

#include "Chicken.h"

Chicken::Chicken()
{
	m_name="Chicken";
	m_sound="Cluck";
}


int Chicken::getEggs() const
{
	return m_eggs;
}


void Chicken::setEggs(int Eggs)
{
	m_eggs=Eggs;
}
