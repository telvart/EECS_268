/**     @name: Cow.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.7.15
*	@brief: Implementation of methods declared in Cow.h
*/ 

#include "Cow.h"

Cow::Cow()
{
	m_name="Cow";
	m_sound="Moo";
}

double Cow::getMilkProduced() const
{
	return m_milkProduced;
}

void Cow::setMilkProduced(double gallons)
{
	m_milkProduced=gallons;
}
